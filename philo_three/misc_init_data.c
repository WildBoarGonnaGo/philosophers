/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:58:15 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/18 09:06:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	grep_cli_data(t_misc *data, int argc, char *argv[])
{
	data->error = 0;
	data->philo_num = wb_atoi(argv[1], 0, ZERO | PLUSMINUS | SPACE);
	data->time_to_die = wb_atoi(argv[2], 0, ZERO | PLUSMINUS | SPACE)
		* 1000;
	data->time_to_eat = wb_atoi(argv[3], 0, ZERO | PLUSMINUS | SPACE)
		* 1000;
	data->time_to_sleep = wb_atoi(argv[4], 0, ZERO | PLUSMINUS | SPACE)
		* 1000;
	if (argc != 6)
		data->num_of_time_philo_must_eat = -1;
	else
		data->num_of_time_philo_must_eat
			= wb_atoi(argv[5], 0, ZERO | PLUSMINUS | SPACE);
}

void	misc_init_data(t_misc *data, int argc, char *argv[])
{
	grep_cli_data(data, argc, argv);
	sem_unlink("/waiter");
	data->waiter = sem_open("/waiter", O_CREAT, 0644, 1);
	sem_unlink("/dead_philo");
	data->dead_philo = sem_open("/dead_philo", O_CREAT, 0644, 1);
	sem_unlink("/chopstick");
	data->chopstick = sem_open("/chopstick", O_CREAT, 0644, data->philo_num);
	sem_unlink("/swallow");
	if (data->num_of_time_philo_must_eat == -1)
		data->swallow = sem_open("/swallow", O_CREAT, 0644, 1);
	else
		data->swallow = sem_open("/swallow", O_CREAT, 0644, data->philo_num);
	sem_unlink("/msg");
	data->msg = sem_open("/msg", O_CREAT, 0644, 1);
	data->is_dead = 1;
}
