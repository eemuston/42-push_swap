/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:36:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/16 12:01:24 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**str_to_stack(t_stack **a, t_stack **b, char *str, int num)
{
	char	**array;
	int		i;
	int		k;

	array = ft_split(str, ' ');
	i = 0;
	k = num;
	while (num > 0)
	{
		insert(&(*a), &(*b), ft_atoi(array[i]));
		num--;
		i++;
	}
	return (array);
}

int	check_duplicates(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;

	temp1 = *a;
	temp2 = *a;
	i = 0;
	while (temp1 != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp1->content == temp2->content)
			{
				i++;
				if (i > 1)
					return (1);
			}
			temp2 = temp2->next;
		}
		i = 0;
		temp1 = temp1->next;
		temp2 = *a;
	}
	return (0);
}

int	valid_arg_array(char **array, int num)
{
	int		i;
	char	*str;

	i = 0;
	while (i < num)
	{
		str = array[i];
		if (wd_counter(str, ' ') == 1)
		{
			if (valid_arg(str) == 1)
			{
				free_array(array, num);
				return (1);
			}
		}
		i++;
	}
	free_array(array, num);
	return (0);
}

int	valid_arg(char *str)
{
	char	**array;
	int		i;

	i = 0;
	if (wd_counter(str, ' ') > 1)
		array = ft_split(str, ' ');
	if (wd_counter(str, ' ') == 1)
	{
		if ((str[0] == '-' || str[0] == '+') && str[1] >= '0' && str[1] <= '9')
			i++;
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9' )
				i++;
			else
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
	}
	else if (wd_counter(str, ' ') > 1)
		return (valid_arg_array(array, wd_counter(str, ' ')));
	return (0);
}

int	check_errors(t_stack **a)
{
	if (check_duplicates(&(*a)) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
