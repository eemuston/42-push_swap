/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:11:09 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 17:16:16 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	ft_lstadd_front(&(*a), &(*b), (*b)->content);
	ft_lstdelone(&(*b));
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	ft_lstadd_front(&(*b), &(*a), (*a)->content);
	ft_lstdelone(&(*a));
	write(1, "pb\n", 3);
}
