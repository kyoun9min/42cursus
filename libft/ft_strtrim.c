/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:25:57 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/17 03:05:28 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start_index(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		if (strchr(set, s1[i]))
			i++;
		else
			break;
	}
	return (i);
}

static size_t	get_end_index(char const *s1, char const *set)
{
	size_t i;
	size_t s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (s1[i])
	{
		if (strchr(set, s1[s1_len - 1 - i]))
			i++;
		else
			break;
	}
	return (s1_len - 1 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * end - start + 2);
	if (!result)
		return (0);
	ft_strlcpy(result, s1 + start, end - start + 2);
	return (result);
}
