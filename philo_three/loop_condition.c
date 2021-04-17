/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:26:59 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 19:34:22 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	loop_condition(t_fork_philo *obj)
{
	return ((obj->misc_data->dead_philo->__size[0] != 0
			&& obj->swallow != obj->misc_data
			->num_of_time_philo_must_eat));
}
