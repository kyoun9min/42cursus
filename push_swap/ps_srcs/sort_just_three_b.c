/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:16:17 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/19 20:16:17 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_two_b(t_stack **b, t_op **op)
{
	if ((*b)->n < (*b)->next->n)
		get_op_list(op, "sb", NULL, b);
}

void	case_three_b(t_stack **b, t_op **op, int stack_size)
{
	int	min_value_index;

	min_value_index = get_value_index(b, get_min_value(b, stack_size));
	if (min_value_index == 0)
	{
		get_op_list(op, "rb", NULL, b);
		case_two_b(b, op);
	}
	else if (min_value_index == 1)
	{
		get_op_list(op, "rrb", NULL, b);
		case_two_b(b, op);
	}
	else
		case_two_b(b, op);
}

void	sort_just_three_b(t_stack **b, t_op **op)
{
	int	stack_size;

	stack_size = get_stack_size(b);
	if (stack_size == 2)
		case_two_b(b, op);
	else if (stack_size == 3)
		case_three_b(b, op, stack_size);
}
