/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:56:13 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/12 21:47:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int 			philo_is_eating(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%ld %d is eating\n", old_time, crnl->num + 1);
	crnl->philo_hp = crnl->misc_data->time_to_die - diff_time * 1000;
	if (crnl->philo_hp <= 0)
	{
		printf("%ld %d died\n", old_time, crnl->num + 1);
		//return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				philo_is_sleeping(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%ld %d is sleeping\n", old_time, crnl->num + 1);
	crnl->philo_hp -= diff_time * 1000;
	if (crnl->philo_hp <= 0)
	{
		printf("%ld %d died\n", old_time, crnl->num + 1);
		//return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				philo_is_thinking(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%ld %d is thinking\n", old_time, crnl->num + 1);
	crnl->philo_hp -= diff_time * 1000;
	if (crnl->philo_hp <= 0)
	{
		printf("%ld %d died\n", old_time, crnl->num + 1);
		//return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				philo_takes_fork(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%ld %d has taken a fork\n", old_time, crnl->num + 1);
	crnl->philo_hp -= diff_time * 1000;
	if (crnl->philo_hp <= 0)
	{
		printf("%ld %d died\n", old_time, crnl->num + 1);
		//return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				calculate_time(t_fork_philo *data, 
				int (*func)(t_fork_philo *, long, long), long time)
{
	long	diff_time;
	long 	old_time;

	old_time = data->time_travel;
	usleep(time);
	gettimeofday(&data->misc_data->cur_time, NULL);
	diff_time = data->misc_data->cur_time.tv_sec * 1000 +
	data->misc_data->cur_time.tv_usec / 1000 - data->old_time ;
	data->time_travel += diff_time;
	return (func(data, diff_time, old_time));
}

void			*check_philo_table(void *data)
{
	t_fork_philo	*checker;

	checker = (t_fork_philo *)data;
	while (1)
	{
		if (checker->philo_hp <= 0 || checker->swallow ==
		checker->misc_data->num_of_time_philo_must_eat)
		{	
			/*checker->misc_data->dead_philo +=
			(checker->philo_hp <= 0);
			checker->satiate_philo += (checker->swallow ==
			checker->misc_data->num_of_time_philo_must_eat);*/
			if (checker->philo_hp <= 0)
			{
				++checker->philo_died;
				sem_post(checker->misc_data->dead_philo);
			}
			if (checker->swallow == checker->misc_data->num_of_time_philo_must_eat)
			{
				++checker->satiate_philo;
				sem_post(checker->misc_data->swallow);
			}			
			return (NULL);
		}
	}
	return (NULL);
}

void			philo_takes_forks(t_fork_philo *philo)
{
	if (philo->left_hand == PHILO_PUT_FORK)
	{
		sem_wait(philo->misc_data->waiter);
		sem_wait(philo->misc_data->chopstick);
		calculate_time(philo, philo_takes_fork, 0);
		philo->left_hand = PHILO_TAKE_FORK;
		sem_post(philo->misc_data->waiter);
	}
	if (philo->right_hand == PHILO_PUT_FORK)
	{
		sem_wait(philo->misc_data->chopstick);
		calculate_time(philo, philo_takes_fork, 0);
		philo->right_hand = PHILO_TAKE_FORK;	
	}	
}

void			philo_put_forks(t_fork_philo *philo)
{
	sem_post(philo->misc_data->chopstick);
	philo->right_hand = PHILO_PUT_FORK;
	sem_post(philo->misc_data->chopstick);
	philo->left_hand = PHILO_PUT_FORK;
	calculate_time(philo, philo_is_sleeping, philo->
	misc_data->time_to_sleep);
	calculate_time(philo, philo_is_thinking, 0);
}

int				philo_lifetime(void *proc)
{
	pthread_t		watcher;
	t_fork_philo	*data;
	int				if_err;

	if_err = pthread_create(&watcher, NULL, check_philo_table, proc);
	if (if_err)
	{
		printf("philo_three: error: can't create a new thread\n");
		return (EXIT_FAILURE);
	}
	pthread_detach(watcher);
	data = (t_fork_philo *)proc;
	while (!data->philo_died && !data->satiate_philo)
	{
		philo_takes_forks(data);
		calculate_time(data, philo_is_eating,
		data->misc_data->time_to_eat);
		philo_put_forks(data);
	}
	//exit (0);
	return (EXIT_SUCCESS);
}

int				dinner_is_over(t_fork_philo *data, int i)
{
	if (data->misc_data->num_of_time_philo_must_eat == -1)
		return (0);
	else if (data[i].swallow !=
	data->misc_data->num_of_time_philo_must_eat)
		return (0);
	else if (i < data->misc_data->philo_num)
		return (dinner_is_over(data, ++i));
	return (1);
}

int             main(int argc, char *argv[])
{
	t_fork_philo	*philo_proc;
	t_misc			misc_data;
	int				i;

	philo_proc = NULL;
    if (argc < 5 || argc > 6)
    {
        printf("Error: wrong number of arguments\n");
        return (1);
    }
	misc_init_data(&misc_data, argc, argv);
	philo_proc = fork_philo_init_data(&misc_data);
	if (!philo_proc)
	{
		printf("philo_three: error: can't allocate memory\n");
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < misc_data.philo_num)
	{
		philo_proc[i].philo_pid = fork();
		if (philo_proc[i].philo_pid == -1)
		{
			printf("philo_three: can't create child process\n");
			exit(EXIT_FAILURE);
		}
		else if (!philo_proc[i].philo_pid)
		{
			philo_lifetime(&philo_proc[i]);
			exit (0);
		}
	}
	if (misc_data.num_of_time_philo_must_eat != -1)
		misc_data.sem_philo_dish += (!sem_wait(misc_data.swallow));
	while (!sem_wait(misc_data.dead_philo) &&
	misc_data.sem_philo_dish != misc_data.num_of_time_philo_must_eat)
		waitpid(-1, &misc_data.status, 0);
	i = -1;
	while (++i < misc_data.philo_num)
		kill(philo_proc[i].philo_pid, SIGKILL);
	sem_close(misc_data.chopstick);
	sem_close(misc_data.waiter);
    return (0);
}