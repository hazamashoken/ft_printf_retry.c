/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:26:33 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 12:39:34 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

size_t	ft_uintlen(unsigned int nb, int div)
{
	int			i;
	long int	number;

	i = 0;
	if (!nb)
		return (1);
	number = nb;
	while (number)
	{
		number /= div;
		i++;
	}
	return (i);
}

char	*get_hexaddr_str(size_t x, char format)
{
	char	*hex;
	char	*res;
	int		i;
	int		len;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = 0;
	len = ft_uintlen(x, 16);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (0);
	*(res + --len) = '\0';
	while (x >= 16)
	{
		*(res + len) = hex[x % 16];
		x /= 16;
		len--;
	}
	*(res) = hex[x];
	return (ft_strjoin("0x", res));
}

char	*get_hex_str(unsigned int x, char format)
{
	char	*hex;
	char	*res;
	int		i;
	int		len;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = 0;
	len = ft_uintlen(x, 16);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (0);
	*(res + --len) = '\0';
	while (x >= 16)
	{
		*(res + len) = hex[x % 16];
		x /= 16;
		len--;
	}
	*(res) = hex[x];
	return (res);
}
