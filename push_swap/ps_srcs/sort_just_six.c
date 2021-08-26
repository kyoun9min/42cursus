/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:33:24 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/19 16:33:24 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_just_six(t_stack **a, t_stack **b, t_op **op, int stack_size)
{
	int	mid;
	int	i;
	int	count_pb;

	mid = get_mid_value(a, stack_size);
	i = 0;
	count_pb = 0;
	while (i < stack_size)
	{
		if ((*a)->n < mid)
		{
			get_op_list(op, "pb", a, b);
			count_pb++;
		}
		else
			get_op_list(op, "ra", a, b);
		i++;
	}
	sort_just_three_a(a, op, stack_size);
	sort_just_three_b(b, op, stack_size);
	while (count_pb--)
		get_op_list(op, "pa", a, b);
}
