/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:54:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 14:41:01 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_isflags(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'x' || c == 'X' || c == 'h' || c == 'l' || c == 'f' || c == 'L')
		return (1);
	return (0);
}

int		ft_atoi_2(char const *str)
{
	int		i;
	int		neg;
	int		nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || ft_isalpha(str[i]) || str[i] == '%')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && str[i - 1] != '+')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr * neg);
}

t_flags init(t_flags flags)
{
	flags.hashtag = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.point = 0;
	flags.width = 0;
	flags.precision = 0;
	return (flags);
}

void	print_help(t_flags flags, t_compt compt, char *str)
{
	printf("\nlast_caract[%c]\n", str[compt.j]);
	printf("flag = [%c]\n", flags.flag);
	printf("param = [%s]\n", compt.num);
	printf("atoi flags.precision = [%s]\n", compt.num2);
	printf("# = [%d]\n", flags.hashtag);
	printf("+ = [%d]\n", flags.plus);
	printf("- = [%d]\n", flags.minus);
	printf("0 = [%d]\n", flags.zero);
	printf(". = [%d]\n", flags.point);
	printf("width = [%d]\n", flags.width);
	printf("precision = [%d]\n\n", flags.precision);
}

void	ft_putnstr(char const *s, int size)
{
	if (s != 0)
		write(1, s, size);
}

void	ft_putncaract(char c, int size)
{
	int		i;

	i = -1;
	while (++i != size)
		ft_putchar(c);
}

void	check_p_w_str(char *str, t_flags flags)
{
	int		size;

	size = flags.width - ft_strlen(str);
	if (size < 0)
		size = 0;
	if (flags.precision)
	{
		if (flags.precision < ft_strlen(str))
		{
			if (flags.width)
			{
				if (flags.minus)
				{
					ft_putnstr(str, flags.precision);
					ft_putncaract(' ', size);
				}
				else
				{
					if (flags.precision < flags.width)
					{
						ft_putncaract(' ', (flags.width - flags.precision));
						ft_putnstr(str, flags.precision);
					}
					else
					{
						ft_putncaract(' ', size);
						ft_putnstr(str, flags.precision);
					}
				}
			}
			else
				ft_putnstr(str, flags.precision);
		}
		else
		{
			if (flags.minus)
			{
				ft_putstr(str);
				ft_putncaract(' ', size);
			}
			else
			{
				ft_putncaract(' ', size);
				ft_putstr(str);
			}
		}
	}
	else if (flags.point && !flags.precision)
		ft_putncaract(' ', flags.width);
	else if (flags.width)
	{
		if (flags.minus)
		{
			ft_putstr(str);
			ft_putncaract(' ', size);
		}
		else
		{
			ft_putncaract(' ', size);
			ft_putstr(str);
		}
	}
}

void	check_p_w_digit(int digit, t_flags flags)
{
	if (flags.plus)
	{
		
	}
}

int		chose_flag(t_flags flags, va_list va)
{
	t_args		args;

	if (flags.flag == 's')
	{
		args._s = va_arg(va, char*);
		check_p_w_str(args._s, flags);
	}
	if (flags.flag == 'd')
	{
		args._d = va_arg(va, int);
		check_p_w_digit(args._d, flags);
	}
	return (0);
}

int		parse(char *str, va_list va)
{
	t_flags		flags;
	t_compt		compt;

	compt.i = -1;
	while (str[++compt.i])
	{
		if (str[compt.i] != '%')
			ft_putchar(str[compt.i]);
		//not print %%
		if (str[compt.i] == '%' && (str[compt.i + 1] != '%' && str[compt.i + 1] != '\0' && str[compt.i - 1] != '%'))
		{
			compt.j = compt.i;
			compt.k = 0;
			flags = init(flags);
			compt.num2 = ft_strnew(0);
			while (!(ft_isflags(str[compt.j++])))
			{
				if (str[compt.j] == '#')
					flags.hashtag++;
				if (str[compt.j] == '+' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '-'))
					flags.plus++;
				if (str[compt.j] == '-' && (str[compt.j - 1] == '%' && str[compt.j + 1] != '+'))
					flags.minus++;
				if (str[compt.j] == '0' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '+'))
					flags.zero++;
				if (str[compt.j] == '.' && (ft_isdigit(str[compt.j - 1]) || ft_isdigit(str[compt.j + 1])))
				{
					flags.point++;
					compt.k = compt.j;
				}
				//printf("%c", str[compt.j]);
			}
			//remplace flag hh et ll par autre lettre
			if (str[compt.j - 1] == 'h' && str[compt.j] == 'h')
				flags.flag = 'm';
			else if (str[compt.j - 1] == 'l' && str[compt.j] == 'l')
				flags.flag = 'n';
			else
				flags.flag = str[compt.j - 1];
			if (!(compt.num = ft_strsub(str, compt.i, (compt.j - compt.i))))
				return (0);
			if (flags.point)
				if (!(compt.num2 = ft_strsub(str, compt.k + 1, (compt.j - compt.k - 1))))
					return (0);
			flags.precision = ft_atoi_2(compt.num2);
			flags.width = ft_atoi_2(compt.num);
			compt.i = compt.j - 1;
			chose_flag(flags, va);
			//print_help(flags, compt, str);
		}
	}
	va_end(va);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		va;

	va_start(va, format);
	return (parse((char*)format, va));
}

int		main(void)
{
	ft_printf("salut%5s %1s %10.5s %.s\n", "zob", "Zoberie", "salut", "yolo");
	printf("salut%5s %1s %10.5s %.s\n", "zob", "Zoberie", "salut", "yolo");
	printf("|%+0d|\n", 52);
	return (0);
}
