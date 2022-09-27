/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:22:03 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/27 15:24:23 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	star_flag(char c, t_format *fmt)
{
	int		star;

	if (c != '*')
		return (0);
	if (fmt->dot)
	{
		star = (va_arg(fmt->args, int));
		fmt->precision = star;
	}
	else
	{
		star = (va_arg(fmt->args, int));
		if (star < 0)
		{
			fmt->minus = 1;
			star *= -1;
		}
		fmt->width = star;
	}
	return (1);
}
