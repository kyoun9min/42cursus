/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:00:35 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 22:00:35 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*i;
	t_stack	*temp;

	i = (*a);
	while (i != NULL)
	{
		temp = i;
		i = i->next;
		free(temp);
	}
	(*a) = NULL;
}

void	free_operation(t_op **op)
{
	t_op	*i;
	t_op	*temp;

	i = (*op);
	while (i != NULL)
	{
		temp = i;
		i = i->next;
		free(temp->s);
		free(temp);
	}
	(*op) = NULL;
}
