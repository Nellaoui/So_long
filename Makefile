# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:23:26 by nelallao          #+#    #+#              #
#    Updated: 2023/04/14 17:52:41 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC =	mandatory/utils.c \
		mandatory/map.c \
		mandatory/keys.c \
		mandatory/utils_2.c \
		mandatory/utils_3.c \
		mandatory/so_long.c \
		mandatory/check_map.c \
		mandatory/check_map_2.c \

MLX = lib/libmlx42/libmlx42.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -lglfw -L "lib"
LIB = mandatory/libft.a/libft.a
LIBF =  mandatory/printf/libftprintf.a

all : $(LIB) $(LIBF) $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(MLX) $(CFLAGS) $(LIB) $(LIBF) $(SRC) -o so_long

$(LIBF) :
	@make -C mandatory/printf
$(LIB) :
	@make -C mandatory/libft.a

clean :
	@make clean -C mandatory/libft.a
	@make clean -C mandatory/printf
	@rm -rf $(NAME)
fclean :
	@make fclean -C mandatory/libft.a
	@make fclean -C mandatory/printf
	@rm -dfr ./so_long

re : fclean all
