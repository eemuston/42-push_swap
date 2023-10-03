/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:14 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:58 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	int	value;

	value = min_value(&(**a));
	while ((*a)->content != value)
	{
		if (ra_or_rra(&(*a), value) == 0)
			rotate_a(&(*a), &(*b), 0);
		else
			reverse_rotate_a(&(*a), 0);
	}
	push_b(&(*a), &(*b));
	value = min_value(&(**a));
	while ((*a)->content != value)
	{
		if (ra_or_rra(&(*a), value) == 0)
			rotate_a(&(*a), &(*b), 0);
		else
			reverse_rotate_a(&(*a), 0);
	}
	push_b(&(*a), &(*b));
	sort_three(&(*a), &(*b));
	push_a(&(*a), &(*b));
	push_a(&(*a), &(*b));
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	value;

	value = min_value(&(**a));
	if (ra_or_rra(&(*a), value) == 0)
	{
		while ((*a)->content != value)
			rotate_a(&(*a), &(*b), 0);
		push_b(&(*a), &(*b));
		sort_three(&(*a), &(*b));
		push_a(&(*a), &(*b));
	}
	else
	{
		while ((*a)->content != value)
			reverse_rotate_a(&(*a), 0);
		push_b(&(*a), &(*b));
		sort_three(&(*a), &(*b));
		push_a(&(*a), &(*b));
	}
}

void	sort_three(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->content;
	j = (*a)->next->content;
	k = (*a)->next->next->content;
	if (i < j && j > k)
	{
		if (i < k)
			swap_and_rotate_a(&(*a), &(*b));
		else
			reverse_rotate_a(&(*a), 0);
	}
	else if (i > j && j < k)
	{
		if (i < k)
			swap_a(&(**a), 0);
		else
			rotate_a(&(*a), &(*b), 0);
	}
	else if (i > j && j > k)
		rotate_and_swap_a(&(*a), &(*b));
}

void	sort_small_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(&(**a)) == 2)
		swap_a(&(**a), 0);
	else if (ft_lstsize(&(**a)) == 3)
		sort_three(&(*a), &(*b));
	else if (ft_lstsize(&(**a)) == 4)
		sort_four(&(*a), &(*b));
	else if (ft_lstsize(&(**a)) == 5)
		sort_five(&(*a), &(*b));
}
