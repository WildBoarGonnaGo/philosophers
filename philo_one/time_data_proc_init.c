/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_data_proc_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:46:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 18:12:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	time_data_proc_init(t_time *time_input, int argc, char *argv[])
{
	time_input->num_of_philo = wb_atoi(argv[1], 0, ZERO | SPACE | PLUSMINUS);
	time_input->time_to_die = wb_atoi(argv[2], 0, ZERO | SPACE | PLUSMINUS)
		* 1000;
	time_input->time_to_eat = wb_atoi(argv[3], 0, ZERO | SPACE | PLUSMINUS)
		* 1000;
	time_input->time_to_sleep = wb_atoi(argv[4], 0, ZERO | SPACE | PLUSMINUS)
		* 1000;
	if (argc != 6)
		time_input->number_of_time_philo_eats = -1;
	else
		time_input->number_of_time_philo_eats
			= wb_atoi(argv[5], 0, ZERO | SPACE | PLUSMINUS);
	pthread_mutex_init(&time_input->msg, NULL);
}
