/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:58:15 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/11 21:29:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	misc_init_data(t_misc *data, int argc, char *argv[])
{
    data->error = 0;
    data->philo_num = wb_atoi(argv[1], 0, ZERO | PLUSMINUS | SPACE);
    data->time_to_die = wb_atoi(argv[2], 0, ZERO | PLUSMINUS | SPACE);
    data->time_to_eat = wb_atoi(argv[3], 0, ZERO | PLUSMINUS | SPACE);
    data->time_to_sleep = wb_atoi(argv[4], 0, ZERO | PLUSMINUS | SPACE);
    data->num_of_time_philo_must_eat = (argc != 6) ? -1 :
    wb_atoi(argv[5], 0, ZERO | PLUSMINUS | SPACE);
	sem_unlink("/output");
	data->output = sem_open("/output", O_CREAT, 0644, 1);
	if (data->output == SEM_FAILED)
		return (EXIT_FAILURE);
	sem_unlink("/dead_philo");
	data->dead_philo = sem_open("/dead_philo", O_CREAT, 0644, 1);
	if (data->dead_philo == SEM_FAILED)
		return (EXIT_FAILURE);
	sem_unlink("/chopstick");
	data->chopstick = sem_open("/chopstick", O_CREAT, 0644, data->philo_num);
	if (data->chopstick == SEM_FAILED)
		return (EXIT_FAILURE);
	sem_unlink("/swallow");
	data->swallow = sem_open("/swallow", O_CREAT, 0644, data->philo_num);
	if (data->swallow == SEM_FAILED)
		return (EXIT_FAILURE);
}