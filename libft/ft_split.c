/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:03:58 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/21 17:07:18 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**malloc_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static size_t	cnt_s(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != 0
				&& s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	idx;
	size_t	i;
	size_t	start;

	if (!s || !(result = (char **)malloc(sizeof(char *) * (cnt_s(s, c) + 1))))
		return (0);
	i = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(result[idx] = (char *)malloc(sizeof(char) * (i - start + 1))))
				return (malloc_free(result));
			ft_strlcpy(result[idx++], &s[start], i - start + 1);
		}
		else
			i++;
	}
	result[idx] = 0;
	return (result);
}
