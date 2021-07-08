/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:13:33 by kyounkim          #+#    #+#             */
/*   Updated: 2021/07/08 19:43:27 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	int	temp;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if ((*src) != NULL)
	{
		temp = (*src)->next;
		add_stack_top(dest, *src);
		(*src) = temp;
	}
}

void	rotate(t_stack **head)
{
	t_stack	*temp;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		temp = (*head);
		(*head) = (*head)->next;
		temp->next = NULL;
		add_stack_bottom(head, temp);
	}
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*last;

	temp = (*head);
	if ((*head) != NULL && (*head)->next != NULL)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		add_stack_top(head, last);
	}
}
