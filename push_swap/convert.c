/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:50:23 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 18:11:08 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_count(t_stack **a, int num)
{
	int		i;
	t_stack	*temp;

	temp = *a;
	i = 0;
	while (temp != NULL)
	{
		if (temp->content < num)
			i++;
		temp = temp->next;
	}
	return (i);
}

void	convert_to_smaller(t_stack **a, t_stack **b)
{
	t_stack	*new;
	t_stack	*temp;

	temp = *a;
	new = NULL;
	while (temp != NULL)
	{
		insert(&new, &(*b), smaller_count(&(*a), (temp)->content));
		temp = (temp)->next;
	}
	radix_sort(&new, b);
	free_and_delete_lst(&new);
}
