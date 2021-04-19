/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:11:50 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/19 22:31:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	sem_create(t_sema_philo *addr)
{
	sem_unlink("forks");
	addr->forks = sem_open("forks", O_CREAT, 0644, addr->philo_num);
	sem_unlink("waiter");
	addr->waiter = sem_open("waiter", O_CREAT, 0644, addr->waiter_busy);
	sem_unlink("msg");
	addr->msg = sem_open("msg", O_CREAT, 0644, 1);
	sem_unlink("death");
	addr->death = sem_open("death", O_CREAT, 0644, 1);
}

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
	sem_create(&prot);
	heretic = philo_hands_init(&prot);
	if (prot.num_of_time_philo_must_eat == -1)
		philo_choose_case(philo_seikatsu, heretic);
	else
		philo_choose_case(philo_ranchi, heretic);
	check_pidt_case_state(&prot, heretic);
	sem_close(prot.forks);
	sem_close(prot.waiter);
	sem_close(prot.msg);
	sem_close(prot.death);
	memfree_alloc((void **)&heretic);
	return (0);
}
