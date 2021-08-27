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
			sort_just_three_b(b, op);
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
	t_count	count;
	int		i;

	init_count(&count);
	i = 0;
	if (return_case_b(a, b, op, stack_size))
		return ;
	while (i++ < stack_size)
	{
		if ((*b)->n >= get_low_pivot(b, stack_size) && ++count.push)
		{
			get_op_list(op, "pa", a, b);
			if ((*a)->n < get_high_pivot(b, stack_size) && ++count.count_ra)
				get_op_list(op, "ra", a, b);
		}
		else if ((*b)->n < get_low_pivot(b, stack_size) && ++count.count_rb)
			get_op_list(op, "rb", a, b);
	}
	sort_main_a(a, b, op, count.push - count.count_ra);
	exe_rrr(a, b, op, count.count_ra);
	if (count.count_ra > count.count_rb)
		get_op_list(op, "rb", a, b);
	sort_main_a(a, b, op, count.count_ra);
	sort_main_b(a, b, op, stack_size - count.push);
}
