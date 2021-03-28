/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:46:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/28 13:16:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <errno.h>
/*
 
 * */

/*
While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping.

int usleep(useconds_t usec)


*/

#define	EPHILDEAD -10

void			alloc_free(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

void			philo_is_eating(t_philo_one *obj)
{
	printf("[%ld ms] philosopher %d is eating\n",
	obj->time_travel[obj->indx[0]], obj->indx[0] + 1);
	obj->starvation[obj->indx[0]] = obj->time_to_die -
	obj->time_to_eat;
}

void			philo_is_sleeping(t_philo_one *obj)
{
	
	printf("[%ld ms] philosopher %d is sleeping\n",
	obj->time_travel[obj->indx[0]], obj->indx[0] + 1);
	obj->starvation[obj->indx[0]] -= obj->time_to_sleep;
	printf("[%ld ms] philosopher %d is thinking\n",
	obj->time_travel[obj->indx[0]], obj->indx[0] + 1);
}

/*void			philo_is_sleeping(t_philo_one *obj)
{
	printf("[%ld ms] philosopher %d is sleeping\n",
	obj->time_travel[obj->indx[0]], obj->indx[0]);
	obj->starvation[obj->indx[0]] -= obj->time_to_sleep;
}*/

void			starve_proc(t_philo_one *obj)
{
	int	i;

	i = -1;
	if (obj->starvation[obj->indx[0]] < 0)
	{
		printf("[%ld ms] philosopher %d died\n",
		obj->time_travel[obj->indx[0]], obj->indx[0]);
		while (++i < 4)
			obj->error[i] = EPHILDEAD;	
	}
}

long			wb_micro_to_mille(useconds_t var)
{
	long		check;

	check = (var / 100) - (var / 1000) * 10;
	return (check > 5) ? (var / 1000 + 1) : (var / 1000);
}

void			calculate_time(t_philo_one *obj,
				useconds_t sleep, void (*starve)(t_philo_one *))
{
	gettimeofday(&obj->time_val, NULL);
	usleep(sleep);
	if (obj->old_time[obj->indx[0]] > wb_micro_to_mille(obj->time_val.tv_usec) +
	obj->prefix[obj->indx[0]])
		obj->prefix[obj->indx[0]] += 1000;
	obj->time_travel[obj->indx[0]] += wb_micro_to_mille(obj->time_val.tv_usec) +
	obj->prefix[obj->indx[0]] - obj->old_time[obj->indx[0]];
	obj->old_time[obj->indx[0]] = wb_micro_to_mille(obj->time_val.tv_usec) +
	obj->prefix[obj->indx[0]];
	starve(obj);
}	

void			*philo_routines(void *arg)
{
	t_philo_one	*obj;
	
	obj = (t_philo_one *)arg;
	obj->error[2] = 0;
	obj->error[3] = 0;
	obj->error[2] = pthread_mutex_lock(&obj->chopstick[obj->indx[0] %
	obj->num_of_philo]);
	if (!obj->error[2] && obj->error[2] != EDEADLK)
		printf("[%ld ms] philosopher %d has taken a fork\n", 
		obj->time_travel[obj->indx[0]], obj->indx[0] + 1);
	else
		return (NULL);
	obj->error[3] = pthread_mutex_lock(&obj->chopstick[(obj->indx[0] + 1) %
	obj->num_of_philo]);
	if (!obj->error[3] && obj->error[3] != EDEADLK)
		printf("[%ld ms] philosopher %d has taken a fork\n",
		obj->time_travel[obj->indx[0]], obj->indx[0] + 1);
	else
		return (NULL);
	pthread_mutex_unlock(&obj->chopstick[obj->indx[0] % obj->num_of_philo]);
	pthread_mutex_unlock(&obj->chopstick[(obj->indx[0] + 1) % obj->num_of_philo]);
	calculate_time(obj, obj->time_to_eat * 1000, philo_is_eating);
	calculate_time(obj, obj->time_to_sleep * 1000, philo_is_sleeping);
	//pthread_mutex_unlock(&
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo_one	*snakebites;
	int			indx[2];

	if (argc < 5 || argc > 6)
		return (1);
	snakebites = (t_philo_one *)malloc(sizeof(t_philo_one));
	memset(snakebites, 0, sizeof(t_philo_one));
	if (argc != 6)
		snakebites->num_times_philo_eat = -1;
	else
		snakebites->num_times_philo_eat = wb_atoi(argv[6], 0,
		ZERO | SPACE | PLUSMINUS);
	snakebites->num_of_philo = wb_atoi(argv[1], 0, ZERO | SPACE | PLUSMINUS);
	snakebites->num_fork = snakebites->num_of_philo;
	snakebites->time_to_die = wb_atoi(argv[2], 0,
	ZERO | SPACE | PLUSMINUS);
	snakebites->time_to_eat = wb_atoi(argv[3], 0,
	ZERO | SPACE | PLUSMINUS);
	snakebites->time_to_eat = wb_atoi(argv[4], 0,
	ZERO | SPACE | PLUSMINUS);
	snakebites->chopstick = (pthread_mutex_t *)
	malloc(sizeof(pthread_mutex_t) * snakebites->num_of_philo);
	snakebites->starvation = (int *)malloc(sizeof(int) *
	snakebites->num_of_philo);
	snakebites->time_travel = (long *)malloc(sizeof(long) *
	snakebites->num_of_philo);
	snakebites->old_time = (long *)malloc(sizeof(long) * 
	snakebites->num_of_philo);
	snakebites->prefix = (long *)malloc(sizeof(long) *
	snakebites->num_of_philo);
	snakebites->philo = (pthread_t *)malloc(sizeof(pthread_t) * 
	snakebites->num_of_philo);
	snakebites->indx[0] = -1;
	gettimeofday(&snakebites->time_val, NULL);
	//snakebites->old_time = wb_micro_to_mille(snakebites->time_val.tv_usec);
	while (++snakebites->indx[0] < snakebites->num_of_philo)
	{
		snakebites->starvation[snakebites->indx[0]] = 
		snakebites->time_travel[indx[0]] = 0;
		snakebites->old_time[indx[0]] = 0;
		snakebites->prefix[indx[0]] = 0;
		/*Creating mutex lock objects*/
		snakebites->old_time[snakebites->indx[0]] = wb_micro_to_mille(snakebites->time_val.tv_usec);
		pthread_mutex_init(&snakebites->chopstick[indx[0]], NULL);
	}
	snakebites->indx[0] = -1;
	while (++snakebites->indx[0] < 4)
		snakebites->error[snakebites->indx[0]] = 0;
	//while (++snakebites->indx[0] < snakebites->num_of_philo)
	//pthread_mutex_init(&snakebites->chopstick[indx[0]], NULL);
	/*What actually philosopher do: Think for a while, Pick up chopsticks,
	Eat for while, Put down chopsticks*/
	//snakebites->time_travel = 0;
	//snakebites->old_time = 0;
	//snakebites->prefix = 0;
	if (snakebites->num_times_philo_eat == -1)
	{
		while (1)
		{
			snakebites->indx[0] = -1;
			while (++snakebites->indx[0] < snakebites->num_of_philo)
			{
				snakebites->error[0] = pthread_create(&snakebites->philo[snakebites->indx[0]],
				NULL, philo_routines, (void *)snakebites);
				snakebites->error[4] = snakebites->error[0] || snakebites->error[2] || snakebites->error[3];
				if (snakebites->error[4])
				{
					printf("philo_one: thread can't be created: %s\n", strerror(errno));
					break ;
				}
				snakebites->error[1] = pthread_join(snakebites->philo[snakebites->indx[0]], NULL);
				if (snakebites->error[1])
				{
					printf("philo_one: thread can't be joined: %s\n", strerror(errno));
					break;
				}
			}
			if (snakebites->error[4] || snakebites->error[1])
					break ;
			/*if (snakebites->error[4])
				break ;
			snakebites->indx[0] = -1;
			while (++snakebites->indx[0] < snakebites->num_times_philo_eat)
			{
				snakebites->error[1] = pthread_join(snakebites->philo[snakebites->indx[0]], NULL);
				if (snakebites->error[1])
				{
					printf("philo_one: thread can't be joined: %s\n", strerror(errno));
					break;
				}
			}
			if (snakebites->error[1])
				break ; */
		}
	}
	snakebites->indx[0] = -1;
	while (++snakebites->indx[0] < snakebites->num_of_philo)
		pthread_mutex_destroy(&snakebites->chopstick[snakebites->indx[0]]);
	/*
	snakebites->chopstick = (pthread_mutex_t *)
	malloc(sizeof(pthread_mutex_t) * snakebites->num_of_philo);
	snakebites->starvation = (int *)malloc(sizeof(int) *
	snakebites->num_of_philo);
	snakebites->time_travel = (long *)malloc(sizeof(long) *
	snakebites->num_of_philo);
	snakebites->old_time = (long *)malloc(sizeof(long) * 
	snakebites->num_of_philo);
	snakebites->prefix = (long *)malloc(sizeof(long) *
	snakebites->num_of_philo);
	snakebites->philo = (pthread_t *)malloc(sizeof(pthread_t) * 
	snakebites->num_of_philo);
	snakebites->indx[0] = -1;
	 * */
	alloc_free((void **)&snakebites->chopstick);
	alloc_free((void **)&snakebites->time_travel);
	alloc_free((void **)&snakebites->old_time);
	alloc_free((void **)&snakebites->prefix);
	alloc_free((void **)&snakebites->philo);
	return (0);
}
