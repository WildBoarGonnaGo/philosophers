/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:07:40 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:22:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int argc, char *argv[])
{
	t_philo_data		*philo_data_set;
	t_time				time_set;

	if (argc < 5 || argc > 6)
	{
		printf("philo_one: wrong number of arguments\n");
		return (1);
	}
	time_data_proc_init(&time_set, argc, argv);
	philo_data_set = num_of_philo_init(&time_set);
	time_set.i = -1;
	pthread_mutex_init(&time_set.take_forks, NULL);
	case_handle(&time_set, philo_data_set);
	check_if_dish_life(&time_set, philo_data_set);
	while (++time_set.i < time_set.num_of_philo)
		pthread_mutex_destroy(&philo_data_set[time_set.i].philo.simple_fork);
	pthread_mutex_destroy(&time_set.take_forks);
	memfree_alloc((void **)&philo_data_set);
	return (0);
}
