/*Семафор - это объект, который используется для контроля доступа
нескольких потоков до общего ресурса. В общем случае это какая-то переменная,
состояние которой изменяется каждым из потоков. Текущее состояние переменной
определяет доступ к ресурсам.*/

#include <pthread.h>
//Семафоры описаны в библиотеке semaphore.h
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_sem
{
	sem_t		semaphore;
	int			count;
	int			valp;
}				t_sem;

void		*worker1(void *args)
{
	t_sem	*flash_gitz;
	int		i;
	int		local;

	flash_gitz = (t_sem *)args;
	for (i = 0; i < 100; ++i)
	{
		/*Для ожидания доступа используется функция
		int	sem_wait(sem_t *sem);
		*/
		sem_wait(&(flash_gitz->semaphore));
		local = flash_gitz->count;
		printf("worker1 - %d\n", local++);
		flash_gitz->count = local;
		sleep(1);
		/*Если значение семафора отрицательное, по вызывающий
		поток блокируется до тех пор, пока один из потоков не
		вызовет sem_post
		
		int		sem_post(sem_t *sem)
		
		Эта функция увеличиывает значение семафора и разблокирует
		близжайшие потоки.*/
		sem_post(&(flash_gitz->semaphore));
	}
}

void		*worker2(void *args)
{
	t_sem	*flash_gitz;
	int		i;
	int		local;

	flash_gitz = (t_sem *)args;
	for (i = 0; i < 100; i++)
	{
		sem_wait(&(flash_gitz->semaphore));
		local = flash_gitz->count;
		printf("worker2 - %d\n", local--);
		flash_gitz->count = local;
		sleep(1);
		sem_post(&(flash_gitz->semaphore));
	}
}

int			main(void)
{
	/*в pthread семафор - это переменная типа sem_t, которая может находиться
	 в заданном числе состояний. Каждый счетчик может увеличить счетчик семафора
	 или уменьшить его. В Литературе операция увеличения счетчика называется
	 V.  Уменьшение счетчика - это операция P
	 
	 ЗАМЕЧАНИЕ: иногда мьютекс называют двоичным семафором, указывая на то, что мьютекс
	 может находиться в двух состояниях. Но здесь есть важное отличие: разблокировать
	 мьютекс может только тот поток, который его заблокировал, семафор же может разблокировать
	 любой поток*/
	t_sem		kaizer;
	pthread_t	thread1;
	pthread_t	thread2;
	kaizer.count = 0;
	/*Работа с семафорами похожа на работу с мьютексами. Сначала необходимо инициализировать
	 сеафор с помощью функции
	 
	 int	sem_init(sem_t *sem, int pshared, unsigned int value)
	 
	 sem_t - это указатель на семафор, pshared - флаг указывающий, должен ли быть семафор
	 расшарен при использовании функции fork(), value - начальное значение семафора.*/
	sem_init(&(kaizer.semaphore), 0, 1);
	
	pthread_create(&thread1, NULL, worker1, (void *)&kaizer);
	pthread_create(&thread2, NULL, worker2, (void *)&kaizer);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	/*sem_destroy(sem_t *sem) - эта функция уничтожает семафор
	Кроме того, можно получить текущее значение семафора через функцию
	
	int	sem_getvalue(sem_t *sem, int *valp)*/
	printf("the current value of semaphore: %d\n",
	sem_getvalue(&(kaizer.semaphore), &(kaizer.valp)));
	printf("the valp value: %d\n", kaizer.valp);
	sem_destroy(&(kaizer.semaphore));
	printf(" == %d\n", kaizer.count);
	return (0);
}
