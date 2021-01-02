/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .linked_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:13:10 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/01 16:47:20 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_list  *lst_add_back(t_list **head, t_sp spr)
{
    t_list *node = malloc(sizeof(t_list));
    t_list *lastnode;
    node->sp = spr;
    node->next = NULL;

    if (!head)
        head = node;
    else 
    {
        lastnode = head;
        while (lastnode->next)
            lastnode = lastnode->next;
        lastnode->next = node;     
    }        
    return head;
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
