/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:29:51 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 09:44:04 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void clear_list(t_list **lst)
{
    if (*lst)
    {
        if ((*lst)->next)
            clear_list(&(*lst)->next);
        free(*lst);
        *lst =NULL;
    }
}

void    sort_list(t_list *lst)
{
    t_list      *inside;
    t_sp        sprite;
    if (!lst)
        return;
    while (lst->next)
    {
        inside = lst->next;
        while (inside)
        {
            if (lst->sp.dist_plyr_sp < inside->sp.dist_plyr_sp)
            {
                sprite = lst->sp;
                lst->sp = inside->sp;
                inside->sp = sprite;
            }
            inside = inside->next;
        }
        lst = lst->next;
    }
}

void  lst_add_back(t_list **head, t_sp spr)
{
    t_list *node = malloc(sizeof(t_list));
    t_list *lastnode;
    node->sp = spr;
    node->next = NULL;
    if ((*head) == NULL)
        *head = node;
    else
    {
        lastnode = *head;
        while ((*head)->next)
            (*head) = (*head)->next;
        (*head)->next = node;
        *head = lastnode;
    }        
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}