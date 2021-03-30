#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

#define NUM_OF_PHILO 5

typedef unsigned int    uint32;

typedef struct          s_philo 
{
    uint32  num;
    uint32  left_fork;
    uint32  right_fork;
}                       t_philo;

typedef struct          s_forks
{
    pthread_mutex_t forks[NUM_OF_PHILO];
}                       t_forks;

typedef struct          s_philo_data
{
    t_philo *philo;
    t_forks *forks;
}                       t_philo_data;

void                    philo_data_init(t_philo *philo, uint32 num, 
                        uint32 left, uint32 right)
{
    philo->num = num;
    philo->left_fork = left;
    philo->right_fork = right;
}

void                    table_data_init(t_forks *forks)
{
    int i;

    i = -1;
    while (++i < NUM_OF_PHILO)
        pthread_mutex_init(&forks->forks[i], NULL);
}

void                    *philos_lives_matter()
{
    
}
