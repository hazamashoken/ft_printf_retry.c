/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:29:13 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/25 22:37:52 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, (unsigned char *)&c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd < 0)
		return ;
	i = 0;
	if (s == (void *)0)
		return ;
	while (*(unsigned char *)(s + i) != '\0')
		ft_putchar_fd(*(unsigned char *)(s + i++), fd);
}
