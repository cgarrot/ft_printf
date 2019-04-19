/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:33:57 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 12:51:09 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		chose_for_digit(t_flags flags, va_list va, int nb, t_args args)
{
	if (flags._l && flags.flag == 'u')
	{
		args._lu = va_arg(va, unsigned long long);
		nb += check_p_w_digit(args._lu, flags);
	}
	else if (flags.flag == 'u')
	{
		args._u = va_arg(va, unsigned int);
		nb += check_p_w_digit(args._u, flags);
	}
	else if (flags._l && (flags.flag == 'd' || flags.flag == 'i'))
	{
		args._ld = va_arg(va, long long);
		nb += check_p_w_digit(args._ld, flags);
	}
	else
	{
		args._d = va_arg(va, int);
		nb += check_p_w_digit(args._d, flags);
	}
	return (nb);
}

int		chose_other_digit(t_flags flags, va_list va, int nb, t_args args)
{
	if (flags.flag == 'x' || flags.flag == 'X')
	{
		args._x = va_arg(va, unsigned long long);
		nb += check_p_w_hexa(args._x, flags);
	}
	if (flags.flag == 'p')
	{
		args._p = va_arg(va, void*);
		nb += check_p_w_ptr(args._p, flags);
	}
	if (flags.flag == 'o')
	{
		args._o = va_arg(va, unsigned long);
		nb += check_p_w_octa(args._o, flags);
	}
	return (nb);
}

int		chose_flag(t_flags flags, va_list va, int nb)
{
	t_args		args;

	if (flags.flag == 's')
	{
		args._s = va_arg(va, char*);
		nb += check_p_w_str(args._s, flags);
	}
	if (flags.flag == 'd' || flags.flag == 'u' || flags.flag == 'i')
		nb = chose_for_digit(flags, va, nb, args);
	if (flags.flag == 'c')
	{
		args._c = va_arg(va, int);
		nb += check_p_w_caract(args._c, flags);
	}
	if (flags.flag == 'x' || flags.flag == 'X'
			|| flags.flag == 'o' || flags.flag == 'p')
		nb = chose_other_digit(flags, va, nb, args);
	return (nb);
}
