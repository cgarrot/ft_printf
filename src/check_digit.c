/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_digit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:42:56 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 10:32:17 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	is_space(long long digit, t_flags *flags, t_check_digit *c_dig)
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
