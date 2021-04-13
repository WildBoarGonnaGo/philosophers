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
# include <sys/wait.h>
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
    int             status;
    uint16      	philo_num;
	sem_t			*dead_philo;
	sem_t			*chopstick;
	sem_t			*waiter;
    sem_t           *swallow;
	sem_t       	*msg;
	struct timeval	cur_time;
}               t_misc;

typedef struct  s_fork_philo
{
    uint16      num;
    pid_t       philo_pid;
    uint16      swallow;
    int         left_hand;
    int         right_hand;
    uint16		satiate_philo;
    t_misc      *misc_data;
	long		philo_hp;
	long		time_travel;
	long		old_time;
	long		dead_old_time;
	int			philo_died;
}               t_fork_philo;

uint16			wb_atoi(char *str, uint16 res, int flags);
int				misc_init_data(t_misc *data, int argc, char *argv[]);
t_fork_philo	*fork_philo_init_data(t_misc *misc);
int				loop_condition(t_fork_philo *obj);
int 			philo_is_eating(t_fork_philo *crnl, long diff_time,
				long old_time);
int				philo_is_sleeping(t_fork_philo *crnl, long diff_time,
				long old_time);
int				philo_is_thinking(t_fork_philo *crnl, long diff_time,
				long old_time);
int				philo_takes_fork(t_fork_philo *crnl, long diff_time,
				long old_time);
int				calculate_time(t_fork_philo *data, 
				int (*func)(t_fork_philo *, long, long), long time);
void			*check_philo_table(void *data);
void			philo_preparing_to_eat(t_fork_philo *philo);
void			philo_put_forks(t_fork_philo *philo);
int				philo_lifetime(void *proc);

#endif
