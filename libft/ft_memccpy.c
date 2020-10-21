/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:44:45 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/21 20:49:45 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	c1 = (unsigned char)c;
	while (i < n)
	{
		*(dst1 + i) = *(src1 + i);
		if (*(src1 + i) == c1)
			return ((unsigned char *)dst + i + 1);
		i++;
	}
	return (0);
}
