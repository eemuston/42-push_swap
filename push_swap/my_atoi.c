/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:12:30 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/15 16:45:43 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(const char *n)
{
	unsigned long long	r;
	int					s;
	int					i;

	r = 0;
	s = 1;
	i = 0;
	while ((n[0] >= 9 && n[0] <= 13) || n[0] == 32)
		n++;
	if (n[0] == 45)
		s *= -1;
	if (n[0] == 45 || n[0] == 43)
		n++;
	while (n[0] == '0')
		n++;
	while (n[i] >= 48 && n[i] <= 57 && n[i] != '\0')
	{
		r = r * 10 + n[i++] - 48;
	}
	if (r < (unsigned long long)-2147483648 && r > 2147483648)
		return (2147483648);
	return (r * s);
}
