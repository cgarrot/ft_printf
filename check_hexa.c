/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_hexa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:43:42 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 16:48:06 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_p_w_hexa(unsigned long long dec, t_flags flags)
{
	int		size;
	char	*str;
	int		surplus;

	//2147483647
	//922337203685477
	surplus = 0;
	str = dectohexa(dec);
	if (flags.flag == 'X')
		str = ft_strcapitalize(str);
	size = flags.width - ft_strlen(str);
	//printf("\nstrlen : %d\n", ft_strlen(str));
	if (size < 0)
		size = 0;
	if (flags.width && !flags.precision)
	{

		if (flags.hashtag && flags.point)
		{
			if ((dec != 0 && !(flags.flag == 'p') && !(flags.width > ft_strlen(str))) || (flags.flag == 'p' && flags.minus))
			{
				ft_puthash(flags);
				surplus = 2;
			}
			else if ((dec != 0 && flags.plus) || (flags.flag == 'p'))
			{
				if (dec != 0) 
					ft_putncaract(' ', (flags.width - ft_strlen(str) - 2));
				else
					ft_putncaract(' ', (flags.width - 2));
				ft_puthash(flags);
				surplus = 2;
				if (dec != 0)
					ft_putstrx(str, flags);
				if (flags.width > ft_strlen(str))
					return (flags.width);
				else
				{
					if (dec == 0)
						return (surplus);
					else
						return (ft_strlen(str) + surplus);
				}
			}
		}
		if (flags.hashtag && flags.point && dec == 0)
		{
			if (!(flags.flag == 'p'))
			{
				ft_putncaract(' ', flags.width);
				return (flags.width + surplus);
			}
			else if (flags.flag == 'p')
				ft_putncaract(' ', flags.width - surplus);
			return (flags.width);
		}
		if (flags.width > ft_strlen(str))
		{
			if (flags.minus)
			{
				if ((flags.flag == 'p' && surplus != 2) || (flags.hashtag && dec != 0 && surplus != 2))
				{
					ft_puthash(flags);
					surplus = 2;
				}
				if (dec != 0)
				{
					ft_putstrx(str, flags);
					ft_putncaract(' ', (flags.width - ft_strlen(str) - surplus));
				}
				else
					ft_putncaract(' ', (flags.width - ft_strlen(str) - surplus + 1));
			}
			else
			{
				if (flags.zero && !flags.point && !(flags.flag == 'p'))
				{
					if (flags.hashtag && dec != 0 && surplus != 2 && !(flags.flag == 'p'))
					{
						ft_puthash(flags);
						surplus = 2;
					}
					ft_putncaract('0', (size - surplus));
					ft_putstrx(str, flags);
					return (flags.width);
				}
				if (flags.flag == 'p')
				{
					ft_putncaract(' ', size - 2);
					ft_puthash(flags);
				}
				else
				{
					if ((flags.width >= (ft_strlen(str) + 2)) && flags.hashtag && surplus != 2)
					{
						surplus = 2;
						ft_putncaract(' ', size - surplus);
						surplus = 0;
					}
					else
					{
						if (dec == 0)
							size++;
						ft_putncaract(' ', size - surplus);
					}
				}
				if (flags.hashtag && dec != 0 && surplus != 2 && !(flags.flag == 'p'))
				{
					ft_puthash(flags);
					surplus = 2;
				}
				if (dec != 0)
					ft_putstrx(str, flags);
			}
			if (flags.flag == 'p' && flags.minus && flags.width <= ft_strlen(str))
				return (flags.width);
			if (flags.flag == 'p' && flags.minus && flags.width == ft_strlen(str) + 1)
				return (ft_strlen(str) + surplus);
			return (flags.width);
		}
		else
		{
			if (flags.hashtag && dec != 0 && surplus != 2)
			{
				ft_puthash(flags);
				surplus = 2;
			}
			if (!flags._h && !flags._l && ft_strlen(str) > 8)
				ft_putncaract(' ', flags.width - 8);
			else if (flags._h == 1 && ft_strlen(str) > 4)
				ft_putncaract(' ', flags.width - 4);
			else if (flags._h == 2 && ft_strlen(str) > 2)
				ft_putncaract(' ', flags.width - 2);
			if (dec != 0 || (flags._h && dec == 0))
				ft_putstrx(str, flags);
			else
				ft_putncaract(' ', 1);
			return (ft_strlen(str) + surplus);
		}
	}
	else if (flags.width && flags.precision)
	{
		if (flags.flag == 'p' && dec != 0)
		{
			ft_puthash(flags);
			surplus = 2;
		}
		if (flags.width > flags.precision)
		{
			if (flags.precision < ft_strlen(str))
			{
				if (flags.hashtag)
				{
					ft_putncaract(' ', flags.width - ft_strlen(str) - 2);
					if (dec != 0 && surplus != 2)
					{
						ft_puthash(flags);
						surplus = 2;
					}
				}
				else
					ft_putncaract(' ', flags.width - ft_strlen(str));
				ft_putstrx(str, flags);
				if (flags.width > ft_strlen(str) + 1)
					return (flags.width);
				else
					return (ft_strlen(str) + surplus);
			}
			if (!flags.minus)
			{
				if (flags.hashtag && dec != 0 && surplus != 2)
				{
					ft_puthash(flags);
					surplus = 2;
				}
				if (!(flags.flag == 'p'))
					ft_putncaract(' ', (flags.width - flags.precision - surplus));
				ft_putncaract('0', (flags.width - ft_strlen(str) - (flags.width - flags.precision)));
				ft_putstrx(str, flags);
				if (flags.width > 2)
					return (flags.width);
				else
					return(flags.width + ft_strlen(str));
			}
			else
			{
				ft_putncaract('0', (flags.width - ft_strlen(str) - (flags.width - flags.precision)));
				ft_putstrx(str, flags);
				if (!(flags.flag == 'p'))
					ft_putncaract(' ', (flags.width - flags.precision));
				else
					ft_putncaract(' ', (flags.width - flags.precision - surplus));
				return (flags.width);
			}
		}
		else if (flags.width < flags.precision || flags.width == flags.precision)
		{
			if (flags.hashtag && dec != 0 && surplus != 2)
			{
				ft_puthash(flags);
				surplus = 2;
			}
			ft_putncaract('0', (flags.precision - ft_strlen(str)));
			ft_putstrx(str, flags);
			if (flags.precision > ft_strlen(str))
				return (flags.precision + surplus);
			else
				return (ft_strlen(str) + surplus);
		}
	}
	else if (!flags.width && flags.precision)
	{
		if (flags.hashtag)
		{
			if (dec != 0 || flags.flag == 'p')
			{
				ft_puthash(flags);
				surplus = 2;
			}
		}
		if (flags.precision > ft_strlen(str))
		{
			if (ft_strlen(str) < 9)
				ft_putncaract('0', flags.precision - ft_strlen(str));
			if (ft_strlen(str) > 8 && !flags._l && !flags._h)
				ft_putncaract('0', flags.precision - 8);
			if (ft_strlen(str) > 8 && !flags._l && flags._h == 1)
				ft_putncaract('0', flags.precision - 4);
			if (ft_strlen(str) > 8 && !flags._l && flags._h == 2)
				ft_putncaract('0', flags.precision - 2);
			if (ft_strlen(str) > 8 && flags._l && !flags._h)
				ft_putncaract('0', flags.precision - ft_strlen(str));
			ft_putstrx(str, flags);
			return (flags.precision + surplus);
		}
		else
		{
			ft_putstrx(str, flags);
			return (ft_strlen(str) + surplus);
		}
	}
	else
	{
		if (flags.hashtag)
		{
			if (dec != 0 || flags.flag == 'p')
			{
				ft_puthash(flags);
				surplus = 2;
			}
		}
		if (flags.flag == 'x' || flags.flag == 'X')
		{
			if (!(dec == 0  && flags.point))
			{
				ft_putstrx(str, flags);
				return (ft_strlen(str) + surplus);
			}
		}
		else
		{
			if (dec != 0)
			{
				ft_putstrx(str, flags);
				return (ft_strlen(str) + surplus);
			}
			else if (dec == 0 && !flags.point)
			{

				ft_putstrx(str, flags);
				return (ft_strlen(str) + surplus);
			}
			return (surplus);
		}
	}
	return (0);
}

