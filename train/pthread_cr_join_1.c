#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*Набор значений, необходимый для обработки возможных ошибок*/
# define ERROR_CREATE_THREAD -11
# define ERROR_JOIN_THREAD -12
# define SUCCESS 0

/*Функция которая будет работать в отдельном потоке. Она не будет
получать никаких аргументов. После создания потока происходит проверка
на ошибку*/
void	*helloWorld(void *args)
{
	printf("Hello from thread!\n");
	return (SUCCESS);
}

int		main(void)
{
	pthread_t	thread;
	int			status;
	int			status_addr;

	/*
	Новый поток создается с помощью функции pthread_create:

	int pthread_create(*pthread t, const pthread_attr_t *attr,
	void * (*start routine)(void *), void *arg)

	Функция получает в качестве аргументов указатель на поток, переменную типа
	pthread_t, в которую, в случае удачного завершения сохраняет id потока,
	pthread_attr_t - аттрибуты потока. В случае, если используются аттрибуты по умолчанию,
	то можно передавать NULL. start_routine - непосредственно та функция которая будет 
	выполняться в новом потоке, arg - аргументы которые будут переданы функции

	Поток может выполнять много разных дел и получать разные аргументы. Для этого
	функция, которая будет запущена в новом потоке, принимает аргумент типа 
	void *. За счет этого, можно обернуть все передаваемые аргументы в структуру.
	Возвращать значение можно также через передаваемый аргумент.
	
	Здесь содается и сразу же исполяется новый поток. Поток не получает никаких
	аттрибутов и аргументов. После создания потока происходит проверка
	на ошибку, Вызов: */
	status = pthread_create(&thread, NULL, helloWorld, NULL);
	if (status)
	{
		printf("main error: can't create thread, status = %d\n", status);
		exit(ERROR_CREATE_THREAD);
	}
	/*Приводит к тому, что основной поток будет ждать завершение порожденного.*/
	printf("Hello from main!\n");
	/*Функция
	int pthread_join(pthread_t thread, void **value_ptr)
	
	Откладывает выполнение вызывающего (эту функцию потока), до тех пор, пока не будет
	выполнен поток thread. Когда pthread_join выполнилась успешно, то она возвращает
	0. Если поток явно вернул значение (это то самое значение SUCCESS из нашей функции),
	то оно будет перемещено в переменную value_ptr. Возможные ошибки, которые возвращает
	pthread_join смотри в man=)*/
	status = pthread_join(thread, (void **)&status_addr);
	if (status != SUCCESS)
	{
		printf("main error: can't join the thread, status = %d\n", status);
		exit(ERROR_JOIN_THREAD);
	}
	printf("joined with address %d\n", status_addr);
	getchar();
	return (0);
}
