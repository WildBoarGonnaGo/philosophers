/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:56:13 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/11 22:05:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*int 			philo_seikatsu(t_fork_philo *proc)
{
	
	return (EXIT_SUCCESS);
}*/

int 			philo_is_eating(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%d %ld is eating\n", crnl->num, old_time);
	crnl->philo_hp = crnl->misc_data->time_to_die - diff_time;
	if (crnl->philo_hp <= 0)
	{
		printf("%d %ld died\n", crnl->num, old_time);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				philo_is_sleeping(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%d %ld is sleeping\n", crnl->num, old_time);
	crnl->philo_hp -= diff_time;
	if (crnl->philo_hp <= 0)
	{
		printf("%d %ld died\n", crnl->num, old_time);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				philo_is_thinking(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%d %ld has taken a fork\n", crnl->num, old_time);
	crnl->philo_hp -= diff_time;
	if (crnl->philo_hp <= 0)
	{
		printf("%d %ld died\n", crnl->num, old_time);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				philo_takes_fork(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	printf("%d %ld has taken a fork\n", crnl->num, old_time);
	crnl->philo_hp -= diff_time;
	if (crnl->philo_hp <= 0)
	{
		printf("%d %ld died\n", crnl->num, old_time);
		return (EXIT_FAILURE);
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
	data->misc_data->cur_time.tv_usec / 1000 - data->old_time;
	data->time_travel += diff_time;
	return (func(data, diff_time, old_time));
}

void			philo_proc(t_fork_philo *proc)
{
	
}

int             main(int argc, char *argv[])
{
	t_fork_philo	*philo_proc;
	t_misc			misc_data;
	int				i;

    if (argc < 5 && argc > 6)
    {
        printf("Error: wrong number of arguments\n");
        return (1);
    }
	misc_init_data(&misc_data, argc, argv);
	fork_philo_init_data(philo_proc, &misc_data);
	while (++i < misc_data.philo_num)
	{
		misc_data.philo_pid[i] = fork();
		if (misc_data.philo_pid[i] == -1)
		{
			printf("philo_three: cannot open fork process\n");
			exit(EXIT_FAILURE);
		}
		else if (!misc_data.philo_pid[i])
		{
			
		}
	}
	while (misc_data.dead_philo->__size && misc_data.swallow->__size > 0)
		;
    return (0);
}