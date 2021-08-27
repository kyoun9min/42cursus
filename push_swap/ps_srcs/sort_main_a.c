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

int	return_case_a(t_stack **a, t_op **op, int stack_size)
{
	if (sorted_check_a(a, stack_size))
		return (1);
	if (stack_size <= 3)
	{
		if (stack_size == get_stack_size(a))
			sort_just_three_a(a, op);
		else
			size_discord_a(a, op, stack_size);
		return (1);
	}
	return (0);
}

void	sort_main_a(t_stack **a, t_stack **b, t_op **op, int stack_size)
{
	t_count	count;
	int		i;

	init_count(&count, a, stack_size);
	i = 0;
	if (return_case_a(a, op, stack_size))
		return ;
	while (i++ < stack_size)
	{
		if ((*a)->n < count.h_pivot && ++count.push)
		{
			get_op_list(op, "pb", a, b);
			if ((*b)->n >= count.l_pivot && ++count.count_rb)
				get_op_list(op, "rb", NULL, b);
		}
		else if ((*a)->n >= count.h_pivot && ++count.count_ra)
			get_op_list(op, "ra", a, NULL);
	}
	exe_rrr(a, b, op, count.count_ra);
	exe_rb(b, op, count.count_ra, count.count_rb);
	sort_main_a(a, b, op, count.count_ra);
	sort_main_b(a, b, op, count.count_rb);
	sort_main_b(a, b, op, count.push - count.count_rb);
}
