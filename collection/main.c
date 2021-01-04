/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/04 10:43:26 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

int main(int ac, char **av)
{
    char *line;
    // t_list *list;
    void    *param;

    //list = malloc(sizeof(t_list));
    // list = NULL;
    line = NULL;
    param = NULL;
    if (ac != 2)
    {
        printf("ERROR IN ARGUMENTS OF MAIN");
        return (0);
    }
    else
        collect_data(line, av);
    g_dt.numrays = g_dt.long_l * TILE ;
    // g_dt.numrays = 1 ;
    mlxs();
    // perror("Error: ");
   
    free(g_dt.mmp);
    return (0);
}


//         t_dt *data;
// # define MALLOC(p) p = malloc(sizeof(*(p)))
//         MALLOC(data);
    
//         data = malloc(sizeof(t_d
