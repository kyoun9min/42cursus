/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:18:36 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/22 23:42:24 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_prec_str(char *str, t_info *info, char **buf)
{
	int	i;
	int	str_len;
	int	buf_len;

	str_len = (int)ft_strlen(str);
	if (info->prec > str_len)
		buf_len = str_len;
	else
		buf_len = info->prec;
	if (!(*buf = (char *)malloc(sizeof(char) * buf_len + 1)))
		return ;
	i = 0;
	while (i < buf_len)
	{
		(*buf)[i] = str[i];
		i++;
	}
	(*buf)[i] = '\0';
}

int		print_string(char *str, t_info *info)
{
	int		buf_len;
	char	*buf;

	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = (int)ft_strlen(str);
	put_prec_str(str, info, &buf);
	put_width(info, &buf);
	ft_putstr(buf);
	buf_len = (int)ft_strlen(buf);
	free(buf);
	return (buf_len);
}
