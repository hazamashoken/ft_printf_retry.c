/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:15:01 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 14:15:13 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = (char)(c);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	unsigned char	*ptr;

	if (nmeb >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(nmeb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmeb * size);
	return (ptr);
}

