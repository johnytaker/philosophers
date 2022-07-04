# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/07/04 12:19:57 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = ./includes/

INCLUDES = $(INCLUDES_PATH)philo_bonus.h

PTHREAD = -pthread

RM = @rm -rf

SRCS_DIR = ./sources/

OBJS_DIR = ./objects/

SRCS_FILES =	allocation_utils.c	\
				execution.c			\
				ft_atoi.c			\
				parse_and_init.c	\
				philo.c				\
				print_utils.c		\
				process_utils.c		\
				semaphore_utils.c	\
				time.c				\
				types_of_actions.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

all : temp $(NAME)

temp :
	@mkdir -p ./objects/

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "\nphilo_bonus updated"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) Makefile
	$(CC) $(CFLAGS) $(PTHREAD)  -I $(INCLUDES_PATH) -c $< -o $@

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJS_DIR)
	@echo "\nphilo_bonus clean done"

fclean :
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	@echo "\nphilo_bonus fclean done"

re : fclean all
