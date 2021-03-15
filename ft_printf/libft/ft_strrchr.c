/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:52:50 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/14 12:06:18 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c1;

	i = ft_strlen(s);
	c1 = (char)c;
	while (i > 0)
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == c1)
		return ((char *)s);
	return (0);
}
