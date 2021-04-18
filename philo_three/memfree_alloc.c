/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:25:58 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/18 09:06:55 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	memfree_alloc(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = NULL;
	}
}
