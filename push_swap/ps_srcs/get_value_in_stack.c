/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:50:14 by kyounkim          #+#    #+#             */
/*   Updated: 2021/07/08 19:53:03 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*get_stack_array(t_stack **head, int stack_size)
{
	int		i;
	int		*arr;
	t_stack	*node;

	arr = (int *)malloc(sizeof(int) * stack_size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	node = (*head);
	while (i < stack_size)
	{
		arr[i] = node->n;
		node = node->next;
		i++;
	}
	return (arr);
}

int	get_mid_value(t_stack **head, int stack_size)
{
	int	*arr;
	int	mid_value;

	arr = get_stack_array(head, stack_size);
	quick_sort(arr, 0, stack_size - 1);
	mid_value = arr[stack_size / 2];
	free(arr);
	retrun (mid_value);
}

int	get_min_value(t_stack **head, int stack_size)
{
	int	*arr;
	int	min_value;

	arr = get_stack_array(head, stack_size);
	quick_sort(arr, 0, stack_size - 1);
	min_value = arr[0];
	free(arr);
	return (min_value);
}

int	get_max_value(t_stack **head, int stack_size)
{
	int	*arr;
	int	max_value;

	arr = get_stack_array(head, stack_size);
	quick_sort(arr, 0, stack_size - 1);
	max_value = arr[stack_size - 1];
	free(arr);
	return (max_value);
}

int	get_value_index(t_stack **head, int value)
{
	int		index;
	t_stack	*node;

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
