# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 21:32:06 by lchantel          #+#    #+#              #
#    Updated: 2021/04/17 19:13:30 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo_one
CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror
SRC			= ./calculate_time.c		\
			  ./memfree_alloc.c			\
			  ./main.c					\
			  ./philo_data_init.c		\
			  ./philo_is_eating.c		\
			  ./philo_is_sleeping.c		\
			  ./philo_ranchi.c			\
			  ./philo_seikatsu.c		\
			  ./philo_takes_fork.c		\
			  ./time_data_proc_init.c	\
			  ./wb_atoi.c				\
			  ./set_ref_fork.c			\
			  ./case_handle.c			\
			  ./check_if_dish_life.c	\
			  ./philo_routine_body.c	\
			  ./philo_is_thinking.c		
EXTERN_LIB	= -pthread

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
