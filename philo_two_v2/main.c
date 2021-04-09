#include "philo_two.h"

int						main(int argc, char *argv[])
{
	t_sema_philo	prot;
	t_philo_hands	*heretic;
	pthread_t		*dead_swallow;

	if (argc < 5 || argc > 6)
	{
		printf("bash: philo_two: wrong number of arguments");
		return (1);
	}
	sema_philo_data_init(&prot, argc, argv);
	dead_swallow = (pthread_t *)malloc(sizeof(pthread_t) * prot.philo_num);
	sem_unlink("forks");
	prot.forks = sem_open("forks", O_CREAT, 0644, prot.philo_num);
	sem_unlink("waiter");
	prot.waiter = sem_open("waiter", O_CREAT, 0644, prot.waiter_busy);
	prot.indx = -1;
	heretic = philo_hands_init(&prot);
	(prot.num_of_time_philo_must_eat == -1) ? philo_choose_case(philo_seikatsu, heretic, dead_swallow) :
	philo_choose_case(philo_ranchi, heretic, dead_swallow);
	while (1)
	{
		if (prot.error || check_if_philo_satiety(0, heretic))
			break ;
	}
	sem_close(prot.forks);
	sem_close(prot.waiter);
	return (0);
}

/*int						check_if_philo_satiety(int i, t_philo_hands *data)
{
	if (data[i].c_nerve->
	num_of_time_philo_must_eat == -1)
		return (0);
	else if (data[i].stty_indx !=
	data[i].c_nerve->num_of_time_philo_must_eat)
		return (0);
	else if (i < data[i].c_nerve->philo_num)
		check_if_philo_satiety(++i, data);
	return (1);
}*/	

/*void					philo_choose_case(void *(*good_day)(void *),
						t_philo_hands *data, pthread_t *thread_id)
{
	while (++data->c_nerve->indx < data->c_nerve->philo_num)
	{
		pthread_create(thread_id + data->c_nerve->indx, NULL,
		good_day, (void *)&data[data->c_nerve->indx]);
		pthread_detach(*(thread_id + data->c_nerve->indx));
	}
}*/

/*void					sema_philo_data_init(t_sema_philo *obj,
						int argc, char *argv[])
{
	obj->philo_num = wb_atoi(argv[1], 0, ZERO | SPACE | PLUSMINUS);
	obj->time_to_die = wb_atoi(argv[2], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	obj->time_to_eat = wb_atoi(argv[3], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	obj->time_to_sleep = wb_atoi(argv[4], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	obj->num_of_time_philo_must_eat = (argc != 6) ? -1 :
	wb_atoi(argv[5], 0, ZERO | SPACE | PLUSMINUS);
	obj->waiter_busy = 1;
}*/

/*t_philo_hands			*philo_hands_init(t_sema_philo *wagon)
{
	t_philo_hands	*init;
	int				i;

	init = (t_philo_hands *)malloc(sizeof(t_philo_hands) * wagon->philo_num);
	wagon->error = 0;
	i = -1;
	while (++i < wagon->philo_num)
	{
		init[i].left_hand = DROPFORK;
		init[i].right_hand = DROPFORK;
		init[i].c_nerve = wagon;
		init[i].timeflow = 0;
		gettimeofday(&wagon->cur_time, NULL);
		init[i].old_time = wagon->cur_time.tv_sec * 1000 +
		wagon->cur_time.tv_usec / 1000;
		init[i].philo_hp = wagon->time_to_die;
		init[i].num = i;
		init[i].stty_indx = -1;
	}
	return (init);
}*/

/*void					*philo_seikatsu(void *args)
{
	t_philo_hands	*sinner;

	sinner = (t_philo_hands *)args;
	while (1)
	{
		if (!waiter_give_fork(sinner))
			return (NULL);
		calculate_time(sinner, sinner->c_nerve->time_to_eat,
		philo_is_eating);
		if (sinner->c_nerve->error)
			return (NULL);
		waiter_fork_takeout(sinner);
		calculate_time(sinner, sinner->c_nerve->time_to_sleep,
		philo_is_sleeping);
		if (sinner->c_nerve->error)
			return (NULL);
		calculate_time(sinner, 0, philo_is_thinking);
		if (sinner->c_nerve->error)
			return (NULL);
	}
	return (NULL);
}*/

/*void					*philo_ranchi(void *args)
{
	t_philo_hands	*sinner;

	sinner = (t_philo_hands *)args;
	while (++sinner->stty_indx < 
	sinner->c_nerve->num_of_time_philo_must_eat)
	{
		if (!waiter_give_fork(sinner))
			return (NULL);
		calculate_time(sinner, sinner->c_nerve->time_to_eat,
		philo_is_eating);
		if (sinner->c_nerve->error)
			return (NULL);
		waiter_fork_takeout(sinner);
		calculate_time(sinner, sinner->c_nerve->time_to_sleep,
		philo_is_sleeping);
		if (sinner->c_nerve->error)
			return (NULL);
		calculate_time(sinner, 0, philo_is_thinking);
		if (sinner->c_nerve->error)
			return (NULL);
	}
	return (NULL);
}*/


/*int						waiter_give_fork(t_philo_hands *data)
{
	if (data->left_hand != TAKEFORK)
	{
		sem_wait(data->c_nerve->waiter);
		sem_wait(data->c_nerve->forks);
		data->left_hand = TAKEFORK;
		calculate_time(data, 0, philo_takes_fork);
		if (data->c_nerve->error)
			return (0);
		sem_post(data->c_nerve->waiter);
	}
	if (data->right_hand != TAKEFORK)
	{
		sem_wait(data->c_nerve->forks);
		data->right_hand = TAKEFORK;
		calculate_time(data, 0, philo_takes_fork);
		if (data->c_nerve->error)
			return (0);
	}
	return (1);
}*/

/*void					waiter_fork_takeout(t_philo_hands *data)
{
	sem_post(data->c_nerve->forks);
	sem_post(data->c_nerve->forks);
	data->left_hand = DROPFORK;
	data->right_hand = DROPFORK;
}*/

/*void					calculate_time(t_philo_hands *data, long sleep,
						void (*starve)(t_philo_hands *, long delta))
{
	long delta;

	usleep(sleep);
	gettimeofday(&data->c_nerve->cur_time, NULL);
	data->timeflow += data->c_nerve->cur_time.tv_sec * 1000 +
	data->c_nerve->cur_time.tv_usec / 1000 - data->old_time;
	delta = (data->c_nerve->cur_time.tv_sec * 1000 +
	data->c_nerve->cur_time.tv_usec / 1000 - data->old_time) * 1000;
	data->old_time = data->c_nerve->cur_time.tv_sec * 1000 +
    data->c_nerve->cur_time.tv_usec / 1000;
	starve(data, delta);
}*/

/*void					philo_takes_fork(t_philo_hands *philo_data, long delta)
{
	printf("%ld %d has taken a fork\n",
    philo_data->timeflow, philo_data->num + 1);
	philo_data->philo_hp -= delta;
	if (philo_data->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->timeflow,
		philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
}*/

/*void					philo_is_eating(t_philo_hands *philo_data, long delta)
{
	printf("%ld %d is eating\n", philo_data->timeflow,
	philo_data->num + 1);
	philo_data->philo_hp = philo_data->c_nerve->time_to_die - delta;
	if (philo_data->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->timeflow,
		philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
}*/

/*void					philo_is_sleeping(t_philo_hands *philo_data, long delta)
{
	printf("%ld %d is sleeping\n",
    philo_data->timeflow, philo_data->num + 1);
	philo_data->philo_hp -= delta;
	if (philo_data->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->timeflow,
		philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
}*/

/*void					philo_is_thinking(t_philo_hands *philo_data, long delta)
{
	printf("%ld %d is thinking\n",
    philo_data->timeflow, philo_data->num + 1);
	philo_data->philo_hp -= delta;
	if (philo_data->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->timeflow,
		philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
}*/