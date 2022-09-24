/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:17:17 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 02:53:33 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*c_type_str(int c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	*str = c;
	return (str);
}

char	*s_type_str(char *s)
{
	char	*str;

	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*p_type_str(unsigned long long p)
{
	char	*str;

	str = get_hexaddr(p, 'x');
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*d_type_str(int d)
{
	char	*str;

	str = ft_itoa(d);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*u_type_str(long int u)
{
	char	*str;

	str = uint_str(u);
	if (str == NULL)
		return (NULL);
	return (str);
}
