# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:02:45 by fsarbout          #+#    #+#              #
#    Updated: 2021/01/17 11:41:45 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc -Wall -Wextra -Werror

CFLAGS = ./libft/libft.a -lmlx -framework OpenGL  -framework AppKit

HEADER = cub3d.h\
		functions.h\
		structs.h\
		macros.h

SRC = srcs/hook.c\
	srcs/intersections.c\
 	srcs/list.c\
	srcs/main.c\
	srcs/print_error.c\
	srcs/raycasting_calc.c\
	srcs/read_file.c\
 	srcs/render_3d.c\
	srcs/sprite.c\
	srcs/sprite_utils.c\
	srcs/treat_map.c\
	srcs/utils.c\
	srcs/bmp.c\
	srcs/check_extension.c\
 	srcs/collection.c 

all : $(NAME)

$(NAME): $(SRC) $(HEADER)
	@cd libft && make re
	@$(CC) $(SRC) $(CFLAGS) -o $(NAME)
	
clean:
	@cd libft && make clean
	@rm -rf cub3d.bmp

fclean: clean
	@rm -rf $(NAME) 

re:	fclean all
