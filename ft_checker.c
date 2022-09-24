/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 02:19:34 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 02:55:09 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*types_checker(t_format *fmt)
{
	char	*str;

	if (fmt->type == 'c')
		str = c_type_str(va_arg(fmt->args, int));
	else if (fmt->type == 's')
		str = s_type_str(va_arg(fmt->args, char *));
	else if (fmt->type == 'p')
		str = p_type_str((unsigned long long)va_arg(fmt->args, void *));
	else if (fmt->type == 'd' || fmt->type == 'i')
		str = d_type_str(va_arg(fmt->args, int));
	else if (fmt->type == 'u')
		str = u_type_str(va_arg(fmt->args, long int));
	else if (fmt->type == 'x')
		str = x_type_str(va_arg(fmt->args, size_t), 'x');
	else if (fmt->type == 'X')
		str = x_type_str(va_arg(fmt->args, size_t), 'X');
	else if (fmt->type == '%')
		str = c_type_str('%');
	else
		str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*flags_checker(char *str, t_format *fmt)
{
	str = plus_flag_str(str, fmt);
	if (!str)
		return (NULL);
	str = hash_flag_str(str, fmt);
	if (!str)
		return (NULL);
	return (str);
}

char	*precision_checker(char *str, t_format *fmt)
{
	char	*fstr;

	if (!fmt->dot)
		return (str);
	if (fmt->type == 's' || fmt->type == 'c')
		fstr = format_pcs_str(str, fmt);
	else
		fstr = format_pcs_digit(str, fmt);
	if (!fstr)
		return (NULL);
	return (fstr);
}

char	*width_checker(char *str, t_format *fmt)
{
	char	*fstr;

	if (fmt->width <= ft_strlen(str))
		return (str);
	if (fmt->minus)
		fstr = align_left(str, fmt);
	else
		fstr = align_right(str, fmt);
	if (!fstr)
		return (NULL);
	return (fstr);
}

void	print_format(t_format *fmt)
{
	char	*str;

	str = types_checker(fmt);
	str = flags_checker(str, fmt);
	str = precision_checker(str, fmt);
	str = width_checker(str, fmt);
	if (fmt->type == 'c')
		print_char(str, fmt->width);
	else
		print_str(str, fmt);
	free(str);
}
