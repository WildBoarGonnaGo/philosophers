/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_philo_satiety.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:11:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 22:11:44 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	check_if_philo_satiety(int i, t_philo_hands *data)
{
	if (data[i].c_nerve->num_of_time_philo_must_eat == -1)
		return (0);
	else if (data[i].stty_indx
		!= data[i].c_nerve->num_of_time_philo_must_eat)
		return (0);
	else if (i < data[i].c_nerve->philo_num)
		check_if_philo_satiety(++i, data);
	return (1);
}
