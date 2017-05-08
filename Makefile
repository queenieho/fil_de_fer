# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 17:13:13 by qho               #+#    #+#              #
#    Updated: 2017/03/08 13:53:11 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

HEADER = minilibx

LIB = minilibx_macos

.PHONY: clean fclean re norm

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I $(HEADER) -L $(LIB) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32mCompiled fdf"

norm:
	norminette $(SRC) fdf.h

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31mObject files cleaned"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mExecutable cleaned"

re: fclean all