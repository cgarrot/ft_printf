/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 11:28:43 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 16:39:26 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	get_parts(t_check_float *c_float, t_flags flags, int dec)
{
	c_float->nblen = 0;
	while (c_float->str[c_float->nblen] != '.')
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
}

int		check_p_w_float(long double dec, t_flags flags)
{
	t_check_float	c_float;
	char	*zob;
	zob = ft_strnew(0);
	int i;
	long double decimal;

	i = flags.precision;
	c_float.str = ft_strnew(0);
	c_float.str = ft_ftoa(dec, c_float.str, flags);
	zob = c_float.str;
	decimal = dec;
		//printf("str : [%s]\n", c_float.str);

	get_parts(&c_float, flags, dec);
	c_float.str = zob;
//printf("str : [%s]\n", zob);
	if (c_float.size < 0)
		c_float.size = 0;
	if (flags.width && !flags.precision)
	{
		if (flags.point)
		{
			if (dec == 0.0)
			{
				if (!flags.minus && !flags.zero)
				{
					ft_putncaract(' ', flags.width - 1 - flags.plus - flags.hashtag);
					ft_putncaract('+', flags.plus);
					ft_putchar('0');
					ft_putncaract('.', flags.hashtag);
				}
				else if (flags.minus)
				{
					ft_putncaract('+', flags.plus);
					ft_putchar('0');
					ft_putncaract('.', flags.hashtag);
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
			if (flags.minus)
			{
				ft_putncaract('+', flags.plus);
				ft_putstr(c_float.nbstr);
				ft_putncaract(' ', (flags.width - c_float.nblen - flags.plus));
			}
			else
			{
				if (flags.zero)
					ft_putncaract('0', flags.width - c_float.nblen - flags.plus);
				else
					ft_putncaract(' ', flags.width - c_float.nblen - flags.plus);
				ft_putncaract('+', flags.plus);
				ft_putstr(c_float.nbstr);
			}
			return (flags.width + flags.hashtag + flags.plus);
		}
		if (!flags.point)
		{
			if (dec == 0.0 && flags.width > 8)
			{
				if (!flags.minus && !flags.hashtag && !flags.zero)
				{
					ft_putncaract(' ', flags.width - 8 - flags.plus);
					ft_putncaract('+', flags.plus);
					ft_putstr("0.000000");
				}
				else if (flags.minus)
				{
					ft_putncaract('+', flags.plus);
					ft_putstr("0.000000");
					ft_putncaract(' ', flags.width - 8 - flags.plus);
				}
				else if (flags.zero)
				{
					ft_putncaract('+', flags.plus);
					ft_putncaract('0', flags.width - 8 - flags.plus);
					ft_putstr("0.000000");
				}
				return (flags.width);
			}
			else if (dec == 0.0 && !(flags.width > 8))
			{
				ft_putncaract('+', flags.plus);
				ft_putstr("0.000000");
				return (8 + flags.plus);
			}
			ft_putncaract(' ', c_float.size);
			//printf("%s, %s\n", c_float.nbstr, c_float.decstr);
			ft_putstr(c_float.str);
		}
		return (flags.width);
	}



	if (flags.precision && !flags.width)
	{

		//i = flags.precision;
		while (i != 0)
		{
			decimal *= 10.00;
			i--;
		}
		decimal = decimal - (int)dec;
		decimal = (decimal * 10.00);
		//printf("c_float.str |%s|\n", c_float.str);
		//printf("len|%ld|\n", ft_strlen(c_float.str));
		//printf("nblen : %d\n", c_float.nblen);
		if ((int)decimal >= 5 && c_float.str[ft_strlen(c_float.str) - 1] != 48)
		{
			if ((int)decimal != 9)
			{
				printf("iIMPORTANT ! duzob c_float.str[] : %c\n", c_float.str[ft_strlen(c_float.str) - 1]);
				if (c_float.str[ft_strlen(c_float.str) - 1] != 48 &&
						c_float.str[ft_strlen(c_float.str) - 1] != '9')
					c_float.str[c_float.nblen + flags.precision] += 1;
				//else if (flags.precision == 1)
				//	c_float.str[c_float.nblen + flags.precision] += 1;
			}
		}


			
			ft_putncaract('+', flags.plus);
			if (flags.plus == 0)
				ft_putncaract(' ', flags.space);
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
	}
	if (flags.precision && flags.width)
	{
		//printf("%Lf\n", dec);

		decimal = (flags.precision * (decimal * 10.00));
		decimal = decimal - (int)decimal;
		decimal = (decimal * 10.00);
		//printf("%Lf\n", dec);
		//printf("skurt :  %s\n", c_float.str);
		//printf("zob : |%ld|\n", ft_strlen(c_float.str));
		if ((int)decimal >= 5 && c_float.str[ft_strlen(c_float.str) - 1] != 48)
		{
			if ((int)decimal != 9)
			{
				if (c_float.str[ft_strlen(c_float.str) - 1] != 48 &&
						c_float.str[ft_strlen(c_float.str) - 1] != '9')
					c_float.str[c_float.nblen + flags.precision] += 1;
				//else if (flags.precision == 1)
				//	c_float.str[c_float.nblen + flags.precision] += 1;
			}
		}
	}
		if (dec > 0)
			ft_putncaract('+', flags.plus);
		//ft_putstr(c_float.nbstr);
		//ft_putstr(c_float.decstr);

		ft_putstr(c_float.str);
		ft_putncaract('0', flags.precision - ft_strlen(c_float.decstr) - flags.plus);
		return (ft_strlen(c_float.nbstr) + c_float.declen + flags.plus + 1);
	if (dec > 0)
		ft_putncaract('+', flags.plus);
	ft_putstr(c_float.str);
	return (ft_strlen(c_float.str) + flags.plus);
}
