/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_digit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:42:56 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 20:18:15 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_check_digit		init_digit(t_check_digit c_dig, long long digit)
{
	c_dig.yn = 0;
	c_dig.space = 0;
	c_dig.unplus = 1;
	c_dig.negdig = digit;
	return (c_dig);
}

int		put_ret(char *str, int len)
{
	ft_putstr(str);
	return (len);
}

char	*make_str(long long digit, t_flags flags, char *str)
{
	if (flags.flag == 'u')
	{
		if (flags._l)
			str = ft_ulltoa(digit);
		else if (flags._h == 1)
			str = ft_uhtoa(digit);
		else if (flags._h == 2)
			str = ft_uhhtoa(digit);
		else
			str = ft_utoa(digit);
	}
	if (flags.flag == 'i' || flags.flag == 'd')
	{
		if (flags._l)
			str = ft_lltoa(digit);
		else if (flags._h == 1)
			str = ft_htoa(digit);
		else if (flags._h == 2)
			str = ft_hhtoa(digit);
		else
			str = ft_itoa(digit);
	}
	return (str);
}

void			is_space(long long digit, t_flags *flags, t_check_digit *c_dig)
{
	if (((flags->space && (digit >= 0) && !flags->plus)) &&
			(((digit == 0 && flags->space) || 1 < ft_strlen(c_dig->num))
			|| flags->precision > ft_strlen(c_dig->num)) && flags->flag != 'u')
		ft_putchar(' ');
	else if (flags->space)
	{
		flags->space = 0;
		c_dig->space = 1;
	}
}

void		digit_upper_0(long long digit, t_check_digit *c_dig, int chose)
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

void		digit_lower_0(long long digit, t_check_digit *c_dig, t_flags flags)
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

int		is_digit_plus(long long digit, t_flags flags, t_check_digit c_dig)
{
	if (flags.precision)
		return (digit_plus_prec(digit, flags, c_dig));
	else if (flags.width)
	{
		if (!flags.point && flags.zero && (flags.width > ft_strlen(c_dig.num)))
			return (digit_plus_width(digit, flags, c_dig));
		else
			return (digit_plus_width2(digit, flags, c_dig));
	}
	else
	{
		if (digit >= 0)
		{
			ft_putchar('+');
			if ((!flags.point && digit == 0) || digit != 0)
				c_dig.yn++;
		}
		if ((!flags.point && digit == 0) || digit != 0)
			ft_putstr(c_dig.num);
		return (ft_strlen(c_dig.num) + c_dig.yn + flags.space);
	}
}

int			is_digit_minus(long long digit, t_flags flags, t_check_digit c_dig)
{
	if ((flags.width > flags.precision && flags.precision >=
				ft_strlen(c_dig.num)) || flags.precision > ft_strlen(c_dig.num))
	{
		digit_lower_0(digit, &c_dig, flags);
		ft_putncaract('0', (flags.precision - ft_strlen(c_dig.num)));
		ft_putstr(c_dig.num);
		if (flags.width > flags.precision)
			ft_putncaract(' ', (flags.width - flags.precision - c_dig.yn));
		if (flags.width > flags.precision)
			return (flags.space + flags.width);
		return (flags.space + flags.precision + c_dig.yn);
	}
	if (flags.precision < ft_strlen(c_dig.num))
	{
		digit_upper_0(digit, &c_dig, 2);
		if (flags.width > flags.precision)
		{
			ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num) + c_dig.yn));
			if ((flags.width < ft_strlen(c_dig.num)))
				return (ft_strlen(c_dig.num) + flags.space);
			return (flags.space + flags.width);
		}
		return (ft_strlen(c_dig.num) + flags.space);
	}
	return (0);
}

int			prec_digit_no_op(long long digit, t_flags flags,
		t_check_digit c_dig)
{
	if ((flags.width > flags.precision && flags.precision >
			ft_strlen(c_dig.num)) || flags.precision >= ft_strlen(c_dig.num))
	{
		if (flags.width > flags.precision)
			ft_putncaract(' ', (flags.width - flags.precision));
		if (flags.width > flags.precision)
			c_dig.yn++;
		digit_lower_0(digit, &c_dig, flags);
		ft_putncaract('0', (flags.precision - ft_strlen(c_dig.num)));
		ft_putstr(c_dig.num);
		if (flags.width > flags.precision)
			return (flags.width + flags.space - ft_strlen(c_dig.num) + c_dig.yn);
		return (flags.precision + flags.space + c_dig.yn);
	}
	if (flags.precision < ft_strlen(c_dig.num))
	{
		if (flags.precision < 1)
			ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num)));
		if (flags.precision < 1)
			c_dig.yn++;
		ft_putstr(c_dig.num);
		if (c_dig.yn)
			return (flags.width + flags.space);
		return (ft_strlen(c_dig.num));
	}
	return (0);
}

int			width_digit_no_op(long long digit, t_flags flags,
		t_check_digit c_dig)
{
	if (!flags.point && flags.zero && (flags.width > ft_strlen(c_dig.num)))
	{
		digit_lower_0(digit, &c_dig, flags);
		ft_putncaract('0', (flags.width - ft_strlen(c_dig.num) - c_dig.yn));
		return (put_ret(c_dig.num, flags.width + flags.space));
	}
	else if ((!flags.point && (flags.width > ft_strlen(c_dig.num)))
			|| ((flags.point && (flags.width >= ft_strlen(c_dig.num)))))
	{
		ft_putncaract(' ', (flags.width - ft_strlen(c_dig.num)));
		if (digit != 0)
		{
			if (c_dig.space == 1 && flags.width == 1
					&& ft_strlen(c_dig.num) < 2)
				ft_putchar(' ');
			return (put_ret(c_dig.num, flags.width +
					flags.space + c_dig.space));
		}
		else
			return (put_ret(" ", flags.width + flags.space));
	}
	else
		return (put_ret(c_dig.num, ft_strlen(c_dig.num) + flags.space));
}

int		check_p_w_digit(long long digit, t_flags flags)
{
	t_check_digit		c_dig;

	c_dig = init_digit(c_dig, digit);
	if (flags.flag == 'u')
		flags.plus = 0;
	if (digit < 0 && flags.flag != 'u')
		c_dig.negdig = -digit;
	if (!(c_dig.num = make_str(digit, flags, c_dig.num)))
		return (0);
	is_space(digit, &flags, &c_dig);
	if (flags.plus)
		return (is_digit_plus(digit, flags, c_dig));
	else if (flags.minus)
		return (is_digit_minus(digit, flags, c_dig));
	else
	{
		if (flags.precision)
			return (prec_digit_no_op(digit, flags, c_dig));
		else if (flags.width)
			return (width_digit_no_op(digit, flags, c_dig));
		else if ((digit == 0 && !flags.point) || digit != 0)
			return (put_ret(c_dig.num, ft_strlen(c_dig.num) + flags.space));
	}
	return (0 + flags.space);
}
