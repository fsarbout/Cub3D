# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:02:45 by fsarbout          #+#    #+#              #
#    Updated: 2021/01/16 12:34:08 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc -g #-Wall -Wextra -Werror

#mac compliation
CFLAGS = ./libft/libft.a -lmlx -framework OpenGL  -framework AppKit -o $(NAME)


#linux compilation
#CFLAGS = -g -lm -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -fsanitize=address

SRC =   ./srcs/*.c


all : $(NAME)

$(NAME):
	@cd libft && make re
	@$(CC) $(SRC) $(CFLAGS)
	
clean:
	@cd libft && make clean
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME) 

re:	fclean all
