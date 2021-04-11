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