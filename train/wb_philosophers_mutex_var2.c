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
# define PHDEATH 0xde

typedef unsigned int    uint32;
typedef unsigned short	uint16;

typedef struct          s_time
{
	long	time_to_die;
	long    time_to_eat;
	long	time_to_sleep;
	int		number_of_time_philo_eats;
	int		error;
}                       t_time;

typedef struct          s_philo
{
	uint32          num;
	uint32          left_fork;
	uint32          right_fork;
	struct timeval  cur_time;
	long            time_travel;
	long			old_time;
	long			philo_hp;
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
	philo->old_time = 0;
}

void                    time_data_proc_init(t_time *time_input, int argc, char *argv[])
{
	time_input->time_to_die = wb_atoi(argv[1], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	time_input->time_to_eat = wb_atoi(argv[2], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	time_input->time_to_sleep = wb_atoi(argv[3], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	time_input->number_of_time_philo_eats = (argc != 5) ? -1 :
	wb_atoi(argv[4], 0, ZERO | SPACE | PLUSMINUS);
}

void                    forks_data_init(t_forks *forks, pthread_mutex_t *addr)
{
	int i;

	i = -1;
	while (++i < NUM_OF_PHILO)
		pthread_mutex_init(&forks->forks[i], NULL);
	forks->take_forks = addr;
}

long					return_usec_round(useconds_t time)
{
	long	check;

	check = (time / 100) - (time / 1000) * 10;
	return (check > 5) ? (time / 1000 + 1) : (time / 1000);
}


void					philo_is_eating(t_philo_data *philo_data)
{
	printf("[%ld ms] philosopher %d is eating\n", philo_data->philo->time_travel,
	philo_data->philo->num);
	philo_data->philo->philo_hp = philo_data->philo->input_time_data->time_to_die -
	philo_data->philo->input_time_data->time_to_eat;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("[%ld ms] philosopher %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num);
		philo_data->philo->input_time_data->error = PHDEATH;
	}
}

void					philo_is_sleeping(t_philo_data *philo_data)
{
	printf("[%ld ms] philosopher %d is sleeping\n", philo_data->philo->time_travel,
	philo_data->philo->num);
	philo_data->philo->philo_hp -= philo_data->philo->input_time_data->time_to_sleep;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("[%ld ms] philosopher %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num);
		philo_data->philo->input_time_data->error = PHDEATH;
	}
	printf("[%ld ms] philosopher %d is thinking\n", philo_data->philo->time_travel,
	philo_data->philo->num);
}

void					philo_takes_fork(t_philo_data *philo_data)
{
	printf("[%ld ms] philosopher %d has taken a fork\n", philo_data->philo->time_travel,
	philo_data->philo->num);
}

void					calculate_time(t_philo_data *data, useconds_t sleep,
						void (*starve)(t_philo_data *))
{
	usleep(sleep);
	gettimeofday(&data->philo->cur_time, NULL);
	data->philo->time_travel = data->philo->cur_time.tv_sec * 1000 +
	return_usec_round(data->philo->cur_time.tv_usec) - data->philo->old_time;
	data->philo->old_time = data->philo->time_travel;
	starve(data);
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
		pthread_mutex_lock(forks_init->take_forks);
		pthread_mutex_lock(&forks_init->forks[philo_init->left_fork]);
		calculate_time(philo_manager, 0, philo_takes_fork);
		if (philo_manager->philo->input_time_data->error)
			break ;
		pthread_mutex_unlock(forks_init->take_forks);
		pthread_mutex_lock(&forks_init->forks[philo_init->right_fork]);
		calculate_time(philo_manager, philo_manager->philo->input_time_data->time_to_eat,
		philo_is_eating);
		if (philo_manager->philo->input_time_data->error)
			break ;
		pthread_mutex_unlock(&forks_init->forks[philo_init->right_fork]);
		pthread_mutex_unlock(&forks_init->forks[philo_init->left_fork]);
		calculate_time(philo_manager, philo_manager->philo->input_time_data->time_to_sleep,
		philo_is_sleeping);
		if (philo_manager->philo->input_time_data->error)
			break ;
	}
	//pthread_mutex_destroy(&take_forks);
	return (NULL);
}

int						main(int argc, char *argv[])
{
	t_philo_data		philo_data_set[NUM_OF_PHILO];
	t_philo				philo_info[NUM_OF_PHILO];
	pthread_t			thread_id[NUM_OF_PHILO];
	t_forks				forks_set;
	pthread_mutex_t     take_forks;
	t_time				time_set;
	int					i;

	i = -1;
	if (argc < 4 || argc > 5)
	{
		printf("philo_one: wrong number of arguments\n");
		return (1);
	}
	//pthread_mutex_init(&take_forks)
	time_data_proc_init(&time_set, argc, argv);
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
