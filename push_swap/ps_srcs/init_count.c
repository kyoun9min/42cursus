/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:29:54 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/26 16:29:54 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_count(t_count *count, t_stack **x, int stack_size)
{
	count->push = 0;
	count->count_ra = 0;
	count->count_rb = 0;
	count->h_pivot = get_high_pivot(x, stack_size);
	count->l_pivot = get_low_pivot(x, stack_size);
}
