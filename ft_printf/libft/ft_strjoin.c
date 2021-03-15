/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:43:36 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/15 22:36:57 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_target)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, s1_len + 1);
	if (free_target == 1 || free_target == 3)
		free(s1);
	ft_strlcpy(result + s1_len, s2, s2_len + 1);
	if (free_target == 2 || free_target == 3)
		free(s2);
	return (result);
}
