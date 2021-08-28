/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:44:04 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/28 12:02:06 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_op	*op;
	int		stack_size;

	init_stack_op(&a, &b, &op);
	if (!(check_argv_and_add_stack(&a, argc, argv)))
		return (write_error());
	stack_size = get_stack_size(&a);
	if (sorted_check_a(&a, stack_size))
		return (0);
	if (stack_size <= 3)
		sort_just_three_a(&a, &op);
	else if (stack_size <= 6)
		sort_just_six(&a, &b, &op, stack_size);
	else
		sort_main_a(&a, &b, &op, stack_size);
	minimize_op_list(&op);
	print_op_list(&op);
	free_stack(&a);
	free_operation(&op);
	return (0);
}
