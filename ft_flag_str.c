/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:43:18 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/24 14:32:27 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*plus_flag_str(char *str, t_format *fmt)
{
	int		nb;
	char	*fstr;

	if ((fmt->plus || fmt->space) && (fmt->type == 'd' || fmt->type == 'i'))
	{
		nb = ft_atoi(str);
		if (nb < 0)
			return (str);
		fstr = ft_calloc(sizeof(char), 2);
		if (!fstr)
			return (NULL);
		if (fmt->plus)
			fstr[0] = '+';
		else
			fstr[0] = ' ';
		fstr = ft_strjoin_free(fstr, str);
		if (!fstr)
			return (NULL);
		return (fstr);
	}
	return (str);
}

char	*hash_flag_str(char *str, t_format *fmt)
{
	char	*fstr;

	if (fmt->hash && (fmt->type == 'x' || fmt->type == 'X'))
	{
		fstr = ft_calloc(sizeof(char), 3);
		if (!fstr)
			return (NULL);
		fstr[0] = '0';
		if (str[0] != '0')
		{
			fstr[1] = fmt->type;
			fstr = ft_strjoin_free(fstr, str);
			if (!fstr)
				return (NULL);
		}
		else
			free(str);
		return (fstr);
	}
	return (str);
}

char	*format_pcs_str(char *str, t_format *fmt)
{

}

char	*format_pcs_digit(char *str, t_format *fmt)
{

}
