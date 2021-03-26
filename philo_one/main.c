/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:46:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/26 05:31:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*typedef	struct			s_philo_one
{
	uint16			num_of_philo;
	uint16			time_to_die;
	uint16			time_to_eat;
	uint16			num_times_philo_eat;
	struct timeval	time_info;
	uint16			num_fork;
	pthread_t		*plan;
	pthread_mutex_t	*chopstick;
	int				error[2];
}						t_philo_one;*/

int						wb_atoi(char *str, int res, int flags);


int	main(int argc, char *argv[])
{
	t_philo_one	*snakebites;
	int			indx[2];

	if (argc < 3 || argc > 4)
		return (1);
	snakebites = (t_philo_one *)malloc(sizeof(t_philo_one));
	memset(snakebites, 0, sizeof(t_philo_one));
	if (argc != 4)
		snakebites->num_times_philo_eat = -1;
	else
		snakebites->num_times_philo_eat = wb_atoi(argv[3], 0,
		ZERO | SPACE | PLUSMINUS);
	snakebites->num_of_philo = wb_atoi(argv[0], 0, ZERO | SPACE | PLUSMINUS);
	snakebites->num_fork = snakebites->num_of_philo;
	snakebites->time_to_die = wb_atoi(argv[1], 0,
	ZERO | SPACE | PLUSMINUS);
	snakebites->time_to_eat = wb_atoi(argv[2], 0,
	ZERO | SPACE | PLUSMINUS);
	snakebites->time_to_eat = wb_atoi(argv[3], 0,
	ZERO | SPACE | PLUSMINUS);
	snakebites->chopstick = (pthread_mutex_t *)
	malloc(sizeof(pthread_mutex_t) * snakebites->num_of_philo);
	snakebites->
	/*Creating mutex lock objects*/
	indx[0] = -1;
	while (++snakebites->indx[0] < snakebites->num_of_philo)
		pthread_mutex_init(snakebites->chopstick[indx[0]], NULL);
	/*What actually philosopher do: Think for a while, Pick up chopsticks,
	Eat for while, Put down chopsticks*/
	snakebites->indx[0] = -1;
			
	if (snakebites->num_times_philo_eat == -1)
	{
		while (1)
		{
			snakebites->indx[0] = -1;
			while (++snakebites->indx[0] < snakebites->num_of_philo)
			{
				snakebites->error[0] = pthread_create
			}
		}
	}
}
