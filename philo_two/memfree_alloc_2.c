#include "philo_two.h"

void    memfree_alloc2(void ***addr, int size)
{
    int i;

    if (**addr)
    {
        i = -1;
        while (++i < size)
        {
            free(*(*addr + i));
            *(*addr + i) = NULL;
        }
        free(**addr);
        **addr = NULL;
    }
}