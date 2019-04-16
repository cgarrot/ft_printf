/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_hexa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:43:42 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 10:17:39 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_hexa_width(unsigned long long dec, t_flags flags, t_check_hexa c_hexa)
{
	if ((dec != 0 && !(flags.flag == 'p') && !(flags.width >
					ft_strlen(c_hexa.str))) || (flags.flag == 'p' && flags.minus))
	{
		ft_puthash(flags);
		c_hexa.surplus = 2;
	}
	else if ((dec != 0 && flags.plus) || (flags.flag == 'p'))
	{
		if (dec != 0) 
			ft_putncaract(' ', (flags.width - ft_strlen(c_hexa.str) - 2));
		else
			ft_putncaract(' ', (flags.width - 2));
		ft_puthash(flags);
		c_hexa.surplus = 2;
		if (dec != 0)
			ft_putstrx(c_hexa.str, flags);
		if (flags.width > ft_strlen(c_hexa.str))
			return (flags.width);
		else if (dec == 0)
			return (c_hexa.surplus);
		else
			return (ft_strlen(c_hexa.str) + c_hexa.surplus);
	}
	return (-1);
}

int		is_hexa_width_small(unsigned long long dec, t_flags flags, t_check_hexa c_hexa)
{
	if (((flags.flag == 'p' && c_hexa.surplus != 2) || (flags.hashtag
					&& dec != 0 && c_hexa.surplus != 2)) && flags.minus)
	{
		ft_puthash(flags);
		c_hexa.surplus = 2;
	}
	if (dec != 0 && flags.minus)
	{
		ft_putstrx(c_hexa.str, flags);
		ft_putncaract(' ', (flags.width - ft_strlen(c_hexa.str) - c_hexa.surplus));
	}
	else if (flags.minus)
		ft_putncaract(' ', (flags.width - ft_strlen(c_hexa.str) - c_hexa.surplus + 1));
	else
	{
		if (flags.zero && !flags.point && !(flags.flag == 'p'))
		{
			if (flags.hashtag && dec != 0 && c_hexa.surplus != 2 && !(flags.flag == 'p'))
			{
				ft_puthash(flags);
				c_hexa.surplus = 2;
			}
			ft_putncaract('0', (c_hexa.size - c_hexa.surplus));
			ft_putstrx(c_hexa.str, flags);
			return (flags.width);
		}
		if (flags.flag == 'p')
		{
			ft_putncaract(' ', c_hexa.size - 2);
			ft_puthash(flags);
		}
		else if ((flags.width >= (ft_strlen(c_hexa.str) + 2)) && flags.hashtag
				&& c_hexa.surplus != 2)
		{
			c_hexa.surplus = 2;
			ft_putncaract(' ', c_hexa.size - c_hexa.surplus);
			c_hexa.surplus = 0;
		}
		else
		{
			if (dec == 0)
				c_hexa.size++;
			ft_putncaract(' ', c_hexa.size - c_hexa.surplus);
		}
		if (flags.hashtag && dec != 0 && c_hexa.surplus != 2 && !(flags.flag == 'p'))
		{
			ft_puthash(flags);
			c_hexa.surplus = 2;
		}
		if (dec != 0 || (flags.flag == 'p' && dec == 0))
			ft_putstrx(c_hexa.str, flags);
	}
	if (flags.flag == 'p' && flags.minus && flags.width <= ft_strlen(c_hexa.str))
		return (flags.width);
	if (flags.flag == 'p' && flags.minus && flags.width == ft_strlen(c_hexa.str) + 1)
		return (ft_strlen(c_hexa.str) + c_hexa.surplus);
	return (flags.width);
}

int		check_p_w_hexa(unsigned long long dec, t_flags flags)
{
	t_check_hexa	c_hexa;

	c_hexa.surplus = 0;
	c_hexa.str = dectohexa(dec);
	if (flags.flag == 'X')
		c_hexa.str = ft_strcapitalize(c_hexa.str);
	c_hexa.size = flags.width - ft_strlen(c_hexa.str);
	if (c_hexa.size < 0)
		c_hexa.size = 0;
	if (flags.width && !flags.precision)
	{
		if (flags.hashtag && flags.point)
			if (is_hexa_width(dec, flags, c_hexa) != -1)
				return (is_hexa_width(dec, flags, c_hexa));
		if (flags.hashtag && flags.point && dec == 0)
		{
			if (!(flags.flag == 'p'))
			{
				ft_putncaract(' ', flags.width);
				return (flags.width + c_hexa.surplus);
			}
			else if (flags.flag == 'p')
				ft_putncaract(' ', flags.width - c_hexa.surplus);
			return (flags.width);
		}
		if (flags.width > ft_strlen(c_hexa.str))
			return (is_hexa_width_small(dec, flags, c_hexa));
		else
		{
			if (flags.hashtag && dec != 0 && c_hexa.surplus != 2)
			{
				ft_puthash(flags);
				c_hexa.surplus = 2;
			}
			if (!flags._h && !flags._l && ft_strlen(c_hexa.str) > 8)
				ft_putncaract(' ', flags.width - 8);
			else if (flags._h == 1 && ft_strlen(c_hexa.str) > 4)
				ft_putncaract(' ', flags.width - 4);
			else if (flags._h == 2 && ft_strlen(c_hexa.str) > 2)
				ft_putncaract(' ', flags.width - 2);
			if (dec != 0 || (flags._h && dec == 0))
				ft_putstrx(c_hexa.str, flags);
			else
				ft_putncaract(' ', 1);
			return (ft_strlen(c_hexa.str) + c_hexa.surplus);
		}
	}
	else if (flags.width && flags.precision)
	{
		if (flags.flag == 'p' && dec != 0)
		{
			ft_puthash(flags);
			c_hexa.surplus = 2;
		}
		if (flags.width > flags.precision)
		{
			if (flags.precision < ft_strlen(c_hexa.str))
			{
				if (flags.hashtag)
				{
					ft_putncaract(' ', flags.width - ft_strlen(c_hexa.str) - 2);
					if (dec != 0 && c_hexa.surplus != 2)
					{
						ft_puthash(flags);
						c_hexa.surplus = 2;
					}
				}
				else
					ft_putncaract(' ', flags.width - ft_strlen(c_hexa.str));
				ft_putstrx(c_hexa.str, flags);
				if (flags.width > ft_strlen(c_hexa.str) + 1)
					return (flags.width);
				else
					return (ft_strlen(c_hexa.str) + c_hexa.surplus);
			}
			if (!flags.minus)
			{
				if (flags.hashtag && dec != 0 && c_hexa.surplus != 2)
				{
					ft_puthash(flags);
					c_hexa.surplus = 2;
				}
				if (!(flags.flag == 'p'))
					ft_putncaract(' ', (flags.width - flags.precision - c_hexa.surplus));
				ft_putncaract('0', (flags.width - ft_strlen(c_hexa.str) - (flags.width - flags.precision)));
				ft_putstrx(c_hexa.str, flags);
				if (flags.width > 2)
					return (flags.width);
				else
					return(flags.width + ft_strlen(c_hexa.str));
			}
			else
			{
				ft_putncaract('0', (flags.width - ft_strlen(c_hexa.str) - (flags.width - flags.precision)));
				ft_putstrx(c_hexa.str, flags);
				if (!(flags.flag == 'p'))
					ft_putncaract(' ', (flags.width - flags.precision));
				else
					ft_putncaract(' ', (flags.width - flags.precision - c_hexa.surplus));
				return (flags.width);
			}
		}
		else if (flags.width < flags.precision || flags.width == flags.precision)
		{
			if (flags.hashtag && dec != 0 && c_hexa.surplus != 2)
			{
				ft_puthash(flags);
				c_hexa.surplus = 2;
			}
			ft_putncaract('0', (flags.precision - ft_strlen(c_hexa.str)));
			ft_putstrx(c_hexa.str, flags);
			if (flags.precision > ft_strlen(c_hexa.str))
				return (flags.precision + c_hexa.surplus);
			else
				return (ft_strlen(c_hexa.str) + c_hexa.surplus);
		}
	}
	else if (!flags.width && flags.precision)
	{
		if (flags.hashtag)
		{
			if (dec != 0 || flags.flag == 'p')
			{
				ft_puthash(flags);
				c_hexa.surplus = 2;
			}
		}
		if (flags.precision > ft_strlen(c_hexa.str))
		{
			if (ft_strlen(c_hexa.str) < 9)
				ft_putncaract('0', flags.precision - ft_strlen(c_hexa.str));
			if (ft_strlen(c_hexa.str) > 8 && !flags._l && !flags._h)
				ft_putncaract('0', flags.precision - 8);
			if (ft_strlen(c_hexa.str) > 8 && !flags._l && flags._h == 1)
				ft_putncaract('0', flags.precision - 4);
			if (ft_strlen(c_hexa.str) > 8 && !flags._l && flags._h == 2)
				ft_putncaract('0', flags.precision - 2);
			if (ft_strlen(c_hexa.str) > 8 && flags._l && !flags._h)
				ft_putncaract('0', flags.precision - ft_strlen(c_hexa.str));
			ft_putstrx(c_hexa.str, flags);
			return (flags.precision + c_hexa.surplus);
		}
		else
		{
			ft_putstrx(c_hexa.str, flags);
			return (ft_strlen(c_hexa.str) + c_hexa.surplus);
		}
	}
	else
	{
		if (flags.hashtag)
		{
			if (dec != 0 || flags.flag == 'p')
			{
				ft_puthash(flags);
				c_hexa.surplus = 2;
			}
		}
		if (flags.flag == 'x' || flags.flag == 'X')
		{
			if (!(dec == 0  && flags.point))
			{
				ft_putstrx(c_hexa.str, flags);
				return (ft_strlen(c_hexa.str) + c_hexa.surplus);
			}
		}
		else
		{
			if (dec != 0)
			{
				ft_putstrx(c_hexa.str, flags);
				return (ft_strlen(c_hexa.str) + c_hexa.surplus);
			}
			else if (dec == 0 && !flags.point)
			{
				ft_putstrx(c_hexa.str, flags);
				return (ft_strlen(c_hexa.str) + c_hexa.surplus);
			}
			return (c_hexa.surplus);
		}
	}
	return (0);
}

