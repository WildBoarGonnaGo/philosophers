#include "philo_two.h"

void    memfree_alloc(void **addr)
{
    if (*addr)
    {
        free(*addr);
        *addr = NULL;
    }
}