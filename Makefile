# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:23:26 by nelallao          #+#    #+#              #
#    Updated: 2023/04/09 23:16:17 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC =	utils.c \
		so_long.c \
		check_map.c \
		check_map_2.c \

MLX = /Users/nelallao/goinfre/programs/MLX42/build/libmlx42.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -lglfw -L"/Users/nelallao/.brew/Cellar/glfw/3.3.8/lib"
LIB = libft.a/libft.a

all : $(LIB) $(NAME)

$(NAME) : $(SRC)
	$(CC) $(MLX) $(CFLAGS) $(LIB) $(SRC) -o so_long

$(LIB) :
	make -C libft.a

clean :
	@make clean -C libft.a
	@rm -rf $(NAME)
fclean :
	@make fclean -C libft.a
	@rm -dfr ./so_long

re : fclean all
