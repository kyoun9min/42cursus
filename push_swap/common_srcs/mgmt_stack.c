/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgmt_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:57:11 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/23 13:08:03 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack_node(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->n = n;
	node->next = NULL;
	return (node);
}

int	get_stack_size(t_stack **head)
{
	t_stack	*node;
	int		size;

	node = (*head);
	size = 0;
	if (node == NULL)
		return (0);
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}

void	add_stack_top(t_stack **head, t_stack *new_node)
{
	new_node->next = (*head);
	(*head) = new_node;
}

void	add_stack_bottom(t_stack **head, t_stack *new_node)
{
	t_stack	*node;

	node = (*head);
	if ((*head) == NULL)
		(*head) = node;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = node;
	}
}
