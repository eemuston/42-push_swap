/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:18:57 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/16 12:02:25 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack	t_stack;
struct		s_stack
{
	int					content;
	t_stack				*next;
	t_stack				*previous;
};

void	insert(t_stack **sptr, t_stack **otherlst, int value);
int		ft_atoi(const char *n);
void	swap_a(t_stack *a, int flag);
void	swap_b(t_stack *b, int flag);
void	swap_a_and_b(t_stack *a, t_stack *b, int flag);
void	ft_lstadd_front(t_stack **lst, t_stack **otherlst, int element);
void	ft_lstdelone(t_stack **lst);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a, t_stack **b, int flag);
void	rotate_b(t_stack **b, t_stack **a, int flag);
void	rotate_a_and_b(t_stack **a, t_stack **b, int flag);
void	reverse_rotate_a(t_stack **a, int flag);
void	reverse_rotate_b(t_stack **b, int flag);
void	reverse_rotate_a_and_b(t_stack **a, t_stack **b, int flag);
int		check_duplicates(t_stack **a);
int		is_sorted(t_stack **a);
int		ft_lstsize(t_stack *lst);
void	sort_small_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a, t_stack **b);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	swap_and_rotate_a(t_stack **a, t_stack **b);
void	rotate_and_swap_a(t_stack **a, t_stack **b);
int		ra_or_rra(t_stack **a, int value);
int		min_value(t_stack *list);
int		check_errors(t_stack **a);
size_t	wd_counter(const char *s, char c);
char	**str_to_stack(t_stack **a, t_stack **b, char *str, int num);
int		valid_arg(char *str);
int		valid_arg_array(char **array, int num);
void	convert_to_smaller(t_stack **a, t_stack **b);
int		smaller_count(t_stack **a, int num);
void	radix_sort(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
int		get_stack(t_stack **a, t_stack **b, int argc, char **argv);
void	free_and_delete_lst(t_stack **lst);
long	my_atoi(const char *n);
void	free_array(char **array, int num);

#endif