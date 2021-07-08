/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:47:20 by kyounkim          #+#    #+#             */
/*   Updated: 2021/07/08 19:39:19 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted_check_a(t_stack **a)
{
	t_stack	*node;
	int		pre_node_n;

	node = (*a)->next;
	pre_node_n = (*a)->n;
	while (node != NULL)
	{
		if (pre_node_n < node->n)
			pre_node_n = node->n;
		else
			return (0);
		node = node->next;
	}
	return (1);
}

int	sorted_check_b(t_stack **b, int len)
{
	t_stack	*node;
	int		pre_node_n;

	node = (*b)->next;
	pre_node_n = (*b)->n;
	while (node != NULL)
	{
		if (pre_node_n > node->n)
			pre_node_n = node->n;
		else
			return (0);
		node = node->next;
	}
	return (1);
}
