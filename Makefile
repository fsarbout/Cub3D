# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:02:45 by fsarbout          #+#    #+#              #
#    Updated: 2021/02/08 10:53:58 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX_OSX	= ./libft/libft.a -lmlx -framework OpenGL -framework AppKit

MLX_UBU	= ./libft/libft.a -lm -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

_MLX_ = $(MLX_OSX)
ifeq ($(shell uname), Linux)
	_MLX_ = $(MLX_UBU)
endif

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
 	srcs/collection.c\
	srcs/draw_2d.c

all : $(NAME)

$(NAME): $(SRC)
	@cd libft && make re
	@$(CC) $(SRC) $(CFLAGS) -o $(NAME) $(_MLX_)
	
clean:
	@cd libft && make clean
	@rm -rf cub3d.bmp

fclean: clean
	@rm -rf $(NAME) 

re:	fclean all
