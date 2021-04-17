# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 22:11:57 by lchantel          #+#    #+#              #
#    Updated: 2021/04/16 20:20:42 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo_two
CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror
SRC			= ./calculate_time.c			\
			  ./check_if_philo_satiety.c	\
			  ./main.c						\
			  ./memfree_alloc.c				\
			  ./philo_choose_case.c			\
			  ./philo_hands_init.c			\
			  ./philo_is_eating.c			\
			  ./philo_is_sleeping.c			\
			  ./philo_is_thinking.c			\
			  ./philo_ranchi.c				\
			  ./philo_seikatsu.c			\
			  ./philo_takes_fork.c			\
			  ./sema_philo_data_init.c		\
			  ./waiter_fork_takeout.c		\
			  ./waiter_give_fork.c			\
			  ./wb_atoi.c					\
			  ./check_pidt_case_state.c		
EXTERN_LIB	= -pthread

all: $(SRC)
	@echo "Let's make the philo_one executable ..."
	@if [ ! -e $(NAME) ]; then									\
		$(CC) $(FLAGS) $(SRC) -o $(NAME) $(EXTERN_LIB);			\
		echo "$(NAME) executable is successfully made ...";		\
	else														\
		echo "executable is already made ...";					\
	fi
clean:
	@echo "executable is deleted ..."
	@rm -f $(NAME)

fclean: clean

re: fclean all
