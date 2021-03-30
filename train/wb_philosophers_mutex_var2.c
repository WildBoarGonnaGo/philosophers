#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

# define NUM_OF_PHILO 5
# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000


typedef unsigned int    uint32;
typedef unsigned short	uint16;

typedef struct          s_philo
{
    uint32  num;
    uint32  left_fork;
    uint32  right_fork;
}                       t_philo;

typedef struct          s_forks
{
    pthread_mutex_t forks[NUM_OF_PHILO];
	pthread_mutex_t	take_forks;
}                       t_forks;

typedef struct          s_philo_data
{
    t_philo *philo;
    t_forks *forks;
}                       t_philo_data;

int		wb_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int		wb_pow(int digit, uint32 pow)
{
	if (!pow)
		return (1);
	else if (pow == 1)
		return (digit);
	return (digit * wb_pow(digit, --pow));
}

uint16		wb_atoi(char *str, uint16 res, int flags)
{
	if (!str)
		return (0);
	if (*str > 8 && *str < 12 && (flags & SPACE))
		return (wb_atoi(++str, res, flags));
	else if ((*str == '-') && (flags & PLUSMINUS))
		return (wb_atoi(++str, res, (flags | SUBZERO)
		& ~(SPACE | PLUSMINUS)));
	else if ((*str == '+') && (flags & PLUSMINUS))
		return (wb_atoi(++str, res, flags & ~(SPACE | PLUSMINUS)));
	else if (*str == '0' && (flags & ZERO))
		return (wb_atoi(++str, res, (flags & ~SPACE)));
	else if (wb_isdigit(*str) && *str)
	{
		res *= 10;
		res += (*str - 48) * wb_pow(-1, ((flags & SUBZERO) != 0));
		return (wb_atoi(++str, res, (flags & ~ZERO)));
	}
	return (res);
}

void                    philo_data_init(t_philo *philo, uint32 num,
                        uint32 left, uint32 right)
{
    philo->num = num;
    philo->left_fork = left;
    philo->right_fork = right;
}

void                    forks_data_init(t_forks *forks)
{
    int i;

    i = -1;
    while (++i < NUM_OF_PHILO)
        pthread_mutex_init(&forks->forks[i], NULL);
	pthread_mutex_init(&forks->take_forks, NULL);
}

void                    *philos_lives_matter(void *data)
{
    t_philo_data    *philo_manager;
    t_philo         *philo_init;
    t_forks         *forks_init;

    philo_manager = (t_philo_data *)data;
    philo_init = philo_manager->philo;
	forks_init = philo_manager->forks;
	printf("philosopher %d starts to eat\n", philo_init->num + 1);
	pthread_mutex_lock(&forks_init->forks[philo_init->left_fork]);
	sleep(1);
	pthread_mutex_lock(&forks_init->forks[philo_init->right_fork]);
	printf("philosopher %d is eating\n", philo_init->num + 1);
	pthread_mutex_unlock(&forks_init->forks[philo_init->right_fork]);
	pthread_mutex_unlock(&forks_init->forks[philo_init->left_fork]);
	printf("philosopher %d stoped to eat\n", philo_init->num + 1);
	return (NULL);
}

int						main(void)
{
	t_philo_data		philo_data_set[NUM_OF_PHILO];
	t_philo				philo_info[NUM_OF_PHILO];
	pthread_t			thread_id[NUM_OF_PHILO];
	t_forks				forks_set;
	int					i;

	i = -1;
	while (++i < NUM_OF_PHILO)
		philo_data_init(&philo_info[i], i, i % (NUM_OF_PHILO - 1),
		(i + 1) % (NUM_OF_PHILO - 1));
	forks_data_init(&forks_set);
	i = -1;
	while (++i < NUM_OF_PHILO)
	{
		philo_data_set[i].philo = &philo_info[i];
		philo_data_set[i].forks = &forks_set;
	}
	i = -1;
	while (++i < NUM_OF_PHILO)
		pthread_create(&thread_id[i], NULL,
		philos_lives_matter, (void *)&philo_data_set[i]);
	i = -1;
	while (++i < NUM_OF_PHILO)
		pthread_join(thread_id[i], NULL);
	i = -1;
	while (++i < NUM_OF_PHILO)
		pthread_mutex_destroy(&forks_set.forks[i]);
	return (0);
}
