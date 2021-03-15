/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:51:43 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/08 11:57:38 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	if (!dst && !src)
		return (0);
	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst < src)
		while (i < len)
		{
			*(dst1 + i) = *(src1 + i);
			i++;
		}
	else
		while (i < len)
		{
			*(dst1 + len - i - 1) = *(src1 + len - i - 1);
			i++;
		}
	return (dst);
}
