# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:02:45 by fsarbout          #+#    #+#              #
#    Updated: 2020/12/20 04:14:29 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc -Wall -Wextra -Werror

CFLAGS = -g -lmlx -framework OpenGL -framework AppKit -fsanitize=address -o $(NAME)

SRC =   ./*.c\
		../libft/*.c\

all : $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -O3 && ./cub3D map.cub
	
#don't forgot the optimazation flag

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME) 

re:	fclean all