/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:46:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/24 00:13:11 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int argc, char *argv[])
{
	t_philo_one	*snakebites;

	if (argc < 3 || argc > 4)
		return (1);
	snakebites = (t_philo_one *)malloc(sizeof(t_philo_one));
	memset(snakebites, 0, sizeof(t_philo_one));
	if (argc != 4)
		snakebites->num_times_philo_eat = -1;
	
}
