/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:29:51 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/10 19:30:40 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
    {
        tmp = tmp->next;

    }
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
    // printf(" n h %d, s h %d\n" , node->sp.height, spr.height);
    node->next = NULL;
    // node->set_by_lab = 123;
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

// t_list* insertNodeAtTail(t_list* head, int data)
// {
//     //to create a new node
//     t_list *node = malloc(sizeof(t_list));
//     t_list *lastnode;
//     //*(lastnode)we can't work with head we're gonna use it's address;
//     node->data = data; //affect the value of node
//     //because the new node gonna be the last node
//     node->next = NULL;
      
//     if (!head) // if the list is empty the whole 
//     //list we'll be the new node
//         head = node;
//     else 
//     {
//         //start from the first node;
//             lastnode = head;
//         //looping until reaching the last node of the list
//             while (lastnode->next)
//                 lastnode = lastnode->next;
//         //add the new node at the end of list
//             lastnode->next = node;     
//     }        
//     //return the first node which has the adress of the whole list
//     //so all the element 
//     return head;
// }
