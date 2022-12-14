/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_str2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:54:01 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/26 23:08:03 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*x_type_str(unsigned int x, char type)
{
	char	*str;

	str = get_hex_str(x, type);
	if (str == NULL)
		return (NULL);
	return (str);
}
