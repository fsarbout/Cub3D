/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .file.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:02:07 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/04 11:21:39 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	char 	*sp;
	struct	s_list *next;
}				t_list;


void  lst_add_back(t_list **head, char *spr)

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
        printf("start2\n");

        lastnode = *head;
        while ((*head)->next)
            (*head) = (*head)->next;
        (*head)->next = node;     
        *head = lastnode;
    }        
}
void    midel(t_list **lst)
{
        for (int i = 0; i < 10; i++)
    {
        lst_add_back(lst, "tst");
    }
}

int main()
{
    t_list *lst;
    lst = NULL;
    midel(&lst);
    while (lst)
    {
        printf("%s\n", (lst)->sp);
        lst = (lst)->next;
    }
    
    
}

