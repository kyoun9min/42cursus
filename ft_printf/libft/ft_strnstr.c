/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:39 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/21 22:51:27 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) >= ft_strlen(needle) && ft_strlen(needle) <= len)
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (needle[j] && i + j < len)
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
				if (!needle[j])
					return ((char *)haystack + i);
			}
			i++;
		}
	}
	return (0);
}
