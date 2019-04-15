/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_octa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:43:11 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 16:03:12 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_p_w_octa(unsigned long dec, t_flags flags)
{
	int		size;
	char	*str;
	int		surplus;

	surplus = 0;
	if (!(str = dectoocta(dec, flags)))
		return (0);
	size = flags.width - ft_strlen(str);
	if (size < 0)
		size = 0;
	if (flags.width && !flags.precision)
	{
		if (flags.hashtag && flags.point)
		{
			if (dec != 0 && !(flags.width > ft_strlen(str)))
			{
				ft_putstr("0");
				surplus = 1;
			}
			else if (dec != 0 && flags.plus)
			{
				ft_putncaract(' ', size - 1);
				ft_putstr("0");
				ft_putstro(str, flags);
				return (flags.width);
			}
			else if (dec == 0)
			{
				if (flags.minus)
				{
					ft_putstr("0");
					ft_putncaract(' ', flags.width - 1);
				}
				else
				{
					ft_putncaract(' ', flags.width - 1);
					ft_putstr("0");
				}
				return (flags.width);
			}
		}
		if (flags.width > ft_strlen(str))
		{
			if (flags.minus)
			{
				if (flags.hashtag && surplus != 1 && dec != 0)
				{
					ft_putstr("0");
					surplus = 1;
				}
				if (dec != 0 || (dec == 0 && !flags.point))
					ft_putstro(str, flags);
				if (dec == 0 && flags.point)
					ft_putncaract(' ', flags.width);
				else
					ft_putncaract(' ', size - surplus);
			}
			else
			{
				if (flags.zero && !flags.point)
				{
					if (flags.hashtag && dec != 0 && surplus != 1)
					{
						ft_putstr("0");
						surplus = 1;
					}
					ft_putncaract('0', size - surplus);
					ft_putstro(str, flags);
					return(flags.width);
				}
				else
				{
					if (flags.width >= ft_strlen(str) + 1)
					{
						if (dec == 0 && !flags.hashtag)
							ft_putncaract(' ', flags.width);
						else if (dec == 0 && flags.hashtag)
							ft_putncaract(' ', flags.width - 1);
						else if (flags.hashtag && surplus != 1)
							ft_putncaract(' ', size - 1);
						else
							ft_putncaract(' ', size);
					}
					else
						ft_putncaract(' ', size);
				}
				if (flags.hashtag && dec != 0 && surplus != 1)
				{
					ft_putstr("0");
					surplus = 1;
				}
				if (dec != 0 || (dec == 0 && !flags.point))
					ft_putstro(str, flags);
			}
			return (flags.width);
		}
		else
		{
			if (flags.hashtag && dec != 0 && surplus != 1)
			{
				ft_putstr("0");
				surplus = 1;
			}
			if (ft_strlen(str) > 11 && !flags._l && !flags._h)
				ft_putncaract(' ', flags.width - 11);
			else if (ft_strlen(str) > 6 && flags._h == 1)
				ft_putncaract(' ', flags.width - 6);
			else if (ft_strlen(str) > 3 && flags._h == 2)
				ft_putncaract(' ', flags.width - 3);
			if (dec != 0 || (dec == 0 && flags.zero) || (dec == 0 && !flags.point))
				ft_putstro(str, flags);
			if (dec == 0 && flags.point)
				ft_putncaract(' ', flags.width);
			return (ft_strlen(str) + surplus);
		}
	}
	else if (flags.width && flags.precision)
	{
		if (flags.width > flags.precision)
		{
			if (flags.precision < ft_strlen(str))
			{
				if (flags.hashtag && dec != 0 && surplus != 1)
				{
					ft_putncaract(' ', size - 1);
					ft_putstr("0");
					surplus = 1;
				}
				else
					ft_putncaract(' ', size);
				ft_putstro(str, flags);
				if (flags.width > ft_strlen(str))
					return (flags.width);
				return (flags.width + surplus);
			}
			if (flags.hashtag && surplus != 1 && dec != 0)
			{
				ft_putstr("0");
				surplus = 1;
			}
			if (flags.minus)
			{
				ft_putncaract('0', (size - (flags.width - flags.precision)));
				ft_putstro(str, flags);
				ft_putncaract(' ', (flags.width - flags.precision));
				return(flags.width + surplus);
			}
			else
			{
				ft_putncaract(' ', flags.width - flags.precision);
				ft_putncaract('0', size - (flags.width - flags.precision));
				ft_putstro(str, flags);
				return (flags.width + surplus);
			}
		}
		else
		{
			if (flags.hashtag && dec != 0 && surplus != 1)
			{
				ft_putstr("0");
				surplus = 1;
			}
			ft_putncaract('0', flags.precision - ft_strlen(str));
			ft_putstro(str, flags);
			if (flags.precision > ft_strlen(str))
				return (flags.precision + surplus);
			return (ft_strlen(str) + surplus);
		}
	}
	else if (!flags.width && flags.precision)
	{
		if (flags.hashtag && dec != 0 && surplus != 1)
		{
			ft_putstr("0");
			surplus = 1;
		}
		if (flags.precision > ft_strlen(str))
		{
			if (ft_strlen(str) < 12)
				ft_putncaract('0', flags.precision - ft_strlen(str) - surplus);
			if (ft_strlen(str) > 11 && !flags._l && !flags._h)
				ft_putncaract('0', flags.precision - 11);
			if (ft_strlen(str) > 11 && flags._l && !flags._h)
				ft_putncaract('0', flags.precision - ft_strlen(str));
			if (ft_strlen(str) > 11 && !flags._l && flags._h == 1)
				ft_putncaract('0', flags.precision - 6);
			if (ft_strlen(str) > 11 && !flags._l && flags._h == 2)
				ft_putncaract('0', flags.precision - 3);
			ft_putstro(str, flags);
			return (flags.precision);
		}
		ft_putstro(str, flags);
		return (ft_strlen(str) + surplus);
	}
	else
	{
		if (flags.hashtag && dec != 0 && surplus != 1)
		{
			ft_putstr("0");
			surplus = 1;
		}
		if (dec != 0 || (dec == 0 && !flags.point && !flags.precision && !flags.width))
			ft_putstro(str, flags);
		if (dec != 0 || (dec == 0 && !flags.point))
			return (ft_strlen(str) + surplus);
		else
			return (surplus);
	}
	return (0);;
}

