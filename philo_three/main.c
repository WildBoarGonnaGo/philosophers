/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:56:13 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 20:58:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	sem_finish(t_misc *misc_data)
{
	sem_close(misc_data->chopstick);
	sem_close(misc_data->waiter);
	sem_close(misc_data->swallow);
	sem_close(misc_data->msg);
	sem_close(misc_data->dead_philo);
}

int	main(int argc, char *argv[])
{
	t_fork_philo	*philo_proc;
	t_misc			misc_data;
	int				i;

	philo_proc = NULL;
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	misc_init_data(&misc_data, argc, argv);
	philo_proc = fork_philo_init_data(&misc_data);
	fork_proc(&misc_data, philo_proc);
	while (misc_data.dead_philo->__size[0]
		&& misc_data.swallow->__size[0] > 0)
		waitpid(-1, &misc_data.status, 0);
	i = -1;
	while (++i < misc_data.philo_num)
		kill(philo_proc[i].philo_pid, SIGKILL);
	sem_finish(&misc_data);
	memfree_alloc((void **)&philo_proc);
	return (0);
}
