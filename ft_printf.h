/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:26:41 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 11:27:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdlib.h>
# include	<limits.h>
# include	<stdarg.h>
# include	<unistd.h>

# define FORMAT "cspdiuxX%"

typedef struct s_format
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		dot;
	int		minus;
	int		total_len;
	int		plus;
	int		is_zero;
	int		percent;
	int		space;
	int		hash;
	char	type;
}	t_format;

//ft_printf_utils.c
int		ft_istype(char c);

//ft_checker.c
void	print_format(t_format *fmt);

//ft_hex.c
size_t	ft_uintlen(unsigned int nb, int div);
char	*get_hexaddr_str(size_t x, char format);
char	*get_hex_str(unsigned int x, const char *format);

//ft_type_str.c
char	*c_type_str(int c);
char	*s_type_str(char *s);
char	*p_type_str(unsigned long long p);
char	*d_type_str(int d);
char	*u_type_str(long int u);

//ft_type_str2.c
char	*x_type_str(size_t	x, char type);

//utils.c
size_t	ft_strlen(const char *s);
int		ft_isdigit(char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

//itoa.c
char	*ft_itoa(int n);

//u_type_utils.c
char	*uint_str(unsigned int d);

#endif
