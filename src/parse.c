/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:45:53 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/03 16:12:09 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			give_info(t_compt *compt, t_flags flags, va_list va, char *str)
{
	compt->j = compt->i;
	flags.tmp = 0;
	init(&flags);
	while (!(ft_isflags(str[compt->j++])))
		flags = compt_flags(flags, *compt, str);
	flags.flag = str[compt->j - 1];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i))))
		return (0);
	compt->num2 = NULL;
	if (flags.point)
		if (!(compt->num2 = ft_strsub(str, flags.tmp + 1,
						(compt->j - flags.tmp - 1))))
			return (0);
	if (compt->num2 == NULL)
		flags.precision = 0;
	else
		flags.precision = ft_atoi_2(compt->num2);
	flags.width = ft_atoi_2(compt->num);
	compt->i = compt->j - 1;
	compt->nb = chose_flag(flags, va, compt->nb);
	ft_strdel(&compt->num);
	ft_strdel(&compt->num2);
	return (1);
}

t_compt		print_car(t_compt compt, char *str)
{
	compt.m = 0;
	if (str[compt.i] == '%' && str[compt.i + 1] == '%')
	{
		while (str[compt.i] == '%')
		{
			compt.i++;
			compt.m++;
		}
		ft_putncaract('%', (compt.m / 2));
		compt.nb += compt.m / 2;
		if (!str[compt.i])
			compt.i--;
	}
	if (str[compt.i] != '%')
	{
		ft_putchar(str[compt.i]);
		compt.nb++;
	}
	return (compt);
}

int			if_is_true(char *str, t_flags flags, t_compt cpt)
{
	if (str[cpt.j] == '.' && ((ft_isdigit(str[cpt.j - 1]) ||
		ft_isdigit(str[cpt.j + 1])) || str[cpt.j - 1] == ' ' || str[cpt.j - 1]
		== '+' || str[cpt.j - 1] == '#' || (str[cpt.j - 1] == '%'
		&& ft_isflags(str[cpt.j + 1]))))
		return (1);
	else
		return (0);
}

t_flags		compt_flags(t_flags flags, t_compt cpt, char *str)
{
	if (str[cpt.j] == '#' && flags.hashtag < 1)
		flags.hashtag++;
	if (str[cpt.j] == '+' && flags.plus < 1)
		flags.plus++;
	if (str[cpt.j] == '-' && flags.minus < 1)
		flags.minus++;
	if (str[cpt.j] == '0' && flags.zero < 1 &&
			!ft_isflags(str[cpt.j + 1]) && !ft_isdigit(str[cpt.j - 1]))
		flags.zero++;
	if (if_is_true(str, flags, cpt))
	{
		flags.point++;
		flags.tmp = cpt.j;
	}
	if (str[cpt.j] == ' ' && flags.space < 1)
		flags.space++;
	if (str[cpt.j] == 'l' && flags._l < 2)
		flags._l++;
	if (str[cpt.j] == 'h' && flags._h < 2)
		flags._h++;
	if (str[cpt.j] == 'L' && flags._L < 1)
		flags._L++;
	return (flags);
}

int			parse(char *str, va_list va)
{
	t_flags		flags;
	t_compt		compt;

	compt.nb = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		compt = print_car(compt, str);
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' &&
					str[compt.i + 1] != '\0'))
			if (!(give_info(&compt, flags, va, str)))
				return (0);
	}
	va_end(va);
	return (compt.nb);
}
