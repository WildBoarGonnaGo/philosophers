NAME 		= philo_one
CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror
SRC			= ./calculate_time.c		\
			  ./forks_data_init.c		\
			  ./memfree_alloc_2.c 		\
			  ./memfree_alloc.c			\
			  ./main.c					\
			  ./philo_data_init.c		\
			  ./philo_is_eating.c		\
			  ./philo_is_sleeping.c		\
			  ./philo_ranchi.c			\
			  ./philo_seikatsu.c		\
			  ./philo_takes_fork.c		\
			  ./return_usec_round.c		\
			  ./time_data_proc_init.c	\
			  ./wb_atoi.c				
EXTERN_LIB	= -lpthread

all: $(SRC)
	@echo "Let's make the philo_one executable ..."
	@if [ ! -e $(NAME) ]; then									\
		$(CC) $(FLAGS) $(SRC) -o $(NAME) $(EXTERN_LIB);			\
		echo "$(NAME) executable is successfully made ...";	\
	else														\
		echo "executable is already made ...";					\
	fi
clean:
	@echo "executable is deleted ..."
	@rm -f $(NAME)

fclean: clean

re: fclean all
