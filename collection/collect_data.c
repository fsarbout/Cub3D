/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:00:26 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/09 00:16:30 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

 void   collect_data(char *line, char **av)
{
    char **element;
    int fd;
    char *map;
    int i;

    i = 0;
    map = "";
    line = NULL; 
    struct_intialize();
    if (!(fd = open(av[1], O_RDONLY)))
        print_error(9);
    while (get_next_line(fd, &line) && i < 7)
    {  
        i++;
        while (line[0] == '\0')
                get_next_line(fd, &line);
        if (line[0] == 32)
                print_error(9);
        element = ft_split(line, ' ');
        check_elements(element);
    }
    if (i != 7)
        print_error(10);
     che_ck_map(i, fd, line, map);
     printf("collect data working\n");
}   
void    che_ck_map(int i, int fd, char *line, char *map)
{
    int j;

    j = 0;
    i = 1;
    while (i)
    {
        i = get_next_line(fd, &line);
        if (*line == '\0')
        {
            if (j == 1)
                print_error(2);
            continue;
        }
        map = ft_strjoin(map , "\n");
        j = 1;
        map = ft_strjoin(map ,line);
    }
    check_map(map);
    printf("working well\n");
}
void    check_elements(char **element)
{
        if (!ft_strcmp(element[0], "R"))
            treat_rsltn(element);
        else if (!ft_strcmp(element[0], "NO"))
            treat_north(element);
        else if (!ft_strcmp(element[0], "SO"))
            treat_south(element);
        else if (!ft_strcmp(element[0], "WE"))
            treat_west(element);
        else if (!ft_strcmp(element[0], "EA"))
            treat_east(element);
        else if (!ft_strcmp(element[0], "F"))
            treat_flr(element);
        else if (!ft_strcmp(element[0], "C"))
            treat_cllng(element);
        else 
            print_error(10);
}