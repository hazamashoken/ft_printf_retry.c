/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:48:09 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/27 15:18:34 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;

	        int             a = -4;
        int             b = 0;
        char    c = 'a';
        int             d = 2147483647;
        int             e = -2147483648;
        int             f = 42;
        int             g = 25;
        int             h = 4200;
        int             i = 8;
        int             j = -12;
        int             k = 123456789;
        int             l = 0;
        int             m = -12345678;
        char    *n = "abcdefghijklmnop";
        char    *o = "-a";
        char    *p = "-12";
        char    *q = "0";
        char    *r = "%%";
        char    *s = "-2147483648";
        char    *t = "0x12345678";
        char    *u = "-0";

	char	*null_str = NULL;
	printf("\nfake one:\n");
	int len = ft_printf("%?i", a);
	printf("\nfake len: %d\n", len);
	printf("\nreal one:\n");
	int len2 = printf("%?i", a);
	printf("\nreal len: %d\n", len2);
	return (0);
}
