#include "philo_two.h"

void					sema_philo_data_init(t_sema_philo *obj,
						int argc, char *argv[])
{
	obj->philo_num = wb_atoi(argv[1], 0, ZERO | SPACE | PLUSMINUS);
	obj->time_to_die = wb_atoi(argv[2], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	obj->time_to_eat = wb_atoi(argv[3], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	obj->time_to_sleep = wb_atoi(argv[4], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	obj->num_of_time_philo_must_eat = (argc != 6) ? -1 :
	wb_atoi(argv[5], 0, ZERO | SPACE | PLUSMINUS);
	obj->waiter_busy = 1;
}