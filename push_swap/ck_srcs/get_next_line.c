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

char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0' && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *a, char *b)
{
	char	*dest;
	int		len_a;
	int		len_b;
	int		i;
	int		j;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	i = -1;
	j = -1;
	dest = (char *)malloc(sizeof(char) * (len_a + len_b + 1));
	if (!dest)
		return (NULL);
	while (++i < len_a)
		dest[i] = a[i];
	while (++j < len_b)
		dest[i++] = b[j];
	dest[i] = '\0';
	free(a);
	return (dest);
}

int	get_mid_line(char **line, char **data, int n)
{
	*line = ft_strndup((*data), n);
	free(*data);
	*data = NULL;
	return (1);
}

int	get_end_line(char **line, char **data)
{
	if (*data != NULL)
	{
		*line = *data;
		*data = NULL;
		return (0);
	}
	*line = ft_strndup("", 0);
	return (0);
}

int	get_next_line(char **line)
{
	char		buffer[2];
	static char	*data;
	int			byte;
	int			n;

	if (line == NULL)
		return (-1);
	n = 0;
	byte = read(0, buffer, 1);
	while (byte > 0)
	{
		buffer[byte] = '\0';
		if (data == NULL)
			data = ft_strndup(buffer, 1);
		else
			data = ft_strjoin(data, buffer);
		if (buffer[0] == '\n')
			return (get_mid_line(line, &data, n));
		n = n + byte;
	}
	if (byte < 0)
		return (-1);
	return (get_end_line(line, &data));
}
