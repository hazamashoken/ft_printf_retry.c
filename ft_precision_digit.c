/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_digit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:15:56 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/25 21:17:57 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static char	*pcs_digit_fill(char *fstr, char *str, t_format *fmt)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	if (str[0] == '-')
	{
		i++;
		j++;
		len--;
		fmt->precision++;
	}
	while (i < fmt->precision)
	{
		if (i < fmt->precision - len)
			fstr[i] = '0';
		else
			fstr[i] = str[j++];
		i++;
	}
	return (fstr);
}

char	*pcs_digit_operation(char *str, t_format *fmt)
{
	char	*fstr;

	if (str[0] == '-')
	{
		fstr = ft_calloc(sizeof(char), fmt->precision + 2);
		if (!fstr)
			return (NULL);
		fstr[0] = '-';
	}
	else
	{
		fstr = ft_calloc(sizeof(char), fmt->precision + 1);
		if (!fstr)
			return (NULL);
	}
	pcs_digit_fill(fstr, str, fmt);
	return (fstr);
}
