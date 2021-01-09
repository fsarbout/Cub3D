# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:02:45 by fsarbout          #+#    #+#              #
#    Updated: 2021/01/08 15:41:36 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

#mac compliation
CFLAGS = -g -lmlx -framework OpenGL  -framework AppKit -fsanitize=address -o $(NAME)


#linux compilation
#CFLAGS = -g -lm -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -fsanitize=address

SRC =   ./srcs/*.c ./libft/*.c

all : $(NAME)

$(NAME):
	@$(CC) $(SRC) $(CFLAGS) -O3 -o $(NAME) && ./cub3D map.cub
	
#don't forget the optimazation flag

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME) 

re:	fclean all