/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:28:31 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/19 13:27:54 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
}

void	put_minus_and_width(long long nbr, t_info *info, char **buf)
{
	if (info->zero == 0)
	{
		*buf = ft_strjoin("-", *buf, 2);
		put_width(info, buf);
	}
	else
	{
		put_width(info, buf);
		if (ft_nbrlen(nbr, info) >= info->width)
			*buf = ft_strjoin("-", *buf, 2);
		else
			(*buf)[0] = '-';
	}
}

void	put_prec_nbr(long long nbr, t_info *info, char **buf)
{
	int		i;
	int		buf_len;
	int		nbr_len;

	nbr_len = ft_nbrlen(nbr, info);
	if (info->prec > nbr_len)
		buf_len = info->prec;
	else
		buf_len = nbr_len;
	if (!(*buf = (char *)malloc(sizeof(char) * buf_len + 1)))
		return ;
	i = 0;
	(*buf)[buf_len] = '\0';
	while (i < buf_len - nbr_len)
		(*buf)[i++] = '0';
	if (nbr == 0 && info->prec != 0)
		(*buf)[buf_len - 1] = '0';
	i = 1;
	while (nbr)
	{
		(*buf)[buf_len - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
}

int		print_nbr(long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;

	if (info->prec > -1)
		info->zero = 0;
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	put_prec_nbr(nbr, info, &buf);
	if (info->nbr_sign == -1)
		put_minus_and_width(nbr, info, &buf);
	else
		put_width(info, &buf);
	if (info->type == 'p')
		put_pointer_prefix(&buf);
	ft_putstr(buf);
	buf_len = (int)ft_strlen(buf);
	free(buf);
	return (buf_len);
}
