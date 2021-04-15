/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:11:50 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 22:11:51 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	main(int argc, char *argv[])
{
	t_sema_philo	prot;
	t_philo_hands	*heretic;

	if (argc < 5 || argc > 6)
	{
		printf("bash: philo_two: wrong number of arguments");
		return (1);
	}
	sema_philo_data_init(&prot, argc, argv);
	sem_unlink("forks");
	prot.forks = sem_open("forks", O_CREAT, 0644, prot.philo_num);
	sem_unlink("waiter");
	prot.waiter = sem_open("waiter", O_CREAT, 0644, prot.waiter_busy);
	heretic = philo_hands_init(&prot);
	if (prot.num_of_time_philo_must_eat == -1)
		philo_choose_case(philo_seikatsu, heretic);
	else
		philo_choose_case(philo_ranchi, heretic);
	check_pidt_case_state(&prot, heretic);
	sem_close(prot.forks);
	sem_close(prot.waiter);
	memfree_alloc((void **)&heretic);
	return (0);
}
