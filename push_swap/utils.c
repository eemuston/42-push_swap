/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:04:54 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 19:07:54 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack **otherlst, int element)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_and_delete_lst(lst);
		free_and_delete_lst(otherlst);
		exit(1);
	}
	new->content = element;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack **lst)
{
	t_stack	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	free(temp);
}

void	insert(t_stack **sptr, t_stack **otherlst, int value)
{
	t_stack	*newelem;
	t_stack	*currentptr;

	newelem = malloc(sizeof(t_stack));
	if (!newelem)
	{
		free_and_delete_lst(sptr);
		free_and_delete_lst(otherlst);
		exit(1);
	}
	newelem->content = value;
	newelem->next = NULL;
	currentptr = *sptr;
	if (newelem)
	{
		if (currentptr == NULL)
			*sptr = newelem;
		else
		{
			while (currentptr->next != NULL)
				currentptr = currentptr->next;
			currentptr->next = newelem;
		}
	}
}

void	free_and_delete_lst(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = temp->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	free_array(char **array, int num)
{
	while (num >= 0)
	{
		free(array[num]);
		num--;
	}	
	free(array);
}
