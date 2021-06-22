/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:03:02 by kyounkim          #+#    #+#             */
/*   Updated: 2021/06/22 20:30:49 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_operation_list(op, "sa", a, NULL);
}

int		sort_just_three_a(t_stack **a, t_op **op, int stack_size)
{
	if (stack_size == 2)
		case_two_a(a, op);
	else if (stack_size == 3)
		case_three_a(a, op, stack_size);
	return (0);
}