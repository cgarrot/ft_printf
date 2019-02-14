/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:54:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 14:21:34 by cgarrot     ###    #+. /#+    ###.fr     */
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
			|| str[i] == '\f' || str[i] == '\r' || ft_isalpha(str[i]) || str[i] == '%' || str[i] == '0')
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
	printf("atoi flags.width = [%s]\n", compt.num);
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

int		check_p_w_str(char *str, t_flags flags)
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
					return (flags.nb_caract = flags.nb_caract + size + flags.precision);
				}
				else
				{
					if (flags.precision < flags.width)
					{
						ft_putncaract(' ', (flags.width - flags.precision));
						ft_putnstr(str, flags.precision);
						return (flags.nb_caract = flags.nb_caract + (flags.width - flags.precision) + flags.precision);
					}
					else
					{
						ft_putncaract(' ', size);
						ft_putnstr(str, flags.precision);
						return (flags.nb_caract = flags.nb_caract + size + flags.precision);
					}
				}
			}
			else
				ft_putnstr(str, flags.precision);
				return (flags.nb_caract = flags.nb_caract + flags.precision);
		}
		else
		{
			if (flags.minus)
			{
				ft_putstr(str);
				ft_putncaract(' ', size);
				return (flags.nb_caract += size + ft_strlen(str));
			}
			else
			{
				ft_putncaract(' ', size);
				ft_putstr(str);
				return (flags.nb_caract = flags.nb_caract + size + ft_strlen(str));
			}
		}
	}
	else if (flags.point && !flags.precision)
	{
		ft_putncaract(' ', flags.width);
		return (flags.nb_caract = flags.nb_caract + flags.width);
	}
	else if (flags.width)
	{
		if (flags.minus)
		{
			ft_putstr(str);
			ft_putncaract(' ', size);
			return (flags.nb_caract = flags.nb_caract + size + ft_strlen(str));
		}
		else
		{
			ft_putncaract(' ', size);
			ft_putstr(str);
			return (flags.nb_caract = flags.nb_caract + size + ft_strlen(str));
		}
	}
	return (0);
}

int		check_p_w_digit(int digit, t_flags flags)
{
	int		plus;
	char	*number;
	number = ft_itoa(digit);
	if (flags.plus)
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
			{
				if (flags.width > flags.precision)
					ft_putncaract(' ', (flags.width - flags.precision - 1));
				ft_putchar('+');
				ft_putncaract('0', (flags.precision - ft_strlen(number)));
				ft_putstr(number);
			}
			if (flags.precision < ft_strlen(number))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number) - 1));
				ft_putchar('+');
				ft_putstr(number);
			}
		}
		else if (flags.width)
		{
			if (!flags.point && flags.zero && (flags.width > ft_strlen(number)))
			{
				ft_putchar('+');
				ft_putncaract('0', (flags.width - ft_strlen(number) - 1));
				ft_putstr(number);
			}
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width > ft_strlen(number))) && flags.zero))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number) - 1));
				ft_putchar('+');
				ft_putstr(number);
			}
		}
		else
		{
			ft_putchar('+');
			ft_putstr(number);
		}
	}
	else if (flags.minus)
	{
		if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
		{
			ft_putncaract('0', (flags.precision - ft_strlen(number)));
			ft_putstr(number);
			if (flags.width > flags.precision)
				ft_putncaract(' ', (flags.width - flags.precision));
		}
		if (flags.precision < ft_strlen(number))
		{
			ft_putstr(number);
			if (flags.width > flags.precision)
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
		}
	}
	else
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
			{
				if (flags.width > flags.precision)
					ft_putncaract(' ', (flags.width - flags.precision));
				ft_putncaract('0', (flags.precision - ft_strlen(number)));
				ft_putstr(number);
			}
			if (flags.precision < ft_strlen(number))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				ft_putstr(number);
			}
		}
		else if (flags.width)
		{
			if (!flags.point && flags.zero && (flags.width > ft_strlen(number)))
			{
				ft_putncaract('0', (flags.width - ft_strlen(number)));
				ft_putstr(number);
			}
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width > ft_strlen(number))) && flags.zero))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
			}
			else
				ft_putstr(number);
		}
		else
			ft_putstr(number);
	}
	return (0);
}

int		chose_flag(t_flags flags, va_list va)
{
	t_args		args;

	if (flags.flag == 's')
	{
		args._s = va_arg(va, char*);
		flags.nb_caract = check_p_w_str(args._s, flags);
	}
	if (flags.flag == 'd')
	{
		args._d = va_arg(va, int);
		flags.nb_caract = check_p_w_digit(args._d, flags);
	}
	return (flags.nb_caract);
}

int		parse(char *str, va_list va)
{
	t_flags		flags;
	t_compt		compt;

	compt.i = -1;
	flags.nb_caract = 0;
	while (str[++compt.i])
	{
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			flags.nb_caract++;
		}
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
				if (str[compt.j] == '+' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '-' || str[compt.j - 1] == '0'))
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
			flags.nb_caract =chose_flag(flags, va);
			//print_help(flags, compt, str);
		}
	}
	va_end(va);
	return (flags.nb_caract);
}

int		my_printf(const char *format, ...)
{
	va_list		va;

	va_start(va, format);
	return (parse((char*)format, va));
}

int		main(void)
{
	my_printf("%d\n", my_printf("1string 1 %s string 2 %s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("1string 1 %s string 2 %s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("2string 1 %   s string 2 % s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("3string 1 %   s string 2 % s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("4string 1 %12s string 2 %12s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("4string 1 %12s string 2 %12s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("4string 1 %-12s string 2 %-12s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("4string 1 %-12s string 2 %-12s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("5string 1 %0s string 2 %0s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("5string 1 %0s string 2 %0s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("6string 1 %012s string 2 %012s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("6string 1 %012s string 2 %012s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("7string 1 %-012s string 2 %012s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("7string 1 %-012s string 2 %012s\n\n", "toto", "bonjour"));


	my_printf("%d\n", my_printf("12string 1 %-+5s string 2 %-+5s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("12string 1 %-+5s string 2 %-+5s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("13string 1 %-+05s string 2 %-+05s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("13string 1 %-+05s string 2 %-+05s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("14string 1 %+-5s string 2 %+-5s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("14string 1 %+-5s string 2 %+-5s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("15string 1 %.s string 2 %.s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("15string 1 %.s string 2 %.s\n\n", "toto", "bonjour"));

	my_printf("%d\n", my_printf("16string 1 %.6s string 2 %.6s\n", "toto", "bonjour"));
	printf("%d\n\n", printf("16string 1 %.6s string 2 %.6s\n\n", "toto", "bonjour"));

	/*
	   my_printf("%d\n", my_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	   printf("%d\n\n", printf("1chiffre 1 %d chiffre 2 %d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
	   printf("%d\n\n", printf("2chiffre 1 %   d chiffre 2 % d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));
	   printf("%d\n\n", printf("3chiffre 1 %12d chiffre 2 %12d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
	   printf("%d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
	   printf("%d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	   printf("%d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));
	   printf("%d\n\n", printf("7chiffre 1 %-012d chiffre 2 %012d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
	   printf("%d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));

	   my_printf("%d\n", my_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));
	   printf("%d\n\n", printf("9chiffre 1 %+d chiffre 2 %+d\n\n", 42, 6, -42, 6));

	   my_printf("%d\n", my_printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));
	   printf("%d\n\n", printf("10chiffre 1 %+12d chiffre 2 %+12d\n\n", 42, 6, -42, 6));

	   my_printf("%d\n", my_printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));
	   printf("%d\n\n", printf("11chiffre 1 %*12d chiffre 2 %*12d\n\n", 42, -6, 42, 6));

	   my_printf("%d\n", my_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42));
	   printf("%d\n\n", printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n\n", 42, -42));  

	   my_printf("%d\n", my_printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42));
	   printf("%d\n\n", printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));
	   printf("%d\n\n", printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
	   printf("%d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));

	   my_printf("%d\n", my_printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));
	   printf("%d\n\n", printf("16chiffre 1 %.6d chiffre 2 %.6d\n\n", 42, -42));
	   */
	return (0);
}
