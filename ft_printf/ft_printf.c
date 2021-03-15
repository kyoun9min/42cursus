/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:47:24 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/16 03:10:00 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_asterisk(va_list ap, t_info *info)
{
	if (info->prec == -1)
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->minus = 1;
			info->width *= -1;
		}
	}
	else
	{
		info->prec = va_arg(ap, int);
		if (info->prec < 0)
			info->prec = -1;
	}
}

void	check_width_and_prec(char *format, t_info *info, int i)
{
	if (info->prec == -1)
		info->width = info->width * 10 + format[i] - 48;
	else
	{
		info->prec = info->prec * 10 + format[i] - 48;
		if (info->neg_prec == 1)
		{
			info->width = info->prec;
			info->prec = -1;
		}
	}
}

void	check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '0' && info->width == 0)
	{
		if (info->minus == 1)
			info->zero = 0;
		info->zero = 1;
	}
	else if (format[i] == '.')
	{
		if (format[++i] == '-')
		{
			info->neg_prec = 1;
			info->minus = 1;
		}
		info->prec = 0;
	}
	else if (ft_isdigit(format[i]))
		check_width_and_prec(format, info, i);
	else if (format[i] == '*')
		check_asterisk(ap, info);
}

int		parse_format(va_list ap, char *format)
{
	int		i;
	int		result;
	t_info	*info;

	i = 0;
	result = 0;
	if ((info = malloc(sizeof(t_info) * 1)) == '\0')
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			result += ft_putchar(format[i++]);
		else
		{
			if (format[++i] == '\0')
				return result;
			init_info(info);
			while ((ft_strchr(TYPE, format[i])) == '\0')
				check_info(ap, format, info, i);
			info->type = format[i++];
			result += print_type(ap, info);
		}
	}
	free(info);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}
