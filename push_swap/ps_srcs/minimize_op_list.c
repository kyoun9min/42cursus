/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_op_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:18:22 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 19:18:22 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_merge_case(t_op *op)
{
	if (ft_strcmp(op->s, "ra") && ft_strcmp(op->next->s, "rb"))
		return (1);
	if (ft_strcmp(op->s, "rb") && ft_strcmp(op->next->s, "ra"))
		return (1);
	if (ft_strcmp(op->s, "rra") && ft_strcmp(op->next->s, "rrb"))
		return (2);
	if (ft_strcmp(op->s, "rrb") && ft_strcmp(op->next->s, "rra"))
		return (2);
}

int	get_merge_operation(t_op **op)
{
	t_op	*i;
	t_op	*new;
	int		index;
	int		merge_case;

	i = (*op);
	index = 0;
	while (i->next != NULL)
	{
		if (merge_case = get_merge_case(i))
		{
			del_op_list(op, index);
			del_op_list(op, index);
			if (merge_case == 1)
				new = create_op_list_node("rr");
			if (merge_case == 2)
				new = create_op_list_node("rrr");
			add_op_list_middle(op, new, index);
			return (1);
		}
		else
			i = i->next;
		index++;
	}
	return (0);
}

int	get_delete_case(t_op *op)
{
	if (ft_strcmp(op->s, "pa") && ft_strcmp(op->next->s, "pb"))
		return (1);
	if (ft_strcmp(op->s, "pb") && ft_strcmp(op->next->s, "pa"))
		return (1);
	if (ft_strcmp(op->s, "ra") && ft_strcmp(op->next->s, "rra"))
		return (1);
	if (ft_strcmp(op->s, "rra") && ft_strcmp(op->next->s, "ra"))
		return (1);
	if (ft_strcmp(op->s, "rb") && ft_strcmp(op->next->s, "rrb"))
		return (1);
	if (ft_strcmp(op->s, "rrb") && ft_strcmp(op->next->s, "rb"))
		return (1);
	if (ft_strcmp(op->s, "sa") && ft_strcmp(op->next->s, "sa"))
		return (1);
	if (ft_strcmp(op->s, "sb") && ft_strcmp(op->next->s, "sb"))
		return (1);
}

int	get_delete_operation(t_op **op)
{
	t_op	*i;
	int		index;

	i = (*op);
	index = 0;
	while (i->next != NULL)
	{
		if (get_delete_case(i))
		{
			i = i->next->next;
			del_op_list(op, index);
			del_op_list(op, index);
			return (1);
		}
		else
		{
			i = i->next;
			index++;
		}
	}
	return (0);
}

void	minimize_op_list(t_op **op)
{
	while (get_merge_operation(op))
		;
	while (get_delete_operation(op))
		;
}
