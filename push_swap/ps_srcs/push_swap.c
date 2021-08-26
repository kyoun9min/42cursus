/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:44:04 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/26 17:24:53 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_op	*op;
	int		stack_size;

	a = NULL;
	b = NULL;
	op = NULL;
	if (!(check_argv_and_add_stack(&a, argc, argv)))
		return (write_error());
	stack_size = get_stack_size(&a);
	if (sorted_check_a(&a, stack_size))
		return (0);
	if (stack_size <= 3)
		sort_just_three_a(&a, &op, stack_size);
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
