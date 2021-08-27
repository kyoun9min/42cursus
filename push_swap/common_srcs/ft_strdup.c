/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:50:46 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 22:50:46 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		s_len;
	char	*result;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (0);
	while (i < s_len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
