/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:46:23 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 12:29:31 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    check_map(char *mp)
{
    int i;
    int j;
    char **map;

    i = 0;
    j = 0;
    g_dt.long_l = 0;
    g_dt.nbr_lines = 0;
    map = ft_split(mp , '\n');
    
    g_dt.nbr_lines = lenght(map);
    g_dt.mmp = NULL;
    fill_maplines(map);
    parse_map(map, i, j);
    freee(map);
    if (g_dt.plyr   == 0)
        print_error("   missing player!\n");
} 
void    player(char **map, int i, int j)
{
    if ( g_dt.mmp[i][j + 1] == 32 ||  g_dt.mmp[i][j - 1] == 32 
        ||  g_dt.mmp[i - 1][j] == 32
            ||  g_dt.mmp[i + 1][j] == 32)
        print_error("   map invalid , space next to the player!\n");
    if (g_dt.plyr == 1)
        print_error("   more than player!\n");
    g_dt.plyr = 1;
    if (map[i][j] == 'N')
        g_dt.plyr_angl = - M_PI /2;
    else if (map[i][j] == 'W') // 180
        g_dt.plyr_angl = M_PI;
    else if (map[i][j] == 'E')
        g_dt.plyr_angl = 0; // 0
    else if (map[i][j] == 'S')
        g_dt.plyr_angl = M_PI / 2;
    g_dt.pos_x = j * TILE + (TILE / 2);
    g_dt.pos_y = i * TILE + (TILE / 2);
}
void    parse_map(char **map, int i, int j)
{
    while (map[i])
    {
        j = 0;
        while (j < g_dt.long_l)
        {
            if (g_dt.mmp[i][j] != '1' && g_dt.mmp[i][j] != 32)     
                if_dif_one(map, i, j);   
            j++;
        }
        i++; 
    }
}

void    fill_maplines(char **map)
{   
    int i;
    int lenght_l;

    lenght_l = 0;
    i =0;
     while (g_dt.nbr_lines)
    {
        lenght_l = ft_strlen(map[i]);
        if (lenght_l > g_dt.long_l) 
            g_dt.long_l = lenght_l;
        i++;
        g_dt.nbr_lines--;
    }
    g_dt.nbr_lines = lenght(map);
    g_dt.mmp = (char**)malloc(g_dt.nbr_lines * sizeof(g_dt.mmp));
    if (!g_dt.mmp)
        print_error("   there is a problem in memory allocation!\n");
    i = 0;
    while (i < g_dt.nbr_lines)
    {
        g_dt.mmp[i] = (char*)malloc(g_dt.long_l * sizeof(g_dt.mmp[i]));
        ft_strlcpy1(g_dt.mmp[i], map[i] ,g_dt.long_l);
                i++;
    }
}
void    if_dif_one(char **map, int i, int j)
{
    if (i - 1 < 0 || j - 1 < 0 || i + 1 >= g_dt.nbr_lines || j + 1 >= g_dt.long_l)
        print_error("   map not surrounded by ones!\n");
    else if ( g_dt.mmp[i][j] == '0')
    {   
    if (g_dt.mmp[i][j + 1] == 32 ||  g_dt.mmp[i][j - 1] == 32 ||  g_dt.mmp[i - 1][j] == 32
        ||  g_dt.mmp[i + 1][j] == 32)
            print_error("   map invlaid, (spaces problem)!\n");
    }
    else if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' 
        || map[i][j] == 'S')
        player(map, i, j);
    else if (g_dt.mmp[i][j] == '2')
        check_sprite(i, j);
    else 
        print_error("   invalid character in the map!\n");   
}