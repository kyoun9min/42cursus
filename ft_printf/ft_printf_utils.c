/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:32:57 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/16 01:38:56 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->neg_prec = 0;
	info->type = 0;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

int		ft_nbrlen(long long nbr, t_info *info)
{
	int		len;

	if (nbr == 0 && info->prec != 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		nbr /= info->nbr_base;
		len++;
	}
	return (len);
}

char	*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

void	put_width(t_info *info, char **buf)
{
	char	*width;
	int		buf_len;
	int		i;

	buf_len = (int)ft_strlen(*buf);
	if (info->width <= buf_len)
		return;
	if(!(width = (char *)malloc(sizeof(char) * (info->width - buf_len + 1))))
		return;
	i = 0;
	while (i < info->width - buf_len)
	{
		if (info->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf, 3);
	else
		*buf = ft_strjoin(*buf, width, 3);
}
