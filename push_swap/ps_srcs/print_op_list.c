/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:13:00 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 22:13:00 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_op_list(t_op **op)
{
	t_op	*i;

	i = (*op);
	while (i != NULL)
	{
		if (i->s != NULL)
		{
			write(1, i->s, ft_strlen(i->s));
			write(1, "\n", 1);
		}
		i = i->next;
	}
}
