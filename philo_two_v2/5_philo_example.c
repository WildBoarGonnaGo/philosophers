#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/time.h>

# define THINKING 2
# define HUNGRY 1
# define EATING 0
# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000
# define PHDEATH 0xde


typedef unsigned short	uint16;

uint16		wb_atoi(char *str, uint16 res, int flags);

typedef struct	s_sem_squad
{
    int			*state;
    int			*philo;
	int			i;
	sem_t		lock;
	sem_t		*sema_phorks;
	pthread_t	*thread;
	uint16		philo_num;
}				t_sem_squad;

/*
Number of the left fork - (i + philo.hum - 1) % philo.num
Number of the right fork - (i + 1) % philo.num
*/
void			check_state(t_sem_squad *data)
{
	if (data->state[data->i] &&
	data->state[(data->i + data->philo_num - 1)
	% data->philo_num] != EATING && data->state[(data->i + 1) 
	% data->philo_num != EATING])
	{
		// state that's eating
		data->state[data->i] = EATING;
		usleep(200000);
		printf("Philosopher %d takes fork %d and %d\n",
		data->philo_num + 1, (data->i + data->philo_num - 1)
		% data->philo_num, data->philo_num + 1);
		printf("Philosopher %d is eating\n", data->philo_num + 1);
		/*
		sem_post(&data->sema_phorks[data->philo_num])
		during takefork is used to wakeup hungry philosophers
		during putfork
		*/
		sem_post(&data->sema_phorks[data->philo_num]);
	}
}


//take up chopsticks
void			philo_take_fork(t_sem_squad *data)
{
	sem_wait(&data->lock);
	// state that hungry
	data->state[data->i] = HUNGRY;
	printf("Philosopher %d is hungry\n", data->i + 1);
	// eat if neighbours are not eating
	check_state(data);
	sem_post(&data->lock);
	//  if unable to eat wait to be signalled
	sem_wait(&data->sema_phorks[data->i]);
	usleep(200000);
}

//put down chopsticks
void			philo_putdown_fork(t_sem_squad *data)
{
	
}

void			*philo_routine(void *num)
{
	int	*i;

	i = (int *)num;
	while (1)
	{
		;
	}
}

int 			main(int argc, char *argv[])
{
	t_sem_squad	obj;

	if (argc != 2)
		printf("Wrong number of arguments\n");
	obj.philo_num = wb_atoi(argv[1], 0, ZERO | PLUSMINUS | SPACE);
	obj.state = (int *)malloc(sizeof(int) * obj.philo_num);
	obj.philo = (int *)malloc(sizeof(int) * obj.philo_num);
	obj.thread = (pthread_t *)malloc(sizeof(pthread_t) * obj.philo_num);
	// Initialize the semaphores
	obj.sema_phorks = (sem_t *)malloc(sizeof(sem_t) * obj.philo_num);
	obj.i = -1;
	sem_init(&obj.lock, 0, 0);
	while (++obj.i < obj.philo_num)
		sem_init(&obj.sema_phorks[obj.i], 0, 0);
	obj.i = -1;
	// Create philosopher processes
	while (++obj.i < obj.philo_num)
		printf("Philosopher %d is thinking", obj.i + 1);
    return (0);
}