/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:18:28 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 17:17:47 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, t_stack **b, int flag)
{
	int	temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->content;
	ft_lstdelone(&(*a));
	insert(&(*a), &(*b), temp);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b, t_stack **a, int flag)
{
	int	temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->content;
	ft_lstdelone(&(*b));
	insert(&(*b), &(*a), temp);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rotate_a_and_b(t_stack **a, t_stack **b, int flag)
{
	flag = 1;
	rotate_a(&(*a), &(*b), flag);
	rotate_b(&(*b), &(*a), flag);
	flag = 0;
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack **a, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *a;
	*a = last;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *b;
	*b = last;
	if (flag == 0)
		write(1, "rrb\n", 4);
}
