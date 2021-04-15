/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_choose_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:12:13 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:09:14 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	philo_choose_case(void *(*good_day)(void *),
			t_philo_hands *data)
{
	data->c_nerve->indx = -1;
	while (++data->c_nerve->indx < data->c_nerve->philo_num)
	{
		pthread_create(&data[data->c_nerve->indx].philo_tid,
			NULL, good_day, (void *)&data[data->c_nerve->indx]);
		if (data[data->c_nerve->indx].c_nerve->num_of_time_philo_must_eat == -1)
			pthread_detach(data[data->c_nerve->indx].philo_tid);
	}
}
