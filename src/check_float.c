/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 14:32:22 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 15:06:40 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	get_parts(t_check_float *c_float, t_flags flags, long double dec)
{
	c_float->nblen = 0;
	while (c_float->str[c_float->nblen] != '.' && c_float->str[c_float->nblen])
		c_float->nblen++;
	if (flags.hashtag)
		c_float->nblen++;
	if (dec != 0.0)
	{
		c_float->nbstr = ft_strsub(c_float->str, 0, c_float->nblen);
		c_float->decstr = ft_strsub(c_float->str, c_float->nblen,
				ft_strlen(c_float->str) - (c_float->nblen));
		c_float->declen = ft_strlen(c_float->decstr);
		c_float->size = flags.width - ft_strlen(c_float->str);
	}
	else
	{
		c_float->str = "0.0";
		c_float->size = flags.width - ft_strlen(c_float->str);
		c_float->nbstr = "0";
		c_float->decstr = ".0";
		c_float->declen = 1;
		c_float->nblen = 2;
	}
	if (c_float->size < 0)
		c_float->size = 0;
	c_float->ret = 0;
}

void	print_width_noprec_nopoint(t_flags flags, int pre)
{
	if (pre == 1)
		ft_putncaract(' ', flags.width - 8 - flags.plus);
	ft_putncaract('+', flags.plus);
	if (pre == 2)
		ft_putncaract('0', flags.width - 8 - flags.plus);
	ft_putstr("0.000000");
	if (pre == 3)
		ft_putncaract(' ', flags.width - 8 - flags.plus);
}

void	print_width_noprec_point_nul(t_flags flags)
{
	if (!flags.minus && !flags.zero)
		ft_putncaract(' ', flags.width - flags.hashtag - 1);
	ft_putncaract('+', flags.plus);
	if (flags.hashtag && !flags.minus)
		ft_putncaract('0', flags.width - flags.hashtag - flags.plus - 1);
	ft_putchar('0');
	ft_putncaract('.', flags.hashtag);
	if (flags.minus == 1)
		ft_putncaract(' ', flags.width - flags.hashtag - 1);
}

int		width_noprec_point_nul(t_flags flags)
{
	if (!flags.minus && !flags.zero)
	{
		ft_putncaract(' ', flags.width - 1 - flags.plus - flags.hashtag);
		width_noprec_point_nul(flags);
	}
	else if (flags.minus)
	{
		width_noprec_point_nul(flags);
		ft_putncaract(' ', flags.width - 1 - flags.plus - flags.hashtag);
	}
	else if (flags.zero)
	{
		ft_putncaract('+', flags.plus);
		if (flags.width == 2)
			ft_putncaract('0', flags.width - flags.plus - flags.hashtag + 1);
		else if (flags.width == 1)
			ft_putncaract('0', flags.width - flags.plus - flags.hashtag + 2);
		else
			ft_putncaract('0', flags.width - flags.plus - flags.hashtag);
		ft_putncaract('.', flags.hashtag);
	}
	return (flags.width);
}

int		str_find(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

void	dec_arround (t_check_float *c_float, long double dec, t_flags flags)
{
	int i;

	i = 0;

	while (c_float->decstr[i] == '.')
		i++;
	if (c_float->decstr[i] >= '5')
	{
		if (c_float->nbstr[c_float->nblen - 1] == '9')
		{
			c_float->nbstr = ft_strsub(ft_ftoa(dec + 1, flags.precision), 0,
					c_float->nblen + 1);
			c_float->nblen++;
		}
		else
			c_float->nbstr = ft_strsub(ft_ftoa(dec + 1, flags.precision), 0,
					c_float->nblen);
	}
}

int		width_noprec_point(long double dec, t_flags flags,
		t_check_float c_float)
{
	if (dec == 0.0)
		print_width_noprec_point_nul(flags);
	if (dec == 0.0)
		return (flags.width);
	dec_arround(&c_float, dec, flags);
	if (flags.minus)
	{
		ft_putncaract('+', flags.plus);
		ft_putstr(c_float.nbstr);
		ft_putncaract(' ', (flags.width - c_float.nblen - flags.plus));
	}
	else
	{
		ft_putncaract('+', flags.plus);
		if (flags.zero)
			ft_putncaract('0', flags.width - c_float.nblen -
					flags.plus - flags.hashtag);
		else
			ft_putncaract(' ', flags.width - c_float.nblen -
					flags.plus - flags.hashtag);
		ft_putstr(c_float.nbstr);
	}
	if (!(str_find(c_float.nbstr, '.') == 1))
		ft_putncaract('.', flags.hashtag);
	return (flags.width + flags.hashtag + flags.plus);
}

int		width_noprec_nopoint_null (t_flags flags)
{
	if (!flags.minus && !flags.hashtag && !flags.zero)
		print_width_noprec_nopoint(flags, 1);
	else if (flags.minus)
		print_width_noprec_nopoint(flags, 3);
	else if (flags.zero)
		print_width_noprec_nopoint(flags, 2);
	return (flags.width);
}

int		width_noprec_nopoint(long double dec, t_flags flags,
		t_check_float c_float)
{
	if (dec == 0.0 && flags.width > 8)
		return (width_noprec_nopoint_null(flags));
	else if (dec == 0.0 && !(flags.width > 8))
	{
		print_width_noprec_nopoint(flags, 0);
		return (8 + flags.plus);
	}
	if (!flags.zero)
	{
		ft_putncaract(' ', c_float.size - flags.plus);
		ft_putncaract('+', flags.plus);
	}
	else if (!flags.minus)
	{
		ft_putncaract('+', flags.plus);
		ft_putncaract('0', c_float.size - flags.plus);
	}
	ft_putstr(c_float.str);
	if (flags.minus)
		ft_putncaract(' ', c_float.size);
	return (flags.width);
}

int		float_nowidth_prec_sup_inf(long double dec, t_check_float c_float,
		t_flags flags)
{
	if (flags.precision >= ft_strlen(c_float.decstr))
	{
		if (dec == 0.0)
		{
			ft_putstr(c_float.nbstr);
			ft_putstr(c_float.decstr);
		}
		else
			ft_putstr(c_float.str);
		ft_putncaract('0', flags.precision - c_float.declen);
		return (flags.precision + c_float.nblen - 1 + flags.plus);
	}
	else
	{
		ft_putstr(c_float.str);
		return (c_float.nblen + 1 + flags.precision + flags.plus);
	}
	return (0);
}

int		float_nowidth_prec(long double dec,
		t_check_float c_float, t_flags flags)
{
	ft_putncaract('+', flags.plus);
	if (flags.plus == 0)
		ft_putncaract(' ', flags.space);
	return (float_nowidth_prec_sup_inf(dec, c_float, flags));
}

int		check_p_w_float(long double dec, t_flags flags)
{
	t_check_float	c_float;

	c_float.str = ft_ftoa(dec, flags.precision);
	c_float.strlen = ft_strlen(c_float.str);
	get_parts(&c_float, flags, dec);
	if (flags.width && !flags.precision)
	{
		if (flags.point)
			c_float.ret = width_noprec_point(dec, flags, c_float);
		if (!flags.point)
			c_float.ret = width_noprec_nopoint(dec, flags, c_float);
	}
	if (flags.precision && !flags.width)
		c_float.ret = float_nowidth_prec(dec, c_float, flags);
	if ((flags.precision && flags.width) && (flags.width >= flags.precision))
		ft_putncaract(' ', flags.width - c_float.strlen - flags.plus);
	if (!c_float.ret)
	{
		if (dec > 0)
			ft_putncaract('+', flags.plus);
		ft_putstr(c_float.str);
		ft_putncaract('0', flags.precision - c_float.declen - flags.plus);
		c_float.ret = (c_float.nblen + c_float.declen + flags.plus + 1);
	}
	return (c_float.ret);
}
