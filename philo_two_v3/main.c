#include "philo_one.h"

void					set_ref_fork(t_philo_data *ref_philo, t_time
						*time_set, int indx)
{
	if (time_set->num_of_philo == 2)
	{
		ref_philo[indx].philo.left_fork = &ref_philo[indx %
		time_set->num_of_philo].philo.simple_fork;
		ref_philo[indx].philo.right_fork = &ref_philo[(indx + 1) %
		time_set->num_of_philo].philo.simple_fork;
	}
	else
	{
		ref_philo[indx].philo.left_fork = &ref_philo[(indx + 1) % 
		(time_set->num_of_philo)].philo.simple_fork;
		ref_philo[indx].philo.right_fork = 
		&ref_philo[(indx + time_set->num_of_philo - 1) % 
		(time_set->num_of_philo)].philo.simple_fork;
	}
}

t_philo_data			*num_of_philo_init(t_time *time_set)
{
	t_philo_data	*data;
	int				i;
	struct timeval	temp;

	data = (t_philo_data *)malloc(sizeof(t_philo_data)
	* time_set->num_of_philo);
	if (!data)
		return (NULL);
	time_set->error = 0;
	i = -1;
	while (++i < time_set->num_of_philo)
	{
		memset((void *)&data[i], 0, sizeof(t_philo_data) - 1);
		data[i].misc = time_set;
		data[i].philo.num = i;
		set_ref_fork(data, time_set, i);
		data[i].philo.time_travel = 0;
		gettimeofday(&temp, NULL);
		data[i].philo.old_time = temp.tv_sec * 1000 +
		temp.tv_usec / 1000;
		data[i].philo.philo_hp = time_set->time_to_die; 
	}
	i = -1;
	while (++i < time_set->num_of_philo)
		pthread_mutex_init(&data[i].philo.simple_fork, NULL);
	return (data);
}

int						check_if_philo_satiety(int i, t_philo_data *data)
{
	if (data[i].misc->number_of_time_philo_eats == -1)
		return (0);
	else if (data[i].philo.ranchi_indx !=
	data[i].misc->number_of_time_philo_eats)
		return (0);
	else if (i < data[i].misc->num_of_philo)
		check_if_philo_satiety(++i, data);
	return (1);
}					

int						main(int argc, char *argv[])
{
	t_philo_data		*philo_data_set;
	t_time				time_set;

	if (argc < 5 || argc > 6)
	{
		printf("philo_one: wrong number of arguments\n");
		return (1);
	}
	time_data_proc_init(&time_set, argc, argv);
	philo_data_set = num_of_philo_init(&time_set);
	time_set.i = -1;
	pthread_mutex_init(&time_set.take_forks, NULL);
	if (time_set.number_of_time_philo_eats == -1)
	{
		while (++time_set.i < time_set.num_of_philo)
		{
			pthread_create(&philo_data_set[time_set.i].philo.philo_tid, NULL,
			philo_seikatsu, (void *)&philo_data_set[time_set.i]);
			pthread_detach(philo_data_set[time_set.i].philo.philo_tid);
		}
	}
	else
	{
		while (++time_set.i < time_set.num_of_philo)
		{
			philo_data_set[time_set.i].philo.ranchi_indx = 0;
			pthread_create(&philo_data_set[time_set.i].philo.philo_tid, NULL,
			philo_ranchi, (void *)&philo_data_set[time_set.i]);
		}
	}
	if (time_set.number_of_time_philo_eats != -1)
	{
		time_set.i = -1;
		while (++time_set.i < time_set.num_of_philo)
			pthread_join(philo_data_set[time_set.i].philo.philo_tid, NULL);
	}
	else
	{
		while (1)
		{
			if (time_set.error)
				break ;
		}
	}
	while (++time_set.i < time_set.num_of_philo)
		pthread_mutex_destroy(&philo_data_set[time_set.i].philo.simple_fork);
	pthread_mutex_destroy(&time_set.take_forks);
	memfree_alloc((void **)&philo_data_set);
	return (0);
}