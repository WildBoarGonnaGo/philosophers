/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:56:13 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/12 21:47:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int             main(int argc, char *argv[])
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
	if (!philo_proc)
	{
		printf("philo_three: error: can't allocate memory\n");
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < misc_data.philo_num)
	{
		philo_proc[i].philo_pid = fork();
		if (philo_proc[i].philo_pid == -1)
		{
			printf("philo_three: can't create child process\n");
			return (EXIT_FAILURE);
		}
		else if (!philo_proc[i].philo_pid)
		{
			philo_lifetime(&philo_proc[i]);
			exit (0);
		}
	}
	while (misc_data.dead_philo->__size[0] &&
	misc_data.swallow->__size[0] > 0)
		waitpid(-1, &misc_data.status, 0);
	i = -1;
	while (++i < misc_data.philo_num)
		kill(philo_proc[i].philo_pid, SIGKILL);
	sem_close(misc_data.chopstick);
	sem_close(misc_data.waiter);
	sem_close(misc_data.swallow);
	sem_close(misc_data.msg);
	sem_close(misc_data.dead_philo);
	memfree_alloc((void **)&philo_proc);
    return (0);
}