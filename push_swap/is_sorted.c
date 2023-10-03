/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:24:26 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/14 10:22:31 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = -2147483648;
	while (temp != NULL)
	{
		if (temp->content < i)
			return (0);
		i = temp->content;
		temp = temp->next;
	}
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	int			i;
	t_stack		*temp;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ra_or_rra(t_stack **a, int value)
{
	t_stack	*temp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	temp = *a;
	while (temp != NULL)
	{
		if (temp->content == value)
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
				k++;
			}
		}
		temp = temp->next;
		j++;
	}
	if (j <= k)
		return (0);
	return (1);
}

int	min_value(t_stack *list)
{
	int		min;
	t_stack	*temp;

	temp = list;
	min = 2147483647;
	while (temp != NULL)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}
