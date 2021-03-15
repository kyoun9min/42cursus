/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:44 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/07 06:58:58 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	int result;

	result = 0;
	if (info->minus == 1)
		result += ft_putchar(c);
	while (info->width != 1)
	{
		if (info->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		info->width--;
		result++;
	}
	if (info->minus == 0)
		result += ft_putchar(c);
	return (result);
}
