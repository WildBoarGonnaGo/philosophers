/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pidt_case_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:49:19 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:54:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	check_pidt_case_state(t_sema_philo *prot,
			t_philo_hands *heretic)
{
	if (prot->num_of_time_philo_must_eat != -1)
	{
		prot->indx = -1;
		while (++prot->indx < prot->philo_num)
			pthread_join(heretic[prot->indx].philo_tid, NULL);
	}
	else
	{
		while (1)
		{
			if (prot->error)
				break ;
		}
	}
}
