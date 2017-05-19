# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 17:13:13 by qho               #+#    #+#              #
#    Updated: 2017/05/19 12:08:01 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
FRAME	=	-framework OpenGL -framework AppKit

FILES	=	main ft_map_init ft_draw ft_rotate_map ft_get_map \
			ft_adjust_map ft_draw_line
INC		=	./inc/
SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		=	$(addprefix build/, $(SRCS:.c=.o))

# 
MLX_INC	=	minilibx_macos
MLX_LIB	=	minilibx_macos
MLX		=	-I $(MLX_INC) -L $(MLX_LIB) -lmlx

GNL		=	get_next_line/gnl.a
LIBFT	=	libft/libft.a

.PHONY: clean fclean re norm

all: $(NAME)	

$(NAME): $(SRC)
	@make -C libft
	@make -C get_next_line
	@make -C minilibx_macos
	@echo "\033[32mminilibx compiled\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(GNL) -I $(INC) $(MLX) $(FRAME)
	@echo "\033[32mCompiled fdf\033[0m"

norm:
	norminette $(SRC) $(INC)

clean:
	@make -C libft clean
	@make -C get_next_line clean
	@/bin/rm -f $(OBJ)
	@make clean -C minilibx_macos
	@echo "\033[31mObject files cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@make -C get_next_line fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31mExecutable cleaned\033[0m"

re: fclean all