#include "philo_two.h"

long					return_usec_round(useconds_t time)
{
	long	check;

	check = (time / 100) - (time / 1000) * 10;
	return (check > 5) ? (time / 1000 + 1) : (time / 1000);
}