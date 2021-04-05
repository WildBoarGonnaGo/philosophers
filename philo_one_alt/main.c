#include "philo_one.h"

t_philo_data			*num_of_philo_init(t_time *time_set,
						/*pthread_mutex_t *addr, */t_forks *forks_set)
{
	t_philo_data	*data;
	//t_forks			*forks_data;
	//void			*clean;
	int				i;

	if (time_set->num_of_philo <= 0)
		return (0x0);
	//time_data_proc_init(time_set, )
	data = (t_philo_data *)malloc(sizeof(t_philo_data) * time_set->num_of_philo);
	//forks_data_init(forks_data, *time_set);
	i = -1;
	while (++i < time_set->num_of_philo)
	{
		memset((void *)&data[i], 0, sizeof(t_philo_data) - 1);
		data[i].philo = (t_philo *)malloc(sizeof(t_philo));
		data[i].forks = (t_forks *)malloc(sizeof(t_forks));
		philo_data_init(data[i].philo, i, i % (time_set->num_of_philo - 1),
		(i + 1) % (time_set->num_of_philo - 1));
		//forks_data_init(&data[i].forks, addr);
		data[i].philo->input_time_data = time_set;
		data[i].philo->philo_hp = (long)time_set->time_to_die;
		data[i].forks = forks_set;
		data[i].misc = time_set;
	}
	return (data);
}

int						main(int argc, char *argv[])
{
	t_philo_data		*philo_data_set;
	//t_philo				*philo_info;
	pthread_t			*thread_id;
	t_forks				forks_set;
	//pthread_mutex_t     take_forks;
	t_time				time_set;
	//int					i;

	//i = -1;
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
	/*
	while (++i < NUM_OF_PHILO)
	{
		philo_data_init(&philo_info[i], i, i % (NUM_OF_PHILO - 1),
		(i + 1) % (NUM_OF_PHILO - 1));
		philo_info[i].input_time_data = &time_set;
		philo_info[i].philo_hp = (long)time_set.time_to_die;
	}
	forks_data_init(&forks_set, &take_forks);
	i = -1;
	while (++i < NUM_OF_PHILO)
	{
		philo_data_set[i].philo = &philo_info[i];
		philo_data_set[i].forks = &forks_set;
	}
	i = -1;*/
	time_set.i = -1;
	pthread_mutex_init(time_set.take_forks, NULL);
	while (++time_set.i < time_set.num_of_philo)
		pthread_create(&thread_id[time_set.i], NULL,
		philos_lives_matter, (void *)&philo_data_set[time_set.i]);
	time_set.i = -1;
	while (++time_set.i < time_set.num_of_philo)
		pthread_join(thread_id[time_set.i], NULL);
	time_set.i = -1;
	while (++time_set.i < time_set.num_of_philo)
		pthread_mutex_destroy(&forks_set.forks[time_set.i]);
	pthread_mutex_destroy(time_set.take_forks);
	return (0);
}