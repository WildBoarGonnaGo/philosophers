#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define PHILO_NUM 5

typedef struct  s_philo_one
{
    pthread_mutex_t fork[PHILO_NUM];
    pthread_t       philo[PHILO_NUM];
    int             right;
    int             left;
    struct timeval  get_time;
    long            old_time[PHILO_NUM];
    long            time_travel[PHILO_NUM];
	int				indx;
}               t_philo_one;

//pthread_mutex_t lock[PHILO_NUM];

void    *thr(void *arg)
{
    //int left;
    //int right;
    //int i;
	t_philo_one	*earth_corp;

    earth_corp = (t_philo_one *)arg;
    // The first four takes the left hand
    if (earth_corp->indx < 4)
    {
        earth_corp->left = earth_corp->indx;
        if (!earth_corp->indx)
            earth_corp->right = 4;
        else
            earth_corp->right = earth_corp->indx - 1;
    }
    //The fifth one takes the right lock
    if (earth_corp->indx == 4)
    {
        earth_corp->left = earth_corp->indx - 1;
        earth_corp->right = earth_corp->indx;
    }
    while (1)
    {
        //Apply for the lock on the left
        pthread_mutex_lock(&earth_corp->fork[earth_corp->left]);
        //Aplly for the lock on the right
        if ((pthread_mutex_trylock(&earth_corp->
		fork[earth_corp->right])) != 0)
        {
            pthread_mutex_unlock(&earth_corp->fork[earth_corp->left]);
            printf(" ==thread %d == Application failed\n", earth_corp->indx);
            continue ;
        }
        //Both sides succesfully applied
        printf("==thread %d == succesfull\n", earth_corp->indx);
        //Release the lock
		//usleep(200);
        pthread_mutex_unlock(&earth_corp->fork[earth_corp->left]);
        pthread_mutex_unlock(&earth_corp->fork[earth_corp->right]);
        sleep(1);
    }
}

int     main(void)
{
    //initialization
    t_philo_one	terran;

    terran.indx = -1;
    while (++terran.indx < 5)
        pthread_mutex_init(&terran.fork[terran.indx], NULL);
    //Create thread
    terran.indx = -1;
    while (++terran.indx < 5)
        pthread_create(&terran.philo[terran.indx], NULL, thr, (void *)&terran);
    //Recycle thread
    terran.indx = -1;
    while (++terran.indx < 5)
        pthread_join(terran.philo[terran.indx], NULL);
    //Destruction of mutex
    terran.indx = -1;
    while (++terran.indx < 5)
        pthread_mutex_destroy(&terran.fork[terran.indx]);
    return (0);
}
