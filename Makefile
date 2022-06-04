# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/06/04 18:42:21 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = ./includes/

INCLUDES = $(INCLUDES_PATH)philo.h

RM = @rm -rf

SRCS_DIR = ./sources/

OBJS_DIR = ./objects/

SRCS_FILES = 

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))


OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

all : temp $(NAME)

temp :
	@mkdir -p ./objects/

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJS_DIR)
	@echo "\nphilo clean done\n"

fclean :
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	@echo \nphilo fclean done\n"

re : fclean all