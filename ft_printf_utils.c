/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 02:04:32 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/25 21:58:09 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_istype(char c)
{
	size_t	i;

	i = 0;
	while (FORMAT[i])
	{
		if (FORMAT[i] == c)
			return (1);
		i++;
	}
	return (0);
}
