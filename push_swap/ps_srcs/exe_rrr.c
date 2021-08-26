/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:52:55 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/26 16:52:55 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exe_rrr(t_stack **a, t_stack **b, t_op **op, int count_ra)
{
	int	i;

	i = 0;
	while (i < count_ra)
	{
		get_op_list(op, "rrr", a, b);
		i++;
	}
}
