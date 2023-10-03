/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:53:27 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/14 11:00:30 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a, int flag)
{
	int	temp;

	if (a->next == NULL)
	{
		return ;
	}
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *b, int flag)
{
	int	temp;

	if (b->next == NULL)
	{
		return ;
	}
	temp = b->content;
	b->content = b->next->content;
	b->next->content = temp;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	swap_a_and_b(t_stack *a, t_stack *b, int flag)
{
	flag = 1;
	swap_a(&(*a), flag);
	swap_b(&(*b), flag);
	flag = 0;
	write(1, "ss\n", 3);
}

void	reverse_rotate_a_and_b(t_stack **a, t_stack **b, int flag)
{
	flag = 1;
	reverse_rotate_a(&(*a), flag);
	reverse_rotate_b(&(*b), flag);
	flag = 0;
	write(1, "rrr\n", 4);
}
