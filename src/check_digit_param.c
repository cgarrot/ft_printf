/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_digit_param.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 10:26:37 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 10:32:42 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	digit_upper_0(long long digit, t_check_digit *c_dig, int chose)
{
	if (chose == 1)
		if (digit > 0)
			ft_putchar('+');
	if (chose == 2)
	{
		if (digit == 0)
			c_dig->yn++;
		else
			ft_putstr(c_dig->num);
	}
	if (chose == 3)
		if (digit > 0)
		{
			ft_putchar('+');
			c_dig->yn++;
		}
}

void	digit_lower_0(long long digit, t_check_digit *c_dig, t_flags flags)
{
	if (digit < 0)
	{
		ft_putchar('-');
		ft_strdel(&c_dig->num);
		if (!flags._l)
			c_dig->num = ft_itoa(c_dig->negdig);
		if (flags._l)
			c_dig->num = ft_lltoa(c_dig->negdig);
		c_dig->yn++;
	}
}

int		digit_plus_prec(long long digit, t_flags flags, t_check_digit c_dig)
{
	if ((flags.width > flags.precision && flags.precision >
				ft_strlen(c_dig.num)) || flags.precision > ft_strlen(c_dig.num))
	{
		if (flags.width > flags.precision)
			ft_putncaract(' ', (flags.width - flags.precision - 1));
		if (flags.width > flags.precision)
			c_dig.yn++;
		ft_putchar('+');
		ft_putncaract('0', (flags.precision - ft_strlen(c_dig.num)));
		ft_putstr(c_dig.num);
		if (c_dig.yn)
			return (flags.space + c_dig.unplus + flags.width - 1);
		return (c_dig.unplus + flags.precision);
	}
	else if (flags.precision < ft_strlen(c_dig.num))
	{
		if (flags.width > ft_strlen(c_dig.num))
			ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num) - 1));
		digit_upper_0(digit, &c_dig, 1);
		return (put_ret(c_dig.num, ft_strlen(c_dig.num) + flags.space + 1));
	}
	else
		digit_upper_0(digit, &c_dig, 1);
	return (put_ret(c_dig.num, ft_strlen(c_dig.num) + 1));
}

int		digit_plus_width(long long digit, t_flags flags, t_check_digit c_dig)
{
	digit_upper_0(digit, &c_dig, 3);
	if (!flags.minus && !flags.plus)
	{
		ft_putncaract('0', (flags.width - ft_strlen(c_dig.num) - c_dig.yn));
		c_dig.yn++;
	}
	ft_putstr(c_dig.num);
	if (flags.minus)
	{
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num) - c_dig.yn));
		return (flags.space + flags.width);
	}
	return (flags.space + flags.width - c_dig.yn);
}

int		digit_plus_width2(long long digit, t_flags flags, t_check_digit c_dig)
{
	if (flags.minus)
	{
		digit_upper_0(digit, &c_dig, 3);
		ft_putstr(c_dig.num);
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num) - c_dig.yn));
		return (flags.space + flags.width);
	}
	else if ((!flags.point && (flags.width > ft_strlen(c_dig.num))) ||
		((flags.point && (flags.width > ft_strlen(c_dig.num))) && flags.zero))
	{
		digit_upper_0(digit, &c_dig, 3);
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num) - c_dig.yn));
		return (put_ret(c_dig.num, flags.space + flags.width - c_dig.yn));
	}
	else if (flags.width < ft_strlen(c_dig.num))
	{
		digit_upper_0(digit, &c_dig, 1);
		return (put_ret(c_dig.num, ft_strlen(c_dig.num) + 1));
	}
	else
	{
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num)));
		digit_upper_0(digit, &c_dig, 3);
		return (put_ret(c_dig.num, flags.space + c_dig.yn + flags.width));
	}
}
