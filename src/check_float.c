/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 14:32:22 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 17:54:47 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	get_parts(t_check_float *c_float, t_flags flags, int dec)
{
	c_float->nblen = 0;
	while (c_float->str[c_float->nblen] != '.' && c_float->str[c_float->nblen])
		c_float->nblen++;
	if (flags.hashtag)
		c_float->nblen++;
	if (dec != 0.0)
	{
		c_float->nbstr = ft_strsub(c_float->str, 0, c_float->nblen);
		c_float->decstr = ft_strsub(c_float->str, c_float->nblen, (int)ft_strlen(c_float->str) - (c_float->nblen));
		c_float->declen = (int)ft_strlen(c_float->decstr);
		c_float->size = flags.width - (int)ft_strlen(c_float->str);
	}
	/*else
	{
		c_float->str = "0.0";
		c_float->size = flags.width - ft_strlen(c_float->str);
		c_float->nbstr = "0";
		c_float->decstr = ".0";
		c_float->declen = 1;
		c_float->nblen = 2;
	}*/
}

void	print_width_noprec_nopoint(t_flags flags, int pre)
{
	if (pre == 1)
		ft_putncaract(' ', flags.width - 8 - flags.plus);
	ft_putncaract('+', flags.plus);
	if (pre == 2)
		ft_putncaract(' ', flags.width - 8 - flags.plus);
	ft_putstr("0.000000");
	if (pre == 3)
		ft_putncaract(' ', flags.width - 8 - flags.plus);
}

void	print_width_noprec_point_nul(t_flags flags)
{
	ft_putncaract('+', flags.plus);
	ft_putchar('0');
	ft_putncaract('.', flags.hashtag);
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

int		width_noprec_point(long double dec, t_flags flags,
		t_check_float c_float)
{
	if (dec == 0.0)
		print_width_noprec_point_nul(flags);
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
					flags.plus);
		else
			ft_putncaract(' ', flags.width - c_float.nblen -
					flags.plus);
		ft_putstr(c_float.nbstr);
	}
	return (flags.width + flags.hashtag + flags.plus);
}

int		width_noprec_nopoint(long double dec, t_flags flags,
		t_check_float c_float)
{
	if (dec == 0.0 && flags.width > 8)
	{
		if (!flags.minus && !flags.hashtag && !flags.zero)
			print_width_noprec_nopoint(flags, 1);
		else if (flags.minus)
			print_width_noprec_nopoint(flags, 3);
		else if (flags.zero)
			print_width_noprec_nopoint(flags, 2);
		return (flags.width);
	}
	else if (dec == 0.0 && !(flags.width > 8))
	{
		print_width_noprec_nopoint(flags, 0);
		return (8 + flags.plus);
	}
	ft_putncaract(' ', c_float.size);
	ft_putstr(c_float.str);
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
		if (dec == 0.0)
			ft_putncaract('0', flags.precision);
		return (c_float.nblen + 1 + flags.precision + flags.plus);
	}
	return (0);
}

int		float_nowidth_prec(long double dec, long double decimal, int i,
		t_check_float c_float, t_flags flags)
{
	while (i != 0)
	{
		decimal *= 10.00;
		i--;
	}
	decimal = decimal - (int)decimal;
	decimal = (decimal * 10.00);
	if ((int)decimal >= 5 && c_float.str[ft_strlen(c_float.str) - 1] != 48)
	{
		if ((int)decimal != 9)
		{
			if (c_float.str[ft_strlen(c_float.str) - 1] != 48 &&
					c_float.str[ft_strlen(c_float.str) - 1] != '9')
				c_float.str[c_float.nblen + flags.precision] += 1;
		}
	}
	ft_putncaract('+', flags.plus);
	if (flags.plus == 0)
		ft_putncaract(' ', flags.space);
	return (float_nowidth_prec_sup_inf(dec, c_float, flags));
}

int		check_p_w_float(long double dec, t_flags flags)
{
	t_check_float	c_float;
	int				i;
	long double		decimal;

	i = flags.precision;
	c_float.nb = 0;
	c_float.str = ft_ftoa(dec, flags.precision);
	decimal = dec;
	c_float.len = (int)ft_strlen(c_float.str);
	get_parts(&c_float, flags, dec);
	/*if (c_float.size < 0)
		c_float.size = 0;
	if (flags.width && !flags.precision)
	{
		if (flags.point)
			c_float.nb += width_noprec_point(dec, flags, c_float);
		if (!flags.point)
			c_float.nb += width_noprec_nopoint(dec, flags, c_float);
	}
	if (flags.precision && !flags.width)
		c_float.nb += float_nowidth_prec(dec, decimal, i, c_float, flags);
	if (flags.precision && flags.width)
	{
		decimal = (flags.precision * (decimal * 10.00));
		decimal = decimal - (int)decimal;
		decimal = (decimal * 10.00);
		if ((int)decimal >= 5 && c_float.str[ft_strlen(c_float.str) - 1] != 48)
			if ((int)decimal != 9)
			{
				if (c_float.str[ft_strlen(c_float.str) - 1] != 48 &&
						c_float.str[ft_strlen(c_float.str) - 1] != '9')
					c_float.str[c_float.nblen + flags.precision] += 1;
			}
	}
	if (dec > 0)
		ft_putncaract('+', flags.plus);*/
	ft_putstr(c_float.str);
	ft_putncaract('0', flags.precision - ft_strlen(c_float.decstr) - flags.plus);
	c_float.nb += (int)ft_strlen(c_float.nbstr) + c_float.declen + flags.plus + 1;
	//ft_strdel(&c_float.str);
	return (c_float.nb);
}
