#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12
#define BAD_MESSAGE -13
#define SUCCESS 0
#define NUM_THREADS 4

typedef unsigned int	uint32;

typedef struct			someArgs_tag
{
	int			id;
	char		*msg;
	int			out;
}						someArgs_t;

void					addchar(char **str, char c)
{
	int		len;
	char	*clean;
	int		i;

	i = -1;
	if (!*str)
	{
		*str = (char *)malloc(sizeof(char));
		**str = '\0';
	}
	clean = *str;
	len = strlen(*str) + 2;
	*str = (char *)malloc(sizeof(char) * len);
	while (*str[++i])
		*str[i] = clean[i];
	*(*str + i++) = c;
	*(*str + i) = 0;	
	free(clean);
	clean = NULL;
}

void					itoa_base16(int num, uint32 base,
						char **res)
{
	if (num < 0)
	{
		addchar(res, '-');
		num *= -1;
	}
	else if (num > 10)
		itoa_base16(num / base, base, res);
	addchar(res, "0123456789abcdef"[num % 10]);
}

someArgs_t		*create_troopers()
{
	someArgs_t	*flash_gitz;
	int			i;

	i = -1;
	flash_gitz = (someArgs_t *)malloc(sizeof(someArgs_t)
	* NUM_THREADS);
	while (++i < NUM_THREADS)
	{
		//flash_gitz[i] = (someArgs_t *)malloc(sizeof(someArgs_t));
		itoa_base16(i, 10, &flash_gitz[i].msg);
		flash_gitz[i].id = i;
		flash_gitz[i].out = i;
	}
	return (flash_gitz);
}

void			*helloWorld(void *args)
{
	someArgs_t	*info;	
	int			len;

	info = (someArgs_t *)args;
	if (!info->msg)
		return ((void *)BAD_MESSAGE);
	len = strlen(info->msg);
	printf("number of thread is: %s\n", info->msg);
	//info->out = len;
	return (SUCCESS);
}

int				main(void)
{
	pthread_t	*khans;
	someArgs_t	*units;
	int			info[2];
	void		**status_addr;

	khans = (pthread_t *)malloc(sizeof(pthread_t)
	* NUM_THREADS);
	/*for (info[0]  = 0; info[0] < NUM_THREADS; ++info[0])
		khans[info[0]] = 0x0;
	units = NULL;*/
	units = create_troopers();
	for (info[0] = 0; info[0] < NUM_THREADS; info[0]++)
	{
		info[1] = pthread_create(&khans[info[0]], NULL,
		helloWorld, &units[info[0]]);
		if (info[1] != 0)
		{
			printf("main error: can't create a thread, status = %d\n", info[1]);
			exit(ERROR_CREATE_THREAD);
		}
	}
	printf("Main message\n");
	for (info[0] = 0; info[0] < NUM_THREADS; info[0]++)
	{
		status_addr = NULL;
		info[1] = pthread_join(khans[info[0]], status_addr);
		if (info[1] != SUCCESS)
		{
			printf("main error: can't join the thread, status = %d\n", info[1]);
			exit(ERROR_CREATE_THREAD);
		}
		printf("joined with address %lu\n", (unsigned long)status_addr);
	}
	for (info[0] = 0; info[0] < NUM_THREADS; ++info[0])
		printf("thread %d units.out = %d\n", info[0], units[info[0]].out);
	return (0);
}
