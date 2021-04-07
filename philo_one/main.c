#include "philo_one.h"

t_philo_data			*num_of_philo_init(t_time *time_set, t_forks *forks_set)
{
	t_philo_data	*data;
	int				i;

	if (time_set->num_of_philo <= 0)
		return (0x0);
	data = (t_philo_data *)malloc(sizeof(t_philo_data) * time_set->num_of_philo);
	time_set->error = 0;
	i = -1;
	while (++i < time_set->num_of_philo)
	{
		memset((void *)&data[i], 0, sizeof(t_philo_data) - 1);
		data[i].philo = (t_philo *)malloc(sizeof(t_philo));
		data[i].forks = (t_forks *)malloc(sizeof(t_forks));
		//data[i].forks = (t_forks *)malloc(sizeof(t_forks));
		philo_data_init(data[i].philo, i, i % time_set->num_of_philo,
		(i + 1) % time_set->num_of_philo);
		data[i].philo->philo_hp = (long)time_set->time_to_die; 
		data[i].forks = forks_set;
		data[i].misc = time_set;
	}
	return (data);
}

int						check_if_philo_satiety(int i, t_philo_data *data)
{
	if (data[i].misc->number_of_time_philo_eats == -1)
		return (0);
	else if (data[i].philo->ranchi_indx !=
	data[i].misc->number_of_time_philo_eats)
		return (0);
	else if (i < data[i].misc->num_of_philo)
		check_if_philo_satiety(++i, data);
	return (1);
}					

int						main(int argc, char *argv[])
{
	t_philo_data		*philo_data_set;
	pthread_t			*thread_id;
	t_forks				forks_set;
	t_time				time_set;

	if (argc < 5 || argc > 6)
	{
		printf("philo_one: wrong number of arguments\n");
		return (1);
	}
	time_data_proc_init(&time_set, argc, argv);
	forks_set.forks = (pthread_mutex_t *)malloc
	(sizeof(pthread_mutex_t) * time_set.num_of_philo);
	forks_data_init(&forks_set, time_set);
	thread_id = (pthread_t *)malloc(sizeof(pthread_t) * time_set.num_of_philo);
	philo_data_set = num_of_philo_init(&time_set, &forks_set);
	time_set.i = -1;
	pthread_mutex_init(&time_set.take_forks, NULL);
	if (time_set.number_of_time_philo_eats == -1)
	{
		while (++time_set.i < time_set.num_of_philo)
		{
			pthread_create(&thread_id[time_set.i], NULL,
			philo_seikatsu, (void *)&philo_data_set[time_set.i]);
			pthread_detach(thread_id[time_set.i]);
		}
	}
	else
	{
		while (++time_set.i < time_set.num_of_philo)
		{
			philo_data_set[time_set.i].philo->ranchi_indx = 0;
			pthread_create(&thread_id[time_set.i], NULL,
			philo_ranchi, (void *)&philo_data_set[time_set.i]);
			pthread_detach(thread_id[time_set.i]);
		}
	}
	while (1)
	{
		if (time_set.error || 
		check_if_philo_satiety(0, philo_data_set))
			break ;
	}
	while (++time_set.i < time_set.num_of_philo)
		pthread_mutex_destroy(&forks_set.forks[time_set.i]);
	pthread_mutex_destroy(&time_set.take_forks);
	//time_set.i = -1;
	/*while (++time_set.i < time_set.num_of_philo)
	{
		memfree_alloc((void **)&philo_data_set[time_set.i].philo);
		memfree_alloc((void **)&philo_data_set[time_set.i].forks);
	}
	memfree_alloc((void **)&philo_data_set);
	memfree_alloc((void **)&thread_id);*/
	return (0);
}