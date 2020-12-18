/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/15 17:13:55 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"
#include <float.h>

int main(int ac, char **av)
{
    printf("number of arguments = %d\n", ac);
    char *line;
    void    *param;

    line = NULL;
    param = NULL;
    if (ac != 2)
    {
        printf("ERROR IN ARGUMENTS OF MAIN");
        return (0);
    }
    else
        collect_data(line, av);
    // g_dt.numrays =  g_dt.rsltn_w / WALL_S_W;
    g_dt.numrays = g_dt.long_l * TILE ;
    mlxs();
    perror("Error: ");
    free(g_dt.mmp);
    return (0);
}


//         t_dt *data;
// # define MALLOC(p) p = malloc(sizeof(*(p)))
//         MALLOC(data);
    
//         data = malloc(sizeof(t_d
