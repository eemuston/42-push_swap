/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:13:31 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 17:24:54 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_and_rotate_a(t_stack **a, t_stack **b)
{
	swap_a(&(**a), 0);
	rotate_a(&(*a), &(*b), 0);
}

void	rotate_and_swap_a(t_stack **a, t_stack **b)
{
	rotate_a(&(*a), &(*b), 0);
	swap_a(&(**a), 0);
}
