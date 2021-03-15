/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:47:34 by kyounkim          #+#    #+#             */
/*   Updated: 2021/03/16 03:10:55 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"

#define TYPE "cspdiuxX%"

typedef struct	s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		neg_prec;
	char	type;
	int		nbr_base;
	int		nbr_sign;
}			t_info;

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, char *format);
void	check_info(va_list ap, char *format, t_info *info, int i);
void	check_width_and_prec(char *format, t_info *info, int i);
void	check_asterisk(va_list ap, t_info *info);
int		print_type(va_list ap, t_info *info);
int		print_char(int c, t_info *info);
int		print_string(char *str, t_info *info);
void	put_prec_str(char *str, t_info *info, char **buf);
int		print_nbr(long long nbr, t_info *info);
void	put_prec_nbr(long long nbr, t_info *info, char **buf);
void	put_minus_and_width(long long nbr, t_info *info, char **buf);
int		put_pointer_prefix(char **buf);
void	put_width(t_info *info, char **buf);
char	*ft_baseset(char type);
int		ft_nbrlen(long long nbr, t_info *info);
void	init_info(t_info *info);

#endif
