/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_discord_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:33:49 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 14:33:49 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	size_discord_case_two_b(t_stack **b, t_op **op)
{
	if ((*b)->n < (*b)->next->n)
		get_op_list(op, "sb", NULL, b);
}

void	common_op_case_three_b(t_stack **b, t_op **op)
{
	get_op_list(op, "rb", NULL, b);
	get_op_list(op, "sb", NULL, b);
	get_op_list(op, "rrb", NULL, b);
	size_discord_case_two_b(b, op);
}

void	size_discord_case_three_b(t_stack **b, t_op **op, int stack_size)
{
	int	min_value_index;

	min_value_index = get_value_index(b, get_min_value(b, stack_size));
	if (min_value_index == 0)
	{
		get_op_list(op, "sb", NULL, b);
		common_op_case_three_b(b, op);
	}
	else if (min_value_index == 1)
		common_op_case_three_b(b, op);
	else
		size_discord_case_two_b(b, op);
}

void	size_discord_b(t_stack **b, t_op **op, int stack_size)
{
	if (stack_size == 2)
		size_discord_case_two_b(b, op);
	else if (stack_size == 3)
		size_discord_case_three_b(b, op, stack_size);
}
