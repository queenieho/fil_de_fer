# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 16:17:11 by qho               #+#    #+#              #
#    Updated: 2017/05/10 16:29:30 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= get_next_line.c
INC		= get_next_line.h
OBJ 	= $(SRC:.c=.o)

LIB_INC = ../libft

.PHONY: clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"

$(OBJ): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC) -I $(INC) -I $(LIB_INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31mGNL object files cleaned\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mGNL cleaned\033[0m"

re: fclean all
