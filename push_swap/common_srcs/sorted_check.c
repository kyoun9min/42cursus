/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:47:20 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/19 20:15:49 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted_check_a(t_stack **a, int stack_size)
{
	t_stack	*node;
	int		pre_node_n;
	int		i;

	node = (*a)->next;
	pre_node_n = (*a)->n;
	i = 0;
	while (i < stack_size)
	{
		if (pre_node_n < node->n)
			pre_node_n = node->n;
		else
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	sorted_check_b(t_stack **b, int stack_size)
{
	t_stack	*node;
	int		pre_node_n;
	int		i;

	node = (*b)->next;
	pre_node_n = (*b)->n;
	i = 0;
	while (i < stack_size)
	{
		if (pre_node_n > node->n)
			pre_node_n = node->n;
		else
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
