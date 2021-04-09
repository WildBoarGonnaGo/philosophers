#include "philo_two.h"

t_philo_hands			*philo_hands_init(t_sema_philo *wagon)
{
	t_philo_hands	*init;
	int				i;

	init = (t_philo_hands *)malloc(sizeof(t_philo_hands)
    * wagon->philo_num);
	wagon->error = 0;
	i = -1;
	while (++i < wagon->philo_num)
	{
		init[i].left_hand = DROPFORK;
		init[i].right_hand = DROPFORK;
		init[i].c_nerve = wagon;
		init[i].timeflow = 0;
		gettimeofday(&wagon->cur_time, NULL);
		init[i].old_time = wagon->cur_time.tv_sec * 1000 +
		wagon->cur_time.tv_usec / 1000;
		init[i].philo_hp = wagon->time_to_die;
		init[i].num = i;
		init[i].stty_indx = -1;
	}
	return (init);
}