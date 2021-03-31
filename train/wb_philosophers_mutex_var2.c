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

typedef struct          s_time
{
    useconds_t          time_to_die;
    useconds_t          time_to_eat;
    useconds_t          time_to_sleep;
}                       t_time;

typedef struct          s_philo
{
    uint32          num;
    uint32          left_fork;
    uint32          right_fork;
    struct timeval  tv;
    long            time_travel;
    t_time          *input_time_data;
}                       t_philo;

typedef struct          s_forks
{
    pthread_mutex_t forks[NUM_OF_PHILO];
	pthread_mutex_t	*take_forks;
}                       t_forks;

typedef struct          s_philo_data
{
    t_philo *philo;
    t_forks *forks;
}                       t_philo_data;

//pthread_mutex_t take_forks = PTHREAD_MUTEX_INITIALIZER;

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
    philo->time_travel = 0;

}

void                    time_data_proc_init(t_time *time_input,int argc, char *argv[])
{
    int i;

    i = -1;
    
}

void                    forks_data_init(t_forks *forks, pthread_mutex_t *addr)
{
    int i;

    i = -1;
    while (++i < NUM_OF_PHILO)
        pthread_mutex_init(&forks->forks[i], NULL);
	forks->take_forks = addr;
}

void                    *philos_lives_matter(void *data)
{
    t_philo_data    *philo_manager;
    t_philo         *philo_init;
    t_forks         *forks_init;

    philo_manager = (t_philo_data *)data;
    philo_init = philo_manager->philo;
	forks_init = philo_manager->forks;
    //pthread_mutex_init(&take_forks, NULL);
    while (1)
    {

        //printf("philosopher %d starts to eat\n", philo_init->num + 1);
        pthread_mutex_lock(forks_init->take_forks/*&take_forks*/);
        pthread_mutex_lock(&forks_init->forks[philo_init->left_fork]);
        printf("philosopher %d take the left fork\n", philo_init->num + 1);
        pthread_mutex_unlock(forks_init->take_forks/*&take_forks)*/);
        pthread_mutex_lock(&forks_init->forks[philo_init->right_fork]);
        printf("philosopher %d take the right fork\n", philo_init->num + 1);
        printf("philosopher %d is eating\n", philo_init->num + 1);
        usleep(400000);
        //pthread_mutex_unlock(/*&forks_init->take_forks*/&take_forks);
        pthread_mutex_unlock(&forks_init->forks[philo_init->right_fork]);
        pthread_mutex_unlock(&forks_init->forks[philo_init->left_fork]);
        printf("philosopher %d stoped to eat\n", philo_init->num + 1);
    }
    //pthread_mutex_destroy(&take_forks);
	return (NULL);
}

int						main(void)
{
	t_philo_data		philo_data_set[NUM_OF_PHILO];
	t_philo				philo_info[NUM_OF_PHILO];
	pthread_t			thread_id[NUM_OF_PHILO];
	t_forks				forks_set;
    pthread_mutex_t     take_forks;
    
	int					i;
	i = -1;
    //pthread_mutex_init(&take_forks)
	while (++i < NUM_OF_PHILO)
		philo_data_init(&philo_info[i], i, i % (NUM_OF_PHILO - 1),
		(i + 1) % (NUM_OF_PHILO - 1));
	forks_data_init(&forks_set, &take_forks);
	i = -1;
	while (++i < NUM_OF_PHILO)
	{
		philo_data_set[i].philo = &philo_info[i];
		philo_data_set[i].forks = &forks_set;
	}
	i = -1;
    pthread_mutex_init(&take_forks, NULL);
	while (++i < NUM_OF_PHILO)
		pthread_create(&thread_id[i], NULL,
		philos_lives_matter, (void *)&philo_data_set[i]);
	i = -1;
	while (++i < NUM_OF_PHILO)
		pthread_join(thread_id[i], NULL);
	i = -1;
	while (++i < NUM_OF_PHILO)
		pthread_mutex_destroy(&forks_set.forks[i]);
    pthread_mutex_destroy(&take_forks);
	return (0);
}
