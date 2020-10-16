/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:15:47 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/08 11:18:59 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	c1;

	i = 0;
	b1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	while (i < len)
	{
		*(b1 + i) = c1;
		i++;
	}
	return (b);
}
