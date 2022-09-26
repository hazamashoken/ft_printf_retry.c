/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:26:41 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/26 22:51:54 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdlib.h>
# include	<limits.h>
# include	<stdarg.h>
# include	<unistd.h>
# include	<stdio.h>

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

//printf.c
int		ft_printf(const char *format, ...);

//ft_printf_utils.c
int		ft_istype(char c);

//ft_checker.c
void	print_format(t_format *fmt);

//ft_hex.c
size_t	ft_uintlen(unsigned int nb, int div);
char	*get_hexaddr_str(size_t x, char format);
char	*get_hex_str(unsigned int x, char format);

//flag_str.c
char	*plus_flag_str(char *str, t_format *fmt);
char	*hash_flag_str(char *str, t_format *fmt);
char	*format_pcs_digit(char *str, t_format *fmt);
char	*format_pcs_str(char *str, t_format *fmt);

//ft_type_str.c
char	*c_type_str(int c);
char	*s_type_str(char *s);
char	*p_type_str(size_t p);
char	*d_type_str(int d);
char	*u_type_str(unsigned int u);

//ft_type_str2.c
char	*x_type_str(unsigned int x, char type);

//utils.c
int		ft_strlen(const char *s);
int		ft_isdigit(char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);

//utils2.c
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmeb, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);

//ft_utils3.c
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

//itoa.c
char	*ft_itoa(int n);

//atoi.c
int		ft_atoi(const char *nptr);

//u_type_utils.c
char	*uint_str(unsigned int d);

//precision_digit.c
char	*pcs_digit_operation(char *str, t_format *fmt);

//printer.c
int		print_str(char *cstr, t_format *fmt);
int		printf_empty(char *str, t_format *fmt);
int		print_char(char *str, int w);

//align.c
char	*align_left(char *str, t_format *fmt);
char	*align_right(char *str, t_format *fmt);
int		printlen(char *str);

#endif
