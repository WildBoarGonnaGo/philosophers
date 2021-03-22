#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void		*trythis(void *arg)
{
	unsigned long	i;
	int				*res;

	res = (int *)arg;
	*res += 1;
	printf("Job %d has been started\n", *res);
	for (i = 0; i < (0xFFFFFFFF); ++i)
		;
	printf("Job %d has been finished\n", *res);
	return (NULL);

}

int			main(void)
{
	pthread_t	tid[2];
	int			i;
	int			error;
	int			counter;

	i = -1;
	counter = 0;
	while (++i < 2)
	{
		error = pthread_create(&tid[i], NULL, trythis, (void *)&counter);
		if (error)
			printf("Thread can't be created : %s\n", strerror(error));
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return (0);
}
