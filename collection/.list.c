/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .list.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:29:51 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/30 14:56:33 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void append(t_list **lst, t_sp sp)
{
    t_list      *tmp;

    if (!(*lst))
    {
        *lst = malloc(sizeof(t_list));
        (*lst)->sp = sp;
        (*lst)->next = NULL;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(t_list));
    tmp->next->sp = sp;
    tmp->next->next = NULL;
}

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