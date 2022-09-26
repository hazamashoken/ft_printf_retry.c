/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:40:43 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/26 22:23:49 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s)
		while (*(unsigned char *)(s + len) != '\0')
			len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*str;

	k = 0;
	if (s1 == (void *)0 || s2 == (void *)0)
		return (NULL);
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
		*(str + k++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i) != '\0')
		*(str + k++) = *(s2 + i++);
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(str + i) = *(s + i);
		i++;
	}
	return (str);
}
