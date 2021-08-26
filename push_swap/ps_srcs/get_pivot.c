/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:11:35 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/23 13:11:35 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_high_pivot(t_stack **head, int len)
{
	int	*sort;
	int	mid_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	mid_value = sort[2 * len / 3];
	free(sort);
	return (mid_value);
}

int	get_low_pivot(t_stack **head, int len)
{
	int	*sort;
	int	mid_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	mid_value = sort[len / 3];
	free(sort);
	return (mid_value);
}
