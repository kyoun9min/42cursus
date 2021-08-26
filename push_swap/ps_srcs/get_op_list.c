/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:48:48 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 14:09:29 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_op_list(t_op **op, char *s, t_stack **a, t_stack **b)
{
	t_op	*new;

	new = create_op_list_node(s);
	add_op_list_back(op, new);
	if (s[0] == 's' && s[1] == 'a')
		swap(a);
	else if (s[0] == 's' && s[1] == 'b')
		swap(b);
	else if (s[0] == 'p' && s[1] == 'a')
		push(a, b);
	else if (s[0] == 'p' && s[1] == 'b')
		push(b, a);
	else if (s[0] == 'r' && s[1] == 'a')
		rotate(a);
	else if (s[0] == 'r' && s[1] == 'b')
		rotate(b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		reverse_rotate(a);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		reverse_rotate(b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
