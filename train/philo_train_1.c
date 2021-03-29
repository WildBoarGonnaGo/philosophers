#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

# define PHILO_NUM 5

pthread_mutex_t lock[5];

void    *thr(void *arg)
{
    int left;
    int right;
    int i;

    i = (int)arg;
    // The first four takes the left hand
    if (i < 4)
    {
        left = i;
        if (!i)
            right = 4;
        else
            right = i - 1;
    }
    //The fifth one takes the right lock
    if (i == 4)
    {
        left = i - 1;
        right = i;
    }
    while (1)
    {
        //Apply for the lock on the left
        pthread_mutex_lock(&lock[left]);
        //Aplly for the lock on the right
        if ((pthread_mutex_trylock(&lock[right])) != 0)
        {
			pthread_mutex_unlock(&lock[left]);
            //printf(" ==thread %d == Application failed\n", i);
            continue ;
        }
        //Both sides succesfully applied
        printf("==thread %d == succesfull\n", i);
        //Release the lock
        pthread_mutex_unlock(&lock[left]);
        pthread_mutex_unlock(&lock[right]);
        sleep(1);
    }
}

int     main(void)
{
    //initialization
    int         i;
    pthread_t   dit[5];

    i = -1;
    while (++i < 5)
        pthread_mutex_init(&lock[i], NULL);
    //Create thread
    i = -1;
    while (++i < 5)
        pthread_create(&dit[i], NULL, thr, (void *)i);
    //Recycle thread
    i = -1;
    while (++i < 5)
        pthread_join(dit[i], NULL);
    //Destruction of mutex
    i = -1;
    while (++i < 5)
        pthread_mutex_destroy(&lock[i]);
    return (0);
}
