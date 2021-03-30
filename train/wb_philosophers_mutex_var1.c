/*
Dining philosophers with deadlock
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_OF_PHILO 5

typedef unsigned int    uint32;

/* Объявим структуру философ (t_philo), которая будет хранить имя философа
и номера вилок, которые он может взять*/
typedef struct          s_philo
{
   const char   *name;
   uint32       left_fork;
   uint32       right_fork;
}                       t_philo;

/*
Далее структура стол (t_table) которая состоит из массива вилок. 
В качестве вилки будет выступать мьютекс (mutex). Блокировка
мьютекса означает "взять вилку", а разблокировка - "положить ее обратно"
*/
typedef struct          s_table
{
    pthread_mutex_t fork[NUM_OF_PHILO];
}                       t_table;

/*Кроме того, для передачи этих параметров в поток
объединим их в структуру*/

typedef struct          s_philo_args
{
    const t_philo   *philo;
    const t_table   *table;
}                       t_philo_args;

/*Две вспомогательные функции инициализации ...*/
void                    init_philo(t_philo *tmnt, const char *name,
                        uint32 left_fork, uint32 right_fork)
{
    tmnt->name = name;
    tmnt->left_fork = left_fork;
    tmnt->right_fork = right_fork;
}

void                    init_table(t_table *fboar)
{
    int i;

    i = -1;
    while (++i < NUM_OF_PHILO)
        pthread_mutex_init(&fboar->fork[i], NULL);
}

/*... И наша основная функция которая моделирует обед*/
void                    *philo_eats(void *data)
{
    t_philo_args        *dragon;

    dragon = (t_philo_args *)data;
    const t_philo *philo = dragon->philo;
    const t_table *table = dragon->table;
    printf("%s started to have a dinner\n", philo->name);
    pthread_mutex_lock(&table->fork[philo->left_fork]);
    pthread_mutex_lock(&table->fork[philo->right_fork]);
    printf("%s is eating\n", philo->name);
    pthread_mutex_unlock(&table->fork[philo->right_fork]);
    pthread_mutex_unlock(&table->fork[philo->left_fork]);
    printf("%s finished to have a dinner\n", philo->name);
}

/*Теперь осталось запустить 5 потоков и инициализировать их*/
int                     main(void)
{
    pthread_t       thread_id[NUM_OF_PHILO];
    t_philo         legats[NUM_OF_PHILO];
    t_philo_args    battlecruiser[NUM_OF_PHILO];
    t_table         senate;
    int         i;

    init_table(&senate);
    init_philo(&legats[0], "Alice", 0, 1);
    init_philo(&legats[1], "Bob", 1, 2);
    init_philo(&legats[2], "Clark", 2, 3);
    init_philo(&legats[3], "Denis", 3, 4);
    init_philo(&legats[4], "Eugin", 4, 0);

    i = -1;
    while (++i < NUM_OF_PHILO)
    {
        battlecruiser[i].philo = &legats[i];
        battlecruiser[i].table = &senate;
    }
    i = -1;
    while (++i < NUM_OF_PHILO)
        pthread_create(&thread_id[i], NULL, philo_eats, (void *)&battlecruiser[i]);
    i = -1;
    while (++i < NUM_OF_PHILO)
        pthread_join(thread_id[i], NULL);
    return (0);
}
