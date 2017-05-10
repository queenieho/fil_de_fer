# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 17:13:13 by qho               #+#    #+#              #
#    Updated: 2017/05/09 23:49:10 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
FRAME	=	-framework OpenGL -framework AppKit

FILES	=	main
SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		=	$(SRC:.c=.o)
INC		=	./inc/

# 
MLX_INC	=	minilibx_macos
MLX_LIB	=	minilibx_macos
MLX		=	-I $(MLX_INC) -L $(MLX_LIB) -lmlx

.PHONY: clean fclean re norm

all: $(NAME)	

$(NAME):
	@make -C minilibx_macos
	@echo "\033[32mminilibx compiled\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I $(INC) $(MLX) $(FRAME)
	@echo "\033[32mCompiled fdf\033[0m"


norm:
	norminette $(SRC) $(INC)

clean:
	@/bin/rm -f $(OBJ)
	make clean -C minilibx_macos
	@echo "\033[31mObject files cleaned\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mExecutable cleaned\033[0m"

re: fclean all