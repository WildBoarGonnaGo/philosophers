#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

typedef long	millseconds;

long	wb_micro_to_mille(suseconds_t var)
{
	suseconds_t		check;
	
	check = (var / 100) - (var / 1000) * 10;
	return (check > 5) ? (var / 1000 + 1) : (var / 1000);
}

int 	main(void)
{
	struct timeval	tv_test;
	useconds_t		loop;
	long			old;
	//long			prefix;
	long			time_travel;
	int 			i;
	
	time_travel = 0;
	loop = 2000000;
	gettimeofday(&tv_test, NULL);
	old = 0;
	//prefix = 0;
	printf("mileseconds = %ld\n", time_travel);
	//printf("mileseconds = %ld\n", tv_test.tv_usec / 1000);
	i = -1;
	while (++i < 10)
	{
		old = tv_test.tv_sec * 1000 + wb_micro_to_mille(tv_test.tv_usec);
		usleep(loop);
		gettimeofday(&tv_test, NULL);
		time_travel += tv_test.tv_sec * 1000 + wb_micro_to_mille(tv_test.tv_usec) - old;
		printf("mileseconds = %ld\n", time_travel);
		//printf("mileseconds = %ld\n", tv_test.tv_usec / 1000);

	}
	return (0);
}
