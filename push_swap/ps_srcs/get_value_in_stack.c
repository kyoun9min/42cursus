/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:50:14 by kyounkim          #+#    #+#             */
/*   Updated: 2021/07/01 19:55:59 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_value(t_stack **head, int stack_size)
{
	int *sort;
	int max_value;

	sort = get_stack_array(head, stack_size);
	quick_sort(sort, 0, stack_size - 1);
	max_value = sort(stack_size - 1);
	free(sort);
}

int	get_value_index(t_stack **head, int value)
{
	int	index;
	t_stack *node;

	index = 0;
	node = (*head);
	while (node != NULL)
	{
		if (node->n == value)
			return (index);
		node = node->next;
		index++;
	}
	return (index);
}