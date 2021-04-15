# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 22:08:54 by lchantel          #+#    #+#              #
#    Updated: 2021/04/15 22:08:55 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo_three
CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror
SRC			= ./calculate_time.c			\
			  ./check_philo_table.c			\
			  ./fork_philo_init_data.c 		\
			  ./loop_condition.c			\
			  ./main.c						\
			  ./misc_init_data.c			\
			  ./philo_is_eating.c			\
			  ./philo_is_sleeping.c			\
			  ./philo_is_thinking.c			\
			  ./philo_lifetime.c			\
			  ./philo_preparing_to_eat.c	\
			  ./philo_put_forks.c			\
			  ./philo_takes_fork.c			\
			  ./wb_atoi.c					\
			  ./memfree_alloc.c				\
			  ./fork_proc.c

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
