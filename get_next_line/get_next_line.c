/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:06:30 by kyounkim          #+#    #+#             */
/*   Updated: 2020/11/28 15:24:09 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_line(char **backup, char **line, char *newline_ptr)
{
	char		*temp;

	if (newline_ptr)
	{
		newline_ptr[0] = '\0';
		*line = ft_strdup(*backup);
		temp = ft_strdup(newline_ptr + 1);
		free(*backup);
		*backup = temp;
		return (1);
	}
	else
	{
		*line = *backup;
		*backup = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	char		*newline_ptr;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(backup[fd]))
		backup[fd] = ft_strdup("");
	while (!(newline_ptr = ft_strchr(backup[fd], '\n'))
			&& (read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
	}
	if (read_size < 0)
		return (-1);
	return (return_line(&backup[fd], line, newline_ptr));
}
