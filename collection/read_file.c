/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 00:14:05 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/21 03:04:56 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
        print_error("   invlid file\n");
    while (get_next_line(fd, &line) && i < 8)
    {  
        i++;
        while (line[0] == '\0')
                get_next_line(fd, &line);
        if (line[0] == 32)
                print_error("   spaces in an empty line!\n");
        element = ft_split(line, ' ');
        check_elements(element);
    }
    if (i != 8)
        print_error("   wrong number of elements!\n");
     che_ck_map(i, fd, line, map);
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
                print_error("   map separated or ended by  new line(s)!\n");
            continue;
        }
        map = ft_strjoin(map , "\n");
        j = 1;
        map = ft_strjoin(map ,line);
    }
    check_map(map);
    printf("working well\n");
}

int check_txt_name(char **element, char *txt, int flag)
{
    if (!ft_strncmp(element[0], txt , 3) && (lenght(element) == 2) && !flag)
        return 1;
    return 0;
}

void    check_elements(char **element)
{  
    if (check_txt_name(element, "NO", g_dt.n))
        treat_txt(element, &g_txt.no_txt, &g_dt.n);
    else if (check_txt_name(element, "EA", g_dt.e))
        treat_txt(element, &g_txt.ea_txt, &g_dt.e);
    else if (check_txt_name(element, "WE", g_dt.w))
        treat_txt(element, &g_txt.we_txt, &g_dt.w);
    else if (check_txt_name(element, "SO", g_dt.so))
         treat_txt(element, &g_txt.so_txt, &g_dt.so);  
    else if (!ft_strncmp(element[0], "R" , 2) && (lenght(element) == 3) 
        && !g_dt.r)
        treat_rsltn(element);
    else if (!ft_strncmp(element[0], "F" , 2) && (lenght(element) == 2)
        && !g_dt.f )
        treat_flr(element);
    else if (!ft_strncmp(element[0], "C" , 2) && (lenght(element) == 2)
        && !g_dt.c)
        treat_cllng(element);
    else if (!ft_strncmp(element[0] , "S" , 2) && (lenght(element) == 2))
        treat_sprite(element);
    else
        print_error("  wrong element!\n");
}

void    treat_txt(char **element_data, void **img, int *flag)
{
    *flag = 1;
    if (!(*img = (int*)mlx_xpm_file_to_image(g_dt.mlx, element_data[1]
    ,&g_dt.width, &g_dt.height)))
        print_error("   texture path invalid\n");
}