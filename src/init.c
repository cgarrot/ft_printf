/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:04:59 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 18:29:07 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			init(t_flags flags)
{
	flags.hashtag = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.point = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.space = 0;
	flags._l = 0;
	flags._h = 0;
	flags._L = 0;
	return (flags);
}

t_check_str		init_str(t_flags flags, int size, char *str)
{
	t_check_str		c_str;

	c_str.precision = flags.precision;
	c_str.width = flags.width;
	c_str.minus = flags.minus;
	c_str.zero = flags.zero;
	c_str.size = size;
	c_str.str = str;
	return (c_str);
}
