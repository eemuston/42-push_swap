/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:54:22 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 17:26:36 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{	
	int		i;
	int		j;
	int		k;
	int		h;

	i = 1;
	j = ft_lstsize(&(**a));
	while (is_sorted(&(*a)) == 0)
	{
		k = 0;
		while (k < j)
		{
			if ((i & (*a)->content) != i)
				push_b(&(*a), &(*b));
			else
				rotate_a(&(*a), &(*b), 0);
			k++;
		}
		h = ft_lstsize(&(**b));
		while (h-- > 0)
			push_a(&(*a), &(*b));
		i = i * 2;
	}
}
