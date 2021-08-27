/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_discord_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:52:36 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 16:52:36 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	size_discord_case_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_op_list(op, "sa", a, NULL);
}

void	common_op_case_three_a(t_stack **a, t_op **op)
{
	get_op_list(op, "ra", a, NULL);
	get_op_list(op, "sa", a, NULL);
	get_op_list(op, "rra", a, NULL);
	size_discord_case_two_a(a, op);
}

void	size_discord_case_three_a(t_stack **a, t_op **op, int stack_size)
{
	int	max_value_index;

	max_value_index = get_value_index(a, get_max_value(a, stack_size));
	if (max_value_index == 0)
	{
		get_op_list(op, "sa", a, NULL);
		common_op_case_three_a(a, op);
	}
	else if (max_value_index == 1)
		common_op_case_three_a(a, op);
	else
		size_discord_case_two_a(a, op);
}

void	size_discord_a(t_stack **a, t_op **op, int stack_size)
{
	if (stack_size == 2)
		size_discord_case_two_a(a, op);
	else if (stack_size == 3)
		size_discord_case_three_a(a, op, stack_size);
}
