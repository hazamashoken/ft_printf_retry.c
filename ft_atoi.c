/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:17:00 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 14:17:10 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

#define CUTTOFF 922337203685477580

static char	check_neg(int neg)
{
	if (neg == 1)
		return ('7');
	else
		return ('8');
}

static int	check_return(int neg)
{
	if (neg == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	neg;
	long	res;
	int		limit;

	i = 0;
	neg = 1;
	while ((*(nptr + i) >= '\a' && *(nptr + i) <= '\r') || *(nptr + i) == ' ')
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		if (*(nptr + i++) == '-')
			neg = -1;
	limit = check_neg(neg);
	res = 0;
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		if ((res > CUTTOFF) || (res == CUTTOFF && (*(nptr + i) > limit)))
			return ((check_return(neg)));
		res = (res * 10) + (*(nptr + i++) - '0');
	}
	return (res * neg);
}
