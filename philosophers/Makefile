# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 15:03:13 by ahmaidi           #+#    #+#              #
#    Updated: 2022/06/23 06:02:18 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = is_number.c check_args.c ft_atoi.c init_data.c gettime_now.c int_forks.c finish_simulation.c inti_philos.c create_threads.c ft_error.c utils_routine.c ft_usleep.c ft_strlen.c supervisor.c philo.c

all: $(NAME)

$(NAME): $(SRCS)
	@echo "\033[91m ____   _   _  __  __       _   "
	@echo "\033[91m(  __ \/ )_( \(  )(  )    /   \ "
	@echo "\033[91m )  __/) __  ( )( /  (_/\(  o  )"
	@echo "\033[91m(___)  \_) (_/(__)\_____/ \ _ / "
	@$(CC) $(CFLAGS) $(SRCS) -pthread -o  $(NAME)  
	@echo "\033[92mExecution file Created\033[0m"

fclean:
	@$(RM) $(NAME)
	@echo "\033[91mExecution file deleted\033[0m"
clean: fclean
re: fclean all

.PHONY: all fclean re