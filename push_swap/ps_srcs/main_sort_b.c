/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:19:23 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/23 13:19:23 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **a, t_stack **b, t_op **op,
	int stack_size, int *push, int *count_ra, int *count_rb)
{
	int	h_pivot;
	int	l_pivot;
	int	i;

	h_pivot = get_highvalue_pivot(b, stack_size);
	l_pivot = get_lowvalue_pivot(b, stack_size);
	i = 0;
	while (i++ < stack_size)
	{
		if ((*b)->n >= l_pivot)
		{
			get_op_list(op, "pa", a, b);
			(*push)++;
			if ((*a)->n < h_pivot)
			{
				get_op_list(op, "ra", a, b);
				(*count_ra)++;
			}
		}
		else
		{
			get_op_list(op, "rb", a, b);
			(*count_rb)++;
		}
	}
}

int	return_case_b(t_stack **a, t_stack **b, t_op **op, int stack_size)
{
	int	i;

	i = 0;
	if (sorted_check_b(b, stack_size))
	{
		while (stack_size--)
			get_op_list(op, "pa", a, b);
		return (1);
	}
	if (stack_size <= 3)
	{
		if (stack_size == get_stack_size(b))
			sort_just_three_b(b, op, stack_size);
		else
			size_discord_b(b, op, stack_size);
		while (i++ < stack_size)
			get_op_list(op, "pa", a, b);
		return (1);
	}
	return (0);
}

void	sort_main_b(t_stack **a, t_stack **b, t_op **op, int stack_size)
{
	int	*push;
	int	*count_ra;
	int	*count_rb;
	int	i;

	*push = 0;
	*count_ra = 0;
	*count_rb = 0;
	i = 0;
	if (return_case_b(a, b, op, stack_size))
		return ;
	sort(a, b, op, stack_size, push, count_ra, count_rb);
	sort_main_a(a, b, op, *push - *count_ra);
	while (i++ < *count_ra)
		get_op_list(op, "rrr", a, b);
	if (*count_ra > *count_rb)
			get_op_list(op, "rb", a, b);
	sort_main_a(a, b, op, *count_ra);
	sort_main_b(a, b, op, stack_size - *push);
}
