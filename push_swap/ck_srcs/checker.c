/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:27:53 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 22:27:53 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_rr_checker(t_stack **a, t_stack **b, char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		reverse_rotate(a);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		reverse_rotate(b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\0')
	{
		rotate(a);
		rotate(b);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

int	operation_checker(t_stack **a, t_stack **b, char *s)
{
	if (s[0] == 's' && s[1] == 'a')
		swap(a);
	else if (s[0] == 's' && s[1] == 'b')
		swap(b);
	else if (s[0] == 's' && s[1] == 's')
	{
		swap(a);
		swap(b);
	}
	else if (s[0] == 'p' && s[1] == 'a')
		push(a, b);
	else if (s[0] == 'p' && s[1] == 'b')
		push(b, a);
	else if (s[0] == 'r' && s[1] == 'a')
		rotate(a);
	else if (s[0] == 'r' && s[1] == 'b')
		rotate(b);
	else if (s[0] == 'r' && s[1] == 'r')
		operation_rr_checker(a, b, s);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		stack_size;

	a = NULL;
	b = NULL;
	if (!(check_argv_and_add_stack(&a, argc, argv)))
		return (write_error());
	stack_size = get_stack_size(&a);
	while (get_next_line(&line) > 0)
	{
		if (!(operation_checker(&a, &b, line)))
			return (write_error());
		free(line);
	}
	operation_checker(&a, &b, line);
	free(line);
	if (sorted_check_a(&a, stack_size) && (b == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	return (0);
}
