/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_and_add_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:49:09 by kyounkim          #+#    #+#             */
/*   Updated: 2021/06/22 17:34:39 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	check_int_range(long long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

int	duplicate_check(t_stack **a)
{
	t_stack *a_x;
	t_stack *a_y;

	a_y = (*a);
	while (a_y != NULL)
	{
		a_x = a_y->next;
		while (a_x != NULL)
		{
			if (a_y->n == a_x->n)
				return (1);
			a_x = a_x->next;
		}
		a_y = a_y->next;
	}
	return (0);
}

int	check_argv_and_add_stack(t_stack **a, int argc, char **argv)
{
	int			i;
	long long	n;

	i = argc - 1;
	if (i == 0)
		return (1);
	while (i)
	{
		if (check_isdigit(argv[i]))
			return (1);
		n = ft_atoll(argv[i]);
		if (check_int_range(n))
			return (1);
		add_stack_front(a, create_stack((int)n));
		i--;
	}
	if (duplicate_check(a))
		return (1);
	return (0);
}