/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:45:53 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 18:25:15 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

//virer le print help

void		print_help(t_flags flags, t_compt compt, char *str)
{
	printf("\nlast_caract[%c]\n", str[compt.j]);
	printf("flag = [%c]\n", flags.flag);
	printf("param = [%s]\n", compt.num);
	printf("atoi flags.precision = [%s]\n", compt.num2);
	printf("atoi flags.width = [%s]\n", compt.num);
	printf("# = [%d]\n", flags.hashtag);
	printf("+ = [%d]\n", flags.plus);
	printf("- = [%d]\n", flags.minus);
	printf("0 = [%d]\n", flags.zero);
	printf(". = [%d]\n", flags.point);
	printf("l = [%d]\n", flags._l);
	printf("h = [%d]\n", flags._h);
	printf("L = [%d]\n", flags._L);
	printf("space = [%d]\n", flags.space);
	printf("width = [%d]\n", flags.width);
	printf("precision = [%d]\n\n", flags.precision);
}

int			give_info(t_compt *compt, t_flags flags, va_list va, char *str)
{
	compt->j = compt->i;
	flags.tmp = 0;
	flags = init(flags);
	compt->num2 = ft_strnew(0);
	while (!(ft_isflags(str[compt->j++])))
		flags = compt_flags(flags, *compt, str);
	flags.flag = str[compt->j - 1];
	if (!(compt->num = ft_strsub(str, compt->i, (compt->j - compt->i))))
		return (0);
	if (flags.point)
		if (!(compt->num2 = ft_strsub(str, flags.tmp + 1,
				(compt->j - flags.tmp - 1))))
			return (0);
	flags.precision = ft_atoi_2(compt->num2);
	flags.width = ft_atoi_2(compt->num);
	compt->i = compt->j - 1;
	compt->nb = chose_flag(flags, va, compt->nb);
	//print_help(flags, compt, str);
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
	if (str[cpt.j] == '.' && ((ft_isdigit(str[cpt.j - 1]) ||
		ft_isdigit(str[cpt.j + 1])) || str[cpt.j - 1] == ' ' || str[cpt.j - 1]
		== '+' || (str[cpt.j - 1] == '%' && ft_isflags(str[cpt.j + 1]))))
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
