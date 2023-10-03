/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:18:01 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/16 12:06:28 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = wd_counter(argv[i], ' ');
		if (valid_arg(argv[i]) == 1)
			return (-1);
		if (wd_counter(argv[i], ' ') > 1)
			free_array(str_to_stack(&(*a), &(*b), argv[i], k), k);
		else
			insert(&(*a), &(*b), ft_atoi(argv[i]));
		if (check_errors(&(*a)) == 1)
			return (-1);
		if (my_atoi(argv[i]) == 2147483648)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (is_sorted(&(*a)) == 1)
		return ;
	if (ft_lstsize(&(**a)) < 6)
		sort_small_stack(&(*a), &(*b));
	else if (ft_lstsize(&(**a)) > 5)
		convert_to_smaller(&(*a), &(*b));
}

int	main(int argc, char **argv)
{
	t_stack		*startpointer;
	t_stack		*bstart;

	startpointer = NULL;
	bstart = NULL;
	if (argc < 2)
		return (0);
	if (get_stack(&startpointer, &bstart, argc, argv) == -1)
	{
		free_and_delete_lst(&startpointer);
		free_and_delete_lst(&bstart);
		return (-1);
	}
	sort_stack(&startpointer, &bstart);
	free_and_delete_lst(&startpointer);
	free_and_delete_lst(&bstart);
	return (0);
}
