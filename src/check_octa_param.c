/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_octa_param.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 12:55:43 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 13:03:06 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_octa_hash(unsigned long dec, t_flags flags, t_check_octa c_octa)
{
	if (dec != 0 && !(flags.width > ft_strlen(c_octa.str)))
		put_init("0", &c_octa);
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

int		is_octa_width_no_op(unsigned long dec, t_flags flags,
		t_check_octa c_octa)
{
	if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
		put_init("0", &c_octa);
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

void	octa_print_space_0(unsigned long dec, t_flags flags,
		t_check_octa *c_octa, int chose)
{
	if (chose == 1)
	{
		if (dec == 0 && !flags.hashtag)
			ft_putncaract(' ', flags.width);
		else if (dec == 0 && flags.hashtag)
			ft_putncaract(' ', flags.width - 1);
		else if (flags.hashtag && c_octa->surplus != 1)
			ft_putncaract(' ', c_octa->size - 1);
		else
			ft_putncaract(' ', c_octa->size);
	}
	if (chose == 2)
	{
		if (ft_strlen(c_octa->str) < 12)
			ft_putncaract('0', flags.precision - ft_strlen(c_octa->str) -
					c_octa->surplus);
		if (ft_strlen(c_octa->str) > 11 && !flags._l && !flags._h)
			ft_putncaract('0', flags.precision - 11);
		if (ft_strlen(c_octa->str) > 11 && flags._l && !flags._h)
			ft_putncaract('0', flags.precision - ft_strlen(c_octa->str));
		if (ft_strlen(c_octa->str) > 11 && !flags._l && flags._h == 1)
			ft_putncaract('0', flags.precision - 6);
		if (ft_strlen(c_octa->str) > 11 && !flags._l && flags._h == 2)
			ft_putncaract('0', flags.precision - 3);
	}
}

int		is_octa_width_lower_no_op(unsigned long dec, t_flags flags,
		t_check_octa *c_octa)
{
	if (flags.zero && !flags.point)
	{
		if (flags.hashtag && dec != 0 && c_octa->surplus != 1)
			put_init("0", c_octa);
		ft_putncaract('0', c_octa->size - c_octa->surplus);
		ft_putstro(c_octa->str, flags);
		return (flags.width);
	}
	else if (flags.width >= ft_strlen(c_octa->str) + 1)
		octa_print_space_0(dec, flags, c_octa, 1);
	else
		ft_putncaract(' ', c_octa->size);
	if (flags.hashtag && dec != 0 && c_octa->surplus != 1)
		put_init("0", c_octa);
	if (dec != 0 || (dec == 0 && !flags.point))
		ft_putstro(c_octa->str, flags);
	return (-1);
}

int		is_octa_width_lower(unsigned long dec, t_flags flags,
		t_check_octa c_octa)
{
	int		tmp;

	if (flags.hashtag && c_octa.surplus != 1 && dec != 0 && flags.minus)
		put_init("0", &c_octa);
	if ((dec != 0 || (dec == 0 && !flags.point)) && flags.minus)
		ft_putstro(c_octa.str, flags);
	if (dec == 0 && flags.point && flags.minus)
		ft_putncaract(' ', flags.width);
	else if (flags.minus)
		ft_putncaract(' ', c_octa.size - c_octa.surplus);
	else if ((tmp = is_octa_width_lower_no_op(dec, flags, &c_octa) != -1))
		return (flags.width);
	return (flags.width);
}
