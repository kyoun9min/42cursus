/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:03:02 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/23 11:44:34 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_op_list(op, "sa", a, NULL);
}

void	case_three_a(t_stack **a, t_op **op, int stack_size)
{
	int	max_value_index;

	max_value_index = get_value_index(a, get_max_value(a, stack_size));
	if (max_value_index == 0)
	{
		get_op_list(op, "ra", a, NULL);
		case_two_a(a, op);
	}
	else if (max_value_index == 1)
	{
		get_op_list(op, "rra", a, NULL);
		case_two_a(a, op);
	}
	else
		case_two_a(a, op);
}

void	sort_just_three_a(t_stack **a, t_op **op, int stack_size)
{
	if (stack_size == 2)
		case_two_a(a, op);
	else if (stack_size == 3)
		case_three_a(a, op, stack_size);
}
