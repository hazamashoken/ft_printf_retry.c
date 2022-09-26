/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:37:52 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/26 23:28:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	print_char(char *str, int w)
{
	int		i;

	i = 0;
	if (w == 0)
		w = 1;
	while (i < w)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	printf_empty(char *str, t_format *fmt)
{
	int		n;

	n = 0;
	if (str == 0 && fmt->width)
		n = print_char(" ", 1);
	else if (str == 0)
		n = print_char("(null)", 6);
	else if (ft_strlen(str) > 0 && fmt->width > 0)
	{
		while (n++ < fmt->width)
			ft_putchar_fd(' ', 1);
		n--;
	}
	return (n);
}

int	print_str(char *str, t_format *fmt)
{
	int	n;

	if ((fmt->type == 's' && fmt->dot && fmt->precision == 0) || (str == 0))
		return (printf_empty(str, fmt));
	n = ft_strlen(str);
	if (fmt->width > 0 && n == 0)
		n = print_char(str, fmt->width);
	else
		ft_putstr_fd(str, 1);
	return (n);
}
