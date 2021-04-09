#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000
# define EAT 0b0001
# define SLEEP 0b0010
# define TAKEFORK 0b0100
# define DROPFORK 0b1000
# define PHDEATH 0xde

typedef unsigned int	uint32;
typedef unsigned short	uint16;

typedef struct			s_sema_philo
{
    int				indx;
	uint16			philo_num;
	uint16			waiter_busy;
	sem_t			*forks;
	sem_t			*waiter;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	int				num_of_time_philo_must_eat;
	struct timeval	cur_time;
	uint16			error;
}						t_sema_philo;

typedef struct			s_philo_hands
{
	uint16			left_hand;
	uint16			right_hand;
	long			philo_hp;
	long			old_time;
	long			timeflow;
	int				num;
	t_sema_philo	*c_nerve;
	int				stty_indx;
}						t_philo_hands;

uint16					wb_atoi(char *str, uint16 res, int flags);
void					sema_philo_data_init(t_sema_philo *obj,
						int argc, char *argv[]);
void					*philo_seikatsu(void *args);
void					*philo_ranchi(void *args);
t_philo_hands			*philo_hands_init(t_sema_philo *wagon);
int						waiter_give_fork(t_philo_hands *data);
void					calculate_time(t_philo_hands *data, long sleep,
						void (*starve)(t_philo_hands *, long delta));					
void					philo_takes_fork(t_philo_hands *philo_data, long delta);
void					philo_is_eating(t_philo_hands *philo_data, long delta);
void					philo_is_sleeping(t_philo_hands *philo_data, long delta);
void					philo_is_thinking(t_philo_hands *philo_data, long delta);
void					waiter_fork_takeout(t_philo_hands *data);
void					philo_choose_case(void *(*good_day)(void *),
						t_philo_hands *data, pthread_t *thread_id);
int						check_if_philo_satiety(int i, t_philo_hands *data);
void					memfree_alloc(void **addr);
void    				memfree_alloc2(void ***addr, int size);

#endif 