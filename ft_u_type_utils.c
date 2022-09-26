/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:49:44 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/26 16:24:25 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	uint_len(unsigned int d)
{
	int		i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

char	*uint_str(unsigned int d)
{
	char	*str;
	int		len;

	len = uint_len(d);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	str[len - 1] = '0';
	while (d > 0)
	{
		str[len - 1] = (d % 10) + '0';
		d = d / 10;
		len--;
	}
	return (str);
}
