/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:27:17 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/23 12:27:17 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **a, t_stack **b, t_op **op,
	int stack_size, int *push, int *count_ra, int *count_rb)
{
	int	h_pivot;
	int	l_pivot;
	int	i;

	h_pivot = get_highvalue_pivot(a, stack_size);
	l_pivot = get_lowvalue_pivot(a, stack_size);
	i = 0;
	while (i++ < stack_size)
	{
		if ((*a)->n < h_pivot)
		{
			get_op_list(op, "pb", a, b);
			(*push)++;
			if ((*b)->n >= l_pivot)
			{
				get_op_list(op, "rb", a, b);
				(*count_rb)++;
			}
		}
		else
		{
			get_op_list(op, "ra", a, b);
			(*count_ra)++;
		}
	}
}

int	return_case_a(t_stack **a, t_stack **b, t_op **op, int stack_size)
{
	if (sorted_check_a(a, stack_size))
		return (1);
	if (stack_size <= 3)
	{
		if (stack_size == get_stack_size(a))
			sort_just_three_a(a, op, stack_size);
		else
			size_discord_a(a, op, stack_size);
		return (1);
	}
	return (0);
}

void	sort_main_a(t_stack **a, t_stack **b, t_op **op, int stack_size)
{
	int	*push;
	int	*count_ra;
	int	*count_rb;
	int	i;

	*push = 0;
	*count_ra = 0;
	*count_rb = 0;
	i = 0;
	if (return_case_a(a, b, op, stack_size))
		return ;
	sort(a, b, op, stack_size, push, count_ra, count_rb);
	while (i++ < *count_ra)
		get_op_list(op, "rrr", a, b);
	if (*count_ra > *count_rb)
			get_op_list(op, "rb", a, b);
	sort_main_a(a, b, op, stack_size - *push);
	sort_main_b(a, b, op, *count_rb);
	sort_main_b(a, b, op, push - *count_rb);
}
