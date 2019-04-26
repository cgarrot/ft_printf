/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 11:28:43 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 12:25:04 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	get_parts(t_check_float *c_float, t_flags flags)
{
	c_float->nblen = 0;
	while (c_float->str[c_float->nblen] != '.')
		c_float->nblen++;
	if (flags.hashtag)
		c_float->nblen++;
	c_float->nbstr = ft_strsub(c_float->str, 0, c_float->nblen + 1);
	c_float->decstr = ft_strsub(c_float->str, c_float->nblen + 1,
			ft_strlen(c_float->str) - (c_float->nblen + 1));
	c_float->declen = ft_strlen(c_float->decstr);
	c_float->size = flags.width - ft_strlen(c_float->str);
}

int		check_p_w_float(long double dec, t_flags flags)
{


	t_check_float	c_float;

	c_float.str = ft_strnew(0);
	c_float.str = ft_ftoa(dec, c_float.str, flags);
	get_parts(&c_float, flags);

	if (c_float.size < 0)
		c_float.size = 0;

	if (flags.width && !flags.precision)
	{
		if (flags.width >= ft_strlen(c_float.str))
		{
			if (flags.point)
			{
				if (!flags.zero)
					ft_putncaract('0', flags.width - c_float.nblen);
				else
					ft_putncaract(' ', c_float.size);
				ft_putstr(c_float.nbstr);
			}
			else
			{
				ft_putncaract(' ', c_float.size);
				ft_putstr(c_float.str);
			}
			return (flags.width);
		}
	}
	if (flags.precision && !flags.width)
	{
		if (flags.precision >= ft_strlen(c_float.str))
		{
			ft_putstr(c_float.str);
			ft_putncaract('0', flags.precision - ft_strlen(c_float.str));
			return (flags.precision);
		}
		else
		{
			ft_putstr(c_float.nbstr);
			ft_putstr(ft_strndup(c_float.decstr, flags.precision));
			return (c_float.nblen + 1 + flags.precision);
		}
	}
	ft_putstr(c_float.str);
	return (ft_strlen(c_float.str));
}
