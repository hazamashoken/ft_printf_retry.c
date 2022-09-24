/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:31:33 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/23 16:24:36 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_format	*reset_format(t_format *fmt)
{
	fmt->width = 0;
	fmt->precision = 0;
	fmt->zero = 0;
	fmt->dot = 0;
	fmt->minus = 0;
	fmt->plus = 0;
	fmt->is_zero = 0;
	fmt->percent = 0;
	fmt->space = 0;
	fmt->total_len = 0;
	return (fmt);
}

int	check_format(char c, t_format *fmt)
{
	if (fmt->dot && ft_isdigit(c))
		fmt->precision = (fmt->precision * 10) + (c - '0');
	else if (ft_istype(c))
		fmt->type = c;
	else if (c == '.')
		fmt->dot = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == '-')
		fmt->minus = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '#')
		fmt->hash = 1;
	else if (c == '0' && fmt->width == 0)
		fmt->zero = 1;
	else if (ft_isdigit(c))
		fmt->width = (fmt->width * 10) + (c - '0');
	else
		return (0);
	return (1);
}

char	*current_format(t_format *fmt, const char *format, int pos)
{
	char	*current_format;
	size_t	format_len;
	size_t	i;

	i = 0;
	format_len = 0;
	while (check_format(*(format + pos + format_len), fmt) && fmt->type == 0)
		format_len++;
	if (fmt->type)
		current_format = (char *)malloc(format_len + 1);
	else
	{
		reset_format(fmt);
		return (NULL);
	}
	if (current_format == NULL)
		return (NULL);
	while (i < format_len)
	{
		*(current_format + i) = *(format + pos + i);
		i++;
	}
	*(current_format + i) = '\0';
	return (current_format);
}

int	ft_eval_format(t_format *fmt, const char *format, int pos)
{
	int		n;
	char	*format_str;
	int		len;

	len = 0;
	n = 0;
	format_str = current_format(fmt, format, pos);
	if (format_str)
	{
		print_format(fmt);
		len += ft_strlen(format_str);
		free(format_str);
	}
	else
		len = 0;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			ret;
	t_format	*tab;

	tab = (t_format *)malloc(sizeof(t_format));
	if (!tab)
		return (-1);
	tab = reset_format(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (*(format + ++i))
	{
		if (*(format + i) == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, format + i, 1);
	}
	va_end(tab->args);
	ret += tab->total_len;
	free (tab);
	return (ret);
}
