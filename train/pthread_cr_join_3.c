#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12
#define BAD_MESSAGE -13
#define SUCCESS 0

typedef struct	someArgs_tag
{
	int			id;
	const char	*msg;
	int			out;
}				someArgs_t;

void	*helloWorld(void *args)
{
	someArgs_t	*info;
	int			len;

	info = (someArgs_t *)args;
	if (!info->msg)
		return ((void *)BAD_MESSAGE);
	len = strlen(info->msg);
	printf("%s\n", info->msg);
	info->out = len;
	return (SUCCESS);
}

#define NUM_THREADS 4

int		main(void)
{
	pthread_t	khans[NUM_THREADS];
	int			status;
	int			i;
	void		**status_addr;
	someArgs_t	flash_gitz[NUM_THREADS];
	const char	*message[] = {
		"Blood Axes",
		"Goff",
		"Bad Moons",
		"Evil Sunz"
	};

	for (i = 0; i < NUM_THREADS; ++i)
	{
		flash_gitz[i].id = i;
		flash_gitz[i].msg = message[i];
	}
	for (i = 0; i < NUM_THREADS; ++i)
	{
		status = pthread_create(&khans[i], NULL,
		helloWorld, (void *)&flash_gitz[i]);
		if (status)
		{
			printf("main error: can't create thread, status = %d\n", status);
			exit(ERROR_CREATE_THREAD);
		}
	}
	printf("Main message\n");
	for (i = 0; i < NUM_THREADS; ++i)
	{
		status_addr = NULL;
		status = pthread_join(khans[i], (void **)status_addr);
		if (status != SUCCESS)
		{
			printf("main error: can't join thread, status = %d\n", status);
			exit (ERROR_JOIN_THREAD);
		}
		printf("joined with address %d\n", (int)status_addr);
	}
	for (i = 0; i < NUM_THREADS; ++i)
		printf("thread %d flash_gitz.out = %d\n",
		i, flash_gitz[i].out);
	return (0);
}
