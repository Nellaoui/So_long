# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:23:26 by nelallao          #+#    #+#              #
#    Updated: 2023/04/02 22:29:29 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = 	so_long.c \


CC = cc
CFLAGS =  -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
LIB = libft.a/libft.a

all : $(LIB) $(NAME)
$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(LIB) $(SRC) -o so_long

$(LIB) :
	make -C libft.a

clean :
	@make clean -C libft.a
	@rm -rf $(NAME)
fclean :
	@make fclean -C libft.a
	@rm -dfr ./so_long

re : fclean all
