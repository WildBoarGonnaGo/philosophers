#include "philo_one.h"

void    memfree_alloc(void **addr)
{
    if (*addr)
    {
        free(*addr);
        *addr = NULL;
    }
}