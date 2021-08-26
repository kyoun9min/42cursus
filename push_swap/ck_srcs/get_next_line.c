/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:27:51 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/25 22:27:51 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	ft_strlcpy(result, s1, s1_len + s2_len + 1);
	free(s1);
	ft_strlcpy(result + s1_len, s2, s1_len + s2_len + 1);
	return (result);
}

int	return_line(char *backup, char **line, char *newline_ptr)
{
	char	*temp;

	if (newline_ptr)
	{
		newline_ptr[0] = '\0';
		*line = ft_strdup(backup);
		temp = ft_strdup(newline_ptr + 1);
		free(backup);
		backup = temp;
		return (1);
	}
	else
	{
		*line = backup;
		backup = 0;
	}
	return (0);
}

int	get_next_line(char **line)
{
	static char	*backup;
	char		buf[1024];
	int			read_size;
	char		*newline_ptr;

	read_size = 0;
	if (line == 0)
		return (-1);
	if (!(backup))
		backup = ft_strdup("");
	newline_ptr = ft_strchr(backup, '\n');
	read_size = read(0, buf, 1024);
	while (!(newline_ptr) && (read_size > 0))
	{
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	if (read_size < 0)
		return (-1);
	return (return_line(backup, line, newline_ptr));
}
