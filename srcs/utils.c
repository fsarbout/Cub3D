/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:41:17 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/06 09:02:36 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     lenght(char **str)
{
    int n;

    n = 0;
    while (str[n])
        n++;
    return(n);
}

int    str_of_num(char *str)
{   
    int i;

    i = 0;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}

// void swap(float a, float b) 
// { 
//     float temp ;
//     temp = a; 
//     a = b; 
//     b = temp; 
// }
// void   sort_sprites(float  distance)
// {
    



// }
