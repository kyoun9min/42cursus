/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:08:43 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/21 21:53:47 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*result;

	len = int_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	if (n < 0)
	{
		result[len - 1] = (n % 10) * (-1) + '0';
		result[0] = '-';
		len--;
		n /= -10;
	}
	while (n / 10 > 0)
	{
		result[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	if ((result[0] == '-' && (len - 1) != 0)
		|| (result[0] != '-' && (len - 1) == 0))
		result[len - 1] = n + '0';
	return (result);
}
