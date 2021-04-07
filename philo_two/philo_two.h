#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>

# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000
# define PHDEATH 0xde

typedef unsigned int    uint32;
typedef unsigned short	uint16;

typedef struct          s_time
{
    int     		num_of_philo;
	long			time_to_die;
	long    		time_to_eat;
	long			time_to_sleep;
	int				number_of_time_philo_eats;
	int				error;
    int				i;
	int				detach_moveout;
    sem_t			take_forks;
}                       t_time;

typedef struct          s_philo
{
	uint32          num;
	uint32          left_fork;
	uint32          right_fork;
	struct timeval  cur_time;
	long   			time_travel;
	long			old_time;
	long			philo_hp;
	int				ranchi_indx;
}                       t_philo;

typedef struct          s_forks
{
	sem_t	*forks;
}                       t_forks;

typedef struct          s_philo_data
{
	t_philo *philo;
	t_forks *forks;
	t_time	*misc;
}                       t_philo_data;

uint16		            wb_atoi(char *str, uint16 res, int flags);
long					return_usec_round(useconds_t time);
void                    philo_data_init(t_philo *philo, uint32 num,
						uint32 left, uint32 right);
void                    forks_data_init(t_forks *forks, t_time time_set);
void                    time_data_proc_init(t_time *time_input,
                        int argc, char *argv[]);
void					philo_is_eating(t_philo_data *philo_data, long delta);
void					philo_is_sleeping(t_philo_data *philo_data, long delta);
void					philo_takes_fork(t_philo_data *philo_data, long delta);
void					calculate_time(t_philo_data *data, long sleep,
						void (*starve)(t_philo_data *, long delta));
void                    *philo_seikatsu(void *data);
t_philo_data			*num_of_philo_init(t_time *time_set,
						t_forks *forks_set);
void                    *philo_ranchi(void *data);
void    				memfree_alloc(void **addr);
void    				memfree_alloc2(void ***addr, int size);

#endif