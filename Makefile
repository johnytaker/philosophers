# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/06/15 04:59:30 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -O2

INCLUDES_PATH = ./includes/

INCLUDES = $(INCLUDES_PATH)philo.h

PTHREAD = -pthread

RM = @rm -rf

SRCS_DIR = ./sources/

OBJS_DIR = ./objects/

SRCS_FILES =	ft_atoi.c			\
				parse_and_init.c	\
				philo.c				\
				print_utils.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

all : temp $(NAME)

temp :
	@mkdir -p ./objects/

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "\nphilo udpated"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) Makefile
	$(CC) $(CFLAGS) $(PTHREAD)  -I $(INCLUDES_PATH) -c $< -o $@

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJS_DIR)
	# @echo "\nphilo clean done"

fclean :
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	@echo "\nphilo fclean done"

re : fclean all
