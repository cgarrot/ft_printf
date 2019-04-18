/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_octa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:43:11 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 13:10:55 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_octa_width(unsigned long dec, t_flags flags, t_check_octa c_octa)
{
	int		tmp;

	if (flags.hashtag && flags.point)
		if ((tmp = is_octa_hash(dec, flags, c_octa) != -1))
			return (tmp);
	if (flags.width > ft_strlen(c_octa.str))
		return (is_octa_width_lower(dec, flags, c_octa));
	else if ((tmp = is_octa_width_no_op(dec, flags, c_octa)))
		return (tmp);
	return (0);
}

int		is_octa_width_up_prec(unsigned long dec, t_flags flags,
		t_check_octa *c_octa)
{
	if (flags.precision < ft_strlen(c_octa->str))
	{
		if (flags.hashtag && dec != 0 && c_octa->surplus != 1)
		{
			ft_putncaract(' ', c_octa->size - 1);
			put_init("0", c_octa);
		}
		else
			ft_putncaract(' ', c_octa->size);
		ft_putstro(c_octa->str, flags);
		if (flags.width > ft_strlen(c_octa->str))
			return (flags.width);
		return (flags.width + c_octa->surplus);
	}
	if (flags.hashtag && c_octa->surplus != 1 && dec != 0)
		put_init("0", c_octa);
	if (flags.minus)
	{
		ft_putncaract('0', (c_octa->size - (flags.width - flags.precision)));
		ft_putstro(c_octa->str, flags);
		ft_putncaract(' ', (flags.width - flags.precision));
		return (flags.width + c_octa->surplus);
	}
	return (-1);
}

int		is_octa_width_prec(unsigned long dec, t_flags flags,
		t_check_octa *c_octa)
{
	int		tmp;

	if (flags.width > flags.precision)
	{
		if ((tmp = is_octa_width_up_prec(dec, flags, c_octa)) != -1)
			return (tmp);
		else
		{
			ft_putncaract(' ', flags.width - flags.precision);
			ft_putncaract('0', c_octa->size - (flags.width - flags.precision));
			ft_putstro(c_octa->str, flags);
			return (flags.width + c_octa->surplus);
		}
	}
	else
	{
		if (flags.hashtag && dec != 0 && c_octa->surplus != 1)
			put_init("0", c_octa);
		ft_putncaract('0', flags.precision - ft_strlen(c_octa->str));
		ft_putstro(c_octa->str, flags);
		if (flags.precision > ft_strlen(c_octa->str))
			return (flags.precision + c_octa->surplus);
		return (ft_strlen(c_octa->str) + c_octa->surplus);
	}
}

int		is_octa_no_width_prec(unsigned long dec, t_flags flags,
		t_check_octa *c_octa)
{
	if (flags.hashtag && dec != 0 && c_octa->surplus != 1)
		put_init("0", c_octa);
	if (flags.precision > ft_strlen(c_octa->str))
	{
		octa_print_space_0(dec, flags, c_octa, 2);
		ft_putstro(c_octa->str, flags);
		return (flags.precision);
	}
	ft_putstro(c_octa->str, flags);
	return (ft_strlen(c_octa->str) + c_octa->surplus);
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
		return (is_octa_width_prec(dec, flags, &c_octa));
	else if (!flags.width && flags.precision)
		return (is_octa_no_width_prec(dec, flags, &c_octa));
	else
	{
		if (flags.hashtag && dec != 0 && c_octa.surplus != 1)
			put_init("0", &c_octa);
		if (dec != 0 || (dec == 0 && !flags.point && !flags.precision
				&& !flags.width))
			ft_putstro(c_octa.str, flags);
		if (dec != 0 || (dec == 0 && !flags.point))
			return ((ft_strlen(c_octa.str) + c_octa.surplus));
		return (c_octa.surplus);
	}
}
