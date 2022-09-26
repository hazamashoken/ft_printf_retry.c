/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:15:01 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/25 21:20:36 by tliangso         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (size != 0)
	{
		while (*(src + i) != '\0' && i < size - 1)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		*(unsigned char *)(dest + i) = '\0';
	}
	return (n);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len >= s_len - start)
		len = s_len - start;
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (char *)s + start, len + 1);
	return (str);
}
