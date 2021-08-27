/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:41:38 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/27 18:41:38 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exe_rb(t_stack **b, t_op **op, int count_ra, int count_rb)
{
	if (count_ra > count_rb)
		get_op_list(op, "rb", NULL, b);
}
