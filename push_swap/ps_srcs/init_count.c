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

void	init_count(t_count *count)
{
	count->push = 0;
	count->count_ra = 0;
	count->count_rb = 0;
}
