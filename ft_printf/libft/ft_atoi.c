/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:33:42 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/23 19:08:57 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_over_range(unsigned long long num, int sign)
{
	if (num >= 9223372036854775808ULL && sign == -1)
		return (0);
	if (num >= 9223372036854775807ULL && sign == 1)
		return (-1);
	return (num * sign);
}

int			ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (check_over_range(num, sign));
}
