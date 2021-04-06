#include "philo_two.h"

void                    philo_data_init(t_philo *philo, uint32 num,
						uint32 left, uint32 right)
{
	struct timeval	temp;

	philo->num = num;
	philo->left_fork = left;
	philo->right_fork = right;
	gettimeofday(&temp, NULL);
	philo->time_travel = 0;
	philo->old_time = temp.tv_sec * 1000 +
    return_usec_round(temp.tv_usec);
}