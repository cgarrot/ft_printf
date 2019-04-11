/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:45:53 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 16:49:30 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_help(t_flags flags, t_compt compt, char *str)
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

int		parse(char *str, va_list va)
{
	t_flags		flags;
	t_compt		compt;
	int			nb;

	nb = 0;
	compt.i = -1;
	while (str[++compt.i])
	{
		compt.m = 0;
		if (str[compt.i] == '%' && str[compt.i + 1] == '%')
		{
			while (str[compt.i] == '%')
			{
				compt.i++;
				compt.m++;
			}
			ft_putncaract('%', (compt.m  / 2));
			nb += compt.m  / 2;
			if (!str[compt.i])
				compt.i--;
		}
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			nb++;
		}
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' && str[compt.i + 1] != '\0'))
		{
			compt.j = compt.i;
			compt.k = 0;
			flags = init(flags);
			compt.num2 = ft_strnew(0);
			while (!(ft_isflags(str[compt.j++])))
			{
				if (str[compt.j] == '#' && flags.hashtag < 1)
					flags.hashtag++;
				if (str[compt.j] == '+' && flags.plus < 1)
					flags.plus++;
				if (str[compt.j] == '-' && flags.minus < 1)
					flags.minus++;
				if (str[compt.j] == '0' && flags.zero < 1 &&
						!ft_isflags(str[compt.j + 1]) && !ft_isdigit(str[compt.j - 1]))
					flags.zero++;
				if (str[compt.j] == '.' && ((ft_isdigit(str[compt.j - 1])
						|| ft_isdigit(str[compt.j + 1])) || str[compt.j - 1]
						== ' ' || str[compt.j - 1] == '+' || (str[compt.j - 1]
						== '%' && ft_isflags(str[compt.j + 1]))))
				{
					flags.point++;
					compt.k = compt.j;
				}
				if (str[compt.j] == ' ' && flags.space < 1)
					flags.space++;
				if (str[compt.j] == 'l' && flags._l < 2)
					flags._l++;
				if (str[compt.j] == 'h' && flags._h < 2)
					flags._h++;
				if (str[compt.j] == 'L' && flags._L < 1)
					flags._L++;
				//printf("%c", str[compt.j]);
			}
			flags.flag = str[compt.j - 1];
			if (!(compt.num = ft_strsub(str, compt.i, (compt.j - compt.i))))
				return (0);
			if (flags.point)
				if (!(compt.num2 = ft_strsub(str, compt.k + 1, (compt.j - compt.k - 1))))
					return (0);
			flags.precision = ft_atoi_2(compt.num2);
			flags.width = ft_atoi_2(compt.num);
			compt.i = compt.j - 1;
			nb = chose_flag(flags, va, nb);
			//print_help(flags, compt, str);
		}
		//printf("{%d}\n", nb);
	}
	va_end(va);
	return (nb);
}
