/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:49:44 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 02:51:53 by tliangso         ###   ########.fr       */
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
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * uint_len(d) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	while (d > 0)
	{
		str[i] = (d % 10) + '0';
		d = d / 10;
		i++;
	}
	return (str);
}
