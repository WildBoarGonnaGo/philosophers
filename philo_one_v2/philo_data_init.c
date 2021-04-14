#include "philo_one.h"

void                    philo_data_init(t_philo_data *philo, uint32 num/*,
						uint32 left, uint32 right*/)
{
	struct timeval	temp;
	int				indx;
	//philo->philo.num = num;
	//philo->left_fork = left;
	//philo->right_fork = right;
	indx = (num + 1) % philo->misc->num_of_philo;
	philo->philo.left_fork = &philo[indx].philo.simple_fork;
	gettimeofday(&temp, NULL);
	philo->philo.time_travel = 0;
	philo->philo.old_time = temp.tv_sec * 1000 +
    /*return_usec_round(temp.tv_usec)*/temp.tv_usec / 1000;
}