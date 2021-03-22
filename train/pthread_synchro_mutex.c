/*
The most popular way to achive synchronization is by using Mutexes

Mutex
- A Mutex is a lock that we set before using a shared resource and release after using it
- When the lock is set, no other thread can access the locked region of code
- So we see that even if thread 2 is scheduled while thread 1 was not done
  accessing the shared resource and the code is locked by thread 1 using mutexes
  then thread 2 cannot even access that region of code.
- So this ensures synchronized access of shared resources in the code
* */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long	uint64;

typedef struct			sync_info_thread
{
	int				var;
	//int				i;
	int				counter;
	pthread_t		tid[2];
	pthread_mutex_t	lock;
}						sync_info_t;

void					*thread_func(void *arg)
{
	uint64		i;
	sync_info_t	*info;
	
	info = (sync_info_t *)arg;
	pthread_mutex_lock(&info->lock);
	++info->counter;
	printf("Job %d has started\n", info->counter);
	for (i = 0; i < (0xFFFFFFFF); ++i)
		;
	printf("Job %d has finished\n", info->counter);
	pthread_mutex_unlock(&info->lock);
	return (NULL);
}

int						main(void)
{
	int			error;
	int			i;
	sync_info_t	flash_gitz;

	if (pthread_mutex_init(&flash_gitz.lock, NULL))
	{
		printf("Error: mutex init has failed\n");
		exit (1);
	}
	i = -1;
	while (++i < 2)
	{
		error = pthread_create(&flash_gitz.tid[i], NULL,
		thread_func, (void *)&flash_gitz);
		if (error)
		{
			printf("Error: thread can't be created : %s\n",
			strerror(error));
			exit (1);
		}
	}
	pthread_join(flash_gitz.tid[0], NULL);
	pthread_join(flash_gitz.tid[1], NULL);
	pthread_mutex_destroy(&flash_gitz.lock);
	return (0);

}
