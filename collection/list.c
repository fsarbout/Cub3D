/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:29:51 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/04 11:32:22 by fsarbout         ###   ########.fr       */
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

t_list  *newlst(t_sp sp)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->sp = sp;
    new->next = NULL;
    return (new);
}

void  lst_add_back(t_list **head, t_sp spr)
{
    t_list *node = malloc(sizeof(t_list));
    t_list *lastnode;
    node->sp = spr;
    node->next = NULL;
    if ((*head) == NULL)
    {
        //printf("start %d\n", spr.x);
        *head = node;
        //printf("start\n");
    }
    else 
    {
        // printf("start2\n");

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
