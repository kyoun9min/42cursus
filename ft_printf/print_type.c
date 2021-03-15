/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:05:13 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/08 14:05:25 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h";

int		print_type(va_list ap, t_info *info)
{
	int		result;

	result = 0;
	if (info->type == 'c')
		result = print_char(va_arg(ap, int), info);
	else if (info->type == 's')
		result = print_string(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		result = print_nbr(va_arg(ap, int), info);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		result = print_nbr(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		result = print_nbr(va_arg(ap, long long), info);
	else if (info->type == '%')
		result = print_char('%', info);
	return (result);
}
