#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int	counter = 0;

void		*worker1(void *args)
{
	int	i;
	int	local;

	for (i = 0; i < 100; ++i)
	{
		local = counter;
		printf("worker_1 - %d\n", local++);
		counter = local;
		sleep(2);
	}
}

void		*worker2(void *args)
{
	int	i;
	int	local;

	for (i = 0; i < 100; ++i)
	{
		local = counter;
		printf("worker_2 - %d\n", local--);
		counter = local;
		sleep(2);
	}
}

int			main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, worker1, NULL);
	pthread_create(&thread2, NULL, worker2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("== %d", counter);
}
