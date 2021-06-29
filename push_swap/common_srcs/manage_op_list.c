/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_op_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:09:46 by kyounkim          #+#    #+#             */
/*   Updated: 2021/06/29 16:08:59 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_op	*create_op_list_node(char *s)
{
	t_op	*node;

	node = (t_op *)malloc(sizeof(t_op));
	node->s = ft_strdup(s);
	node->next = NULL;
	return (node);
}

void	add_op_list_front(t_op **head, t_op *new_node)
{
	new_node->next = (*head);
	(*head) = new_node;
}

void	add_op_list_back(t_op ** head, t_op *new_node)
{
	t_op	*node;

	node = (*head);
	if (node == NULL)
		(*head) = new_node;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new_node;
	}
}

void	add_op_list_middle(t_op **head, t_op *new_node , int n)
{
	t_op	*node;
	t_op	*temp;

	node = (*head);
	if (n == 1)
	{
		add_op_list_front(head, new_node);
		return ;
	}
	n = n - 2;
	while (n--)
		node = node->next;
	temp = node->next;
	node->next = new_node;
	new_node->next = temp;
}

void	del_op_list(t_op **head, int n)
{
	t_op	*node;
	t_op	*temp;

	node = (*head);
	if (n == 1)
	{
		(*head) = (*head)->next;
		free(node->s);
		free(node);
		return ;
	}
	n = n - 2;
	while (n--)
		node = node->next;
	temp = node->next;
	node->next = temp->next;
	free(temp->s);
	free(temp);
}