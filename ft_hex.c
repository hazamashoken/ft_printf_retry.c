/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:26:33 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/26 22:54:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static size_t	ft_intlen(size_t nb, int div)
{
	int		i;
	size_t	number;

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

size_t	ft_uintlen(unsigned int nb, int div)
{
	int				i;
	unsigned int	number;

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
	size_t	len;
	char	*res2;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = 0;
	len = ft_intlen(x, 16);
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (res == NULL)
		return (0);
	while (x >= 16)
	{
		*(res + len - 1) = hex[x % 16];
		x /= 16;
		len--;
	}
	*(res) = hex[x];
	res2 = ft_strjoin("0x", res);
	free(res);
	return (res2);
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
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (res == NULL)
		return (0);
	while (x >= 16)
	{
		*(res + len - 1) = hex[x % 16];
		x /= 16;
		len--;
	}
	*(res) = hex[x];
	return (res);
}
