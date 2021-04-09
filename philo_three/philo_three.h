#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000
# define PHDEATH 0xde

typedef unsigned int    uint32;
typedef unsigned short	uint16;

uint16		wb_atoi(char *str, uint16 res, int flags);

#endif
