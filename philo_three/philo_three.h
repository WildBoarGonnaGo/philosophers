#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000
# define PHDEATH 0xde

# define PHILO_TAKE_FORK 1
# define PHILO_PUT_FORK 0

typedef unsigned int    uint32;
typedef unsigned short	uint16;

typedef struct  s_misc
{
    int     		error;
    long    		time_to_die;
    long    		time_to_sleep;
    long    		time_to_eat;
    int     		num_of_time_philo_must_eat;
    uint16      	philo_num;
	pid_t			*philo_pid;
	sem_t			*dead_philo;
	sem_t			*chopstick;
	sem_t			*swallow;
	sem_t			*output;
	struct timeval	cur_time;
}               t_misc;

typedef struct  s_fork_philo
{
    uint16      num;
    int         left_hand;
    int         right_hand;
    t_misc      *misc_data;
	long		philo_hp;
	long		time_travel;
	long		old_time;
}               t_fork_philo;

uint16			wb_atoi(char *str, uint16 res, int flags);
int				misc_init_data(t_misc *data, int argc, char *argv[]);
int				fork_philo_init_data(t_fork_philo *data, t_misc *misc);

#endif
