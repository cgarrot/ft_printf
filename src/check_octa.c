/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_octa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:43:11 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 13:01:10 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_octa_hash(unsigned long dec, t_flags flags, t_check_octa c_octa)
{
	if (dec != 0 && !(flags.width > ft_strlen(c_octa.str)))
	{
		ft_putstr("0");
		c_octa.surplus = 1;
	}
	else if (dec != 0 && flags.plus)
	{
		ft_putncaract(' ', c_octa.size - 1);
		ft_putstr("0");
		ft_putstro(c_octa.str, flags);
		return (flags.width);
	}
	else if (flags.minus && dec == 0)
	{
		ft_putstr("0");
		ft_putncaract(' ', flags.width - 1);
		return (flags.width);
	}
	else if (dec == 0)
	{
		ft_putncaract(' ', flags.width - 1);
		ft_putstr("0");
		return (flags.width);
	}
	return (-1);
}

int		is_octa_width(unsigned long dec, t_flags flags, t_check_octa c_octa)
{
	if (flags.hashtag && flags.point)
		if (is_octa_hash(dec, flags, c_octa) != -1)
			return (is_octa_hash(dec, flags, c_octa));
	if (flags.width > ft_strlen(c_octa.str))
	{
		if (flags.hashtag && c_octa.surplus != 1 && dec != 0 && flags.minus)
		{
			ft_putstr("0");
			c_octa.surplus = 1;
		}
		if ((dec != 0 || (dec == 0 && !flags.point)) && flags.minus)
			ft_putstro(c_octa.str, flags);
		if (dec == 0 && flags.point && flags.minus)
			ft_putncaract(' ', flags.width);
		else if (flags.minus)
			ft_putncaract(' ', c_octa.size - c_octa.surplus);
		else
		{
			if (flags.zero && !flags.point)
			{
				if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
				{
					ft_putstr("0");
					c_octa.surplus = 1;
				}
				ft_putncaract('0', c_octa.size - c_octa.surplus);
				ft_putstro(c_octa.str, flags);
				return(flags.width);
			}
			else
			{
				if (flags.width >= ft_strlen(c_octa.str) + 1)
				{
					if (dec == 0 && !flags.hashtag)
						ft_putncaract(' ', flags.width);
					else if (dec == 0 && flags.hashtag)
						ft_putncaract(' ', flags.width - 1);
					else if (flags.hashtag && c_octa.surplus != 1)
						ft_putncaract(' ', c_octa.size - 1);
					else
						ft_putncaract(' ', c_octa.size);
				}
				else
					ft_putncaract(' ', c_octa.size);
			}
			if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
			{
				ft_putstr("0");
				c_octa.surplus = 1;
			}
			if (dec != 0 || (dec == 0 && !flags.point))
				ft_putstro(c_octa.str, flags);
		}
		return (flags.width);
	}
	else
	{
		if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
		{
			ft_putstr("0");
			c_octa.surplus = 1;
		}
		if (ft_strlen(c_octa.str) > 11 && !flags._l && !flags._h)
			ft_putncaract(' ', flags.width - 11);
		else if (ft_strlen(c_octa.str) > 6 && flags._h == 1)
			ft_putncaract(' ', flags.width - 6);
		else if (ft_strlen(c_octa.str) > 3 && flags._h == 2)
			ft_putncaract(' ', flags.width - 3);
		if (dec != 0 || (dec == 0 && flags.zero) || (dec == 0 && !flags.point))
			ft_putstro(c_octa.str, flags);
		if (dec == 0 && flags.point)
			ft_putncaract(' ', flags.width);
		return (ft_strlen(c_octa.str) + c_octa.surplus);
	}
	return (0);
}

int		check_p_w_octa(unsigned long dec, t_flags flags)
{
	t_check_octa	c_octa;

	c_octa.surplus = 0;
	if (!(c_octa.str = dectoocta(dec, flags)))
		return (0);
	c_octa.size = flags.width - ft_strlen(c_octa.str);
	if (c_octa.size < 0)
		c_octa.size = 0;
	if (flags.width && !flags.precision)
		return (is_octa_width(dec, flags, c_octa));
	else if (flags.width && flags.precision)
	{
		if (flags.width > flags.precision)
		{
			if (flags.precision < ft_strlen(c_octa.str))
			{
				if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
				{
					ft_putncaract(' ', c_octa.size - 1);
					ft_putstr("0");
					c_octa.surplus = 1;
				}
				else
					ft_putncaract(' ', c_octa.size);
				ft_putstro(c_octa.str, flags);
				if (flags.width > ft_strlen(c_octa.str))
					return (flags.width);
				return (flags.width + c_octa.surplus);
			}
			if (flags.hashtag && c_octa.surplus != 1 && dec != 0)
			{
				ft_putstr("0");
				c_octa.surplus = 1;
			}
			if (flags.minus)
			{
				ft_putncaract('0', (c_octa.size - (flags.width - flags.precision)));
				ft_putstro(c_octa.str, flags);
				ft_putncaract(' ', (flags.width - flags.precision));
				return(flags.width + c_octa.surplus);
			}
			else
			{
				ft_putncaract(' ', flags.width - flags.precision);
				ft_putncaract('0', c_octa.size - (flags.width - flags.precision));
				ft_putstro(c_octa.str, flags);
				return (flags.width + c_octa.surplus);
			}
		}
		else
		{
			if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
			{
				ft_putstr("0");
				c_octa.surplus = 1;
			}
			ft_putncaract('0', flags.precision - ft_strlen(c_octa.str));
			ft_putstro(c_octa.str, flags);
			if (flags.precision > ft_strlen(c_octa.str))
				return (flags.precision + c_octa.surplus);
			return (ft_strlen(c_octa.str) + c_octa.surplus);
		}
	}
	else if (!flags.width && flags.precision)
	{
		if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
		{
			ft_putstr("0");
			c_octa.surplus = 1;
		}
		if (flags.precision > ft_strlen(c_octa.str))
		{
			if (ft_strlen(c_octa.str) < 12)
				ft_putncaract('0', flags.precision - ft_strlen(c_octa.str) - c_octa.surplus);
			if (ft_strlen(c_octa.str) > 11 && !flags._l && !flags._h)
				ft_putncaract('0', flags.precision - 11);
			if (ft_strlen(c_octa.str) > 11 && flags._l && !flags._h)
				ft_putncaract('0', flags.precision - ft_strlen(c_octa.str));
			if (ft_strlen(c_octa.str) > 11 && !flags._l && flags._h == 1)
				ft_putncaract('0', flags.precision - 6);
			if (ft_strlen(c_octa.str) > 11 && !flags._l && flags._h == 2)
				ft_putncaract('0', flags.precision - 3);
			ft_putstro(c_octa.str, flags);
			return (flags.precision);
		}
		ft_putstro(c_octa.str, flags);
		return (ft_strlen(c_octa.str) + c_octa.surplus);
	}
	else
	{
		if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
		{
			ft_putstr("0");
			c_octa.surplus = 1;
		}
		if (dec != 0 || (dec == 0 && !flags.point && !flags.precision && !flags.width))
			ft_putstro(c_octa.str, flags);
		if (dec != 0 || (dec == 0 && !flags.point))
			return (ft_strlen(c_octa.str) + c_octa.surplus);
		else
			return (c_octa.surplus);
	}
	return (0);;
}

