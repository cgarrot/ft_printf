/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_digit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:42:56 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 16:46:44 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_p_w_digit(long long digit, t_flags flags)
{
	char	*number;
	int		yesno;
	int		unsplus;
	long long		negdigit;
	int		space3;

	yesno = 0;
	space3 = 0;
	unsplus = 1;
	negdigit = digit;
	if (flags.flag == 'u')
		flags.plus = 0;
	if (digit < 0 && flags.flag != 'u')
		negdigit = -digit;
	if (flags.flag == 'u')
	{
		if (flags._l)
			number = ft_ulltoa(digit);
		else if (flags._h == 1)
			number = ft_uhtoa(digit);
		else if (flags._h == 2)
			number = ft_uhhtoa(digit);
		else
			number = ft_utoa(digit);
	}
	if (flags.flag == 'i' || flags.flag == 'd')
	{
		if (flags._l)
			number = ft_lltoa(digit);
		else if (flags._h == 1)
			number = ft_htoa(digit);
		else if (flags._h == 2)
			number = ft_hhtoa(digit);
		else
			number = ft_itoa(digit);
	}
	if (((flags.space && (digit >= 0) && !flags.plus)) &&
			(((digit == 0 && flags.space) || 1 < ft_strlen(number))
			|| flags.precision > ft_strlen(number)) && flags.flag != 'u')
		ft_putchar(' ');
	else if (flags.space)
	{
		flags.space = 0;
		space3 = 1;
	}
	if (flags.plus)
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
			{
				if (flags.width > flags.precision)
				{
					ft_putncaract(' ', (flags.width - flags.precision - 1));
					yesno++;
				}
				ft_putchar('+');
				ft_putncaract('0', (flags.precision - ft_strlen(number)));
				ft_putstr(number);
				if (yesno)
					return (ft_strlen(number) + flags.space + unsplus + (flags.precision - ft_strlen(number)) + (flags.width - flags.precision - 1));
				return (ft_strlen(number) + unsplus + (flags.precision - ft_strlen(number)));
			}
			else if (flags.precision < ft_strlen(number))
			{
				if (flags.width > ft_strlen(number))
					ft_putncaract(' ', (flags.width - ft_strlen(number) - 1));
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + 1);
			}
			else
			{
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return(ft_strlen(number) + 1);
			}
		}
		else if (flags.width)
		{
			if (!flags.point && flags.zero && (flags.width > ft_strlen(number)))
			{
				if (digit > 0)
				{
					ft_putchar('+');
					yesno++;
				}
				if (!flags.minus && !flags.plus)
				{
					ft_putncaract('0', (flags.width - ft_strlen(number) - yesno));
					yesno++;
				}
				ft_putstr(number);
				if (flags.minus)
				{
					ft_putncaract(' ', (flags.width - ft_strlen(number) - yesno));
					return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
				}
				return (ft_strlen(number) + flags.space + ((flags.width - ft_strlen(number)) - yesno));
			}
			else if (flags.minus)
			{
				if (digit > 0)
				{
					ft_putchar('+');
					yesno++;
				}
				ft_putstr(number);
				ft_putncaract(' ', (flags.width - ft_strlen(number) - yesno));
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
			}
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width > ft_strlen(number))) && flags.zero))
			{
				if (digit > 0)
					yesno++;
				ft_putncaract(' ', (flags.width - ft_strlen(number) - yesno));
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number) - yesno));
			}
			else if (flags.width < ft_strlen(number))
			{
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + 1);
			}
			else
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				if (digit > 0)
				{
					ft_putchar('+');
					yesno++;
				}
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + yesno + (flags.width - ft_strlen(number)));
			}
		}
		else
		{
			if (digit >= 0)
			{
				ft_putchar('+');
				if ((!flags.point && digit == 0) || digit != 0)
					yesno++;
			}
			if ((!flags.point && digit == 0) || digit != 0)
				ft_putstr(number);
			return (ft_strlen(number) + yesno + flags.space);
		}
	}
	else if (flags.minus)
	{
		if ((flags.width > flags.precision && flags.precision >= ft_strlen(number)) || flags.precision > ft_strlen(number))
		{
			if (digit < 0)
			{
				ft_putchar('-');
				ft_strdel(&number);
				if (!flags._l)
					number = ft_itoa(negdigit);
				if (flags._l)
					number = ft_lltoa(negdigit);
				yesno++;
			}
			ft_putncaract('0', (flags.precision - ft_strlen(number)));
			ft_putstr(number);
			if (flags.width > flags.precision)
			{
				ft_putncaract(' ', (flags.width - flags.precision - yesno));
				return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number) + (flags.width - flags.precision - yesno) + yesno));
			}
			return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number)) + yesno);
		}
		if (flags.precision < ft_strlen(number))
		{
			if (digit == 0)
				yesno++;
			else
				ft_putstr(number);
			if (flags.width > flags.precision)
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number) + yesno));
				if ((flags.width < ft_strlen(number)))
					return (ft_strlen(number) + flags.space);
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
			}
			return (ft_strlen(number) + flags.space);
		}
	}
	else
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision >= ft_strlen(number))
			{
				if (flags.width > flags.precision)
				{
					ft_putncaract(' ', (flags.width - flags.precision));
					yesno++;
				}
				if (digit < 0)
				{
					ft_putchar('-');
					ft_strdel(&number);
					if (!flags._l)
						number = ft_itoa(negdigit);
					if (flags._l)
						number = ft_lltoa(negdigit);
					yesno++;
				}
				ft_putncaract('0', (flags.precision - ft_strlen(number)));
				ft_putstr(number);
				if (flags.width > flags.precision)
					return ((flags.width - flags.precision) + flags.space + (flags.precision - ft_strlen(number)) + yesno);
				return ((flags.precision - ft_strlen(number) + flags.space + ft_strlen(number)) + yesno);
			}
			if (flags.precision < ft_strlen(number))
			{
				if (flags.precision < 1)
				{
					ft_putncaract(' ', (flags.width - ft_strlen(number)));
					yesno++;
				}
				ft_putstr(number);
				if (yesno)
					return ((flags.width - ft_strlen(number) + flags.space + ft_strlen(number)));
				return (ft_strlen(number));
			}
		}
		else if (flags.width)
		{
			if (!flags.point && flags.zero && (flags.width > ft_strlen(number)))
			{
				if (digit < 0)
				{
					ft_putchar('-');
					ft_strdel(&number);
					if (!flags._l)
						number = ft_itoa(negdigit);
					if (flags._l)
						number = ft_lltoa(negdigit);
					yesno++;
				}
				ft_putncaract('0', (flags.width - ft_strlen(number) - yesno));
				ft_putstr(number);
				return (flags.width - ft_strlen(number) + flags.space + ft_strlen(number));
			}
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width >= ft_strlen(number)))))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				if (digit != 0)
				{
					if (space3 == 1 && flags.width == 1 && ft_strlen(number) < 2)
						ft_putchar(' ');
					ft_putstr(number);
					return (flags.width + flags.space + space3);
				}
				else
					ft_putchar(' ');
				return (flags.width - ft_strlen(number) + flags.space + ft_strlen(number));
			}
			else
			{
				ft_putstr(number);
				return (ft_strlen(number) + flags.space);
			}
		}
		else if ((digit == 0 && !flags.point) || digit != 0)
		{
			ft_putstr(number);
			return (ft_strlen(number) + flags.space);
		}
	}
	return (0 + flags.space);
}

