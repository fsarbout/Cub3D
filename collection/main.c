/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/30 18:40:56 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

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
    mlxs();
    perror("Error: ");
    free(g_data.mmp);
    return (0);
}