/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:16:11 by kyounkim          #+#    #+#             */
/*   Updated: 2020/10/23 02:02:34 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_n(int n, int fd)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
		print_n(n / 10, fd);
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		c = n % 10 * (-1) + '0';
		n /= -10;
		if (n > 0)
			print_n(n, fd);
		write(fd, &c, 1);
	}
	else
		print_n(n, fd);
}
