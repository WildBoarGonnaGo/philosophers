#include "philo_two.h"

void                    time_data_proc_init(t_time *time_input, int argc, char *argv[])
{
	time_input->num_of_philo = wb_atoi(argv[1], 0, ZERO | SPACE | PLUSMINUS);
	time_input->time_to_die = wb_atoi(argv[2], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	time_input->time_to_eat = wb_atoi(argv[3], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	time_input->time_to_sleep = wb_atoi(argv[4], 0, ZERO | SPACE | PLUSMINUS) * 1000;
	time_input->number_of_time_philo_eats = (argc != 6) ? -1 :
	wb_atoi(argv[5], 0, ZERO | SPACE | PLUSMINUS);

}