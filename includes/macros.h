/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:23 by fsarbout          #+#    #+#             */
/*   Updated: 2021/02/08 10:53:30 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define MAX_WIDTH	2560
# define MAX_HEIGHT	1440
# define W_WIDTH 500
# define W_HEIGHT 500
# define TILE 64
# define STEP 20
# define FOV 1.04719755
# define WALL_S_W 0.5
# define MINIM 0.3
# define RAD 0.01745329
# define BIG_NUM 9999999999.0

#if __APPLE__
    # define UP 13
    # define DOWN 1
    # define ESC 53
    # define LEFT 0
    # define RIGHT 2
    # define T_RIGHT 124
    # define T_LEFT 123

# else
    # define UP 119
    # define DOWN 115
    # define LEFT 97
    # define RIGHT 100
    # define T_RIGHT 65363
    # define T_LEFT 65361
    # define ESC 65307

#endif


#endif
