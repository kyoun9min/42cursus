/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_and_add_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:49:09 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/28 11:12:20 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	check_isdigit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		i++;
	}
	if (str[i] == '\0' && flag == 1)
		return (1);
	return (0);
}

int	check_int_range(long long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

int	check_duplication(t_stack **a)
{
	t_stack	*a_x;
	t_stack	*a_y;

	a_x = (*a);
	while (a_x != NULL)
	{
		a_y = a_x->next;
		while (a_y != NULL)
		{
			if (a_x->n == a_y->n)
				return (1);
			a_y = a_y->next;
		}
		a_x = a_x->next;
	}
	return (0);
}

int	check_argv_and_add_stack(t_stack **a, int argc, char **argv)
{
	int			i;
	long long	n;

	i = argc - 1;
	while (i)
	{
		if (!(check_isdigit(argv[i])))
			return (0);
		n = ft_atoll(argv[i]);
		if (!(check_int_range(n)))
			return (0);
		add_stack_top(a, create_stack_node((int)n));
		i--;
	}
	if (check_duplication(a))
		return (0);
	return (1);
}
