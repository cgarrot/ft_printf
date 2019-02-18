/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:54:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 18:37:26 by cgarrot     ###    #+. /#+    ###.fr     */
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
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || ft_isalpha(str[i])
			|| str[i] == '%' || str[i] == '0' || str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr);
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
	flags.space = 0;
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
	printf("space = [%d]\n", flags.space);
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
	if (flags.point && (!flags.precision && !flags.width))
		return (0);
	if (flags.space)
		ft_putchar(' ');
	else if (flags.precision)
	{
		if (flags.precision < ft_strlen(str))
		{
			if (flags.width)
			{
				if (flags.minus)
				{
					ft_putnstr(str, flags.precision);
					ft_putncaract(' ', size);
					return (size + flags.precision + flags.space);
				}
				else
				{
					if (flags.precision < flags.width)
					{
						ft_putncaract(' ', (flags.width - flags.precision));
						ft_putnstr(str, flags.precision);
						return ((flags.width - flags.precision) + flags.precision + flags.space);
					}
					else
					{
						ft_putncaract(' ', size);
						ft_putnstr(str, flags.precision);
						return (size + flags.precision + flags.space);
					}
				}
			}
			else
				ft_putnstr(str, flags.precision);
			return (flags.precision + flags.space);
		}
		else
		{
			if (flags.minus)
			{
				ft_putstr(str);
				ft_putncaract(' ', size);
				return (size + ft_strlen(str) + flags.space);
			}
			else
			{
				ft_putncaract(' ', size);
				ft_putstr(str);
				return (size + ft_strlen(str) + flags.space);
			}
		}
	}

	else if (flags.point && !flags.precision)
	{
		ft_putncaract(' ', flags.width);
		return (flags.width);
	}
	else if (flags.width)
	{
		if (flags.minus)
		{
			ft_putstr(str);
			ft_putncaract(' ', size);
			return (size + ft_strlen(str) + flags.space);
		}

		else
		{
			ft_putncaract(' ', size);
			ft_putstr(str);
			return (size + ft_strlen(str) + flags.space);
		}
	}
	else if (flags.plus && flags.minus && (size + 1))
	{
		ft_putstr(str);
		ft_putncaract(' ', size + 1);
		return (size + ft_strlen(str) + flags.space);
	}
	else
	{
		ft_putstr(str);
		return (ft_strlen(str) + flags.space);
	}
	return (0);
}

int		check_p_w_digit(int digit, t_flags flags)
{
	int		plus;
	char	*number;
	int		yesno;
	int		negdigit;
	yesno = 0;
	negdigit = digit;
	if (digit < 0)
		negdigit = -digit;
	number = ft_itoa(digit);
	if (flags.space && (digit > 0))
		ft_putchar(' ');
	else
		flags.space = 0;
	if (flags.plus)
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
			{
				if (flags.width > flags.precision)
				{
					ft_putncaract(' ', (flags.width - flags.precision - 1));
					yesno++;
				}
				ft_putchar('+');
				ft_putncaract('0', (flags.precision - ft_strlen(number)));
				ft_putstr(number);
				if (yesno)
					return (ft_strlen(number) + flags.space + 1 + (flags.precision - ft_strlen(number)) + (flags.width - flags.precision - 1));
				return (ft_strlen(number) + 1 + (flags.precision - ft_strlen(number)));
			}
			if (flags.precision < ft_strlen(number))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number) - 1));
				ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + 1 + (flags.width - ft_strlen(number) - 1));
			}
		}
		else if (flags.width)
		{
			if (!flags.point && flags.zero && (flags.width > ft_strlen(number)))
			{
				if (digit > 0)
				{
					ft_putchar('+');
					yesno++;
				}
				if (!flags.minus && !flags.plus)
				{
					ft_putncaract('0', (flags.width - ft_strlen(number) - yesno));
					yesno++;
				}
				ft_putstr(number);
				//printf("[%zu]\n", ft_strlen(number));
				//printf("[%d]\n", yesno);
				//printf("[%zu]\n", flags.width - ft_strlen(number));
				if (flags.minus)
				{
					ft_putncaract(' ', (flags.width - ft_strlen(number) - yesno));
					return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
				}

				return (ft_strlen(number) + flags.space + ((flags.width - ft_strlen(number)) - yesno));
			}
			else if (flags.minus)
			{
				if (digit > 0)
				{
					ft_putchar('+');
					yesno++;
				}
				ft_putstr(number);
				ft_putncaract(' ', (flags.width - ft_strlen(number) - yesno));
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
			}
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width > ft_strlen(number))) && flags.zero))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number) - 1));
				ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + 1 + (flags.width - ft_strlen(number) - 1));
			}
		}
		else
		{
			ft_putchar('+');
			ft_putstr(number);
			return (ft_strlen(number) + 1 + flags.space);
		}
	}
	else if (flags.minus)
	{
		if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
		{
			ft_putncaract('0', (flags.precision - ft_strlen(number)));
			ft_putstr(number);
			if (flags.width > flags.precision)
			{
				ft_putncaract(' ', (flags.width - flags.precision));
				return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number) + (flags.width - flags.precision)));
			}
			return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number)));
		}
		if (flags.precision < ft_strlen(number))
		{
			ft_putstr(number);
			if (flags.width > flags.precision)
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
			}
			return (ft_strlen(number) + flags.space);
		}
	}
	else
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision > ft_strlen(number))
			{
				if (flags.width > flags.precision)
				{
					ft_putncaract(' ', (flags.width - flags.precision));
					yesno++;
				}
				if (digit < 0)
				{
					ft_putchar('-');
					ft_strdel(&number);
					number = ft_itoa(negdigit);
					yesno++;
				}
				ft_putncaract('0', (flags.precision - ft_strlen(number)));
				ft_putstr(number);
				if (flags.width > flags.precision)
					return ((flags.width - flags.precision) + flags.space + (flags.precision - ft_strlen(number)));
				return ((flags.precision - ft_strlen(number) + flags.space + ft_strlen(number)) + yesno);
			}
			if (flags.precision < ft_strlen(number))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				ft_putstr(number);
				return ((flags.width - ft_strlen(number) + flags.space + ft_strlen(number)));
			}
		}
		else if (flags.width)
		{
			if (!flags.point && flags.zero && (flags.width > ft_strlen(number)))
			{
				if (digit < 0)
				{
					ft_putchar('-');
					ft_strdel(&number);
					number = ft_itoa(negdigit);
					yesno++;
				}
				ft_putncaract('0', (flags.width - ft_strlen(number) - yesno));
				ft_putstr(number);
				return (flags.width - ft_strlen(number) + flags.space + ft_strlen(number));
			}
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width > ft_strlen(number))) && flags.zero))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				ft_putstr(number);
				return (flags.width - ft_strlen(number) + flags.space + ft_strlen(number));
			}
			else
			{
				ft_putstr(number);
				return (ft_strlen(number) + flags.space);
			}
		}
		else
		{
			ft_putstr(number);
			return (ft_strlen(number) + flags.space);
		}
	}
	return (0);
}

int		check_p_w_caract(int c, t_flags flags)
{
	if (flags.width)
	{
		if (flags.minus)
		{
			ft_putchar(c);
			ft_putncaract(' ', (flags.width - 1));
			return (flags.width);
		}
		else
		{
			if (flags.zero)
				ft_putncaract('0', (flags.width - 1));
			else
				ft_putncaract(' ', (flags.width - 1));
			ft_putchar(c);
			return (flags.width);
		}
	}
	else
		ft_putchar(c);
	return (1);
}

int		chose_flag(t_flags flags, va_list va, int nb)
{
	t_args		args;

	if (flags.flag == 's')
	{
		args._s = va_arg(va, char*);
		nb += check_p_w_str(args._s, flags);
	}
	if (flags.flag == 'd')
	{
		args._d = va_arg(va, int);
		nb += check_p_w_digit(args._d, flags);
	}
	if (flags.flag == 'c')
	{
		args._c = va_arg(va, int);
		nb += check_p_w_caract(args._c, flags);
	}
	return (nb);
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
		if (str[compt.i] != '%')
		{
			ft_putchar(str[compt.i]);
			nb++;
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
				if (str[compt.j] == '-')
					flags.minus++;
				if (str[compt.j] == '0' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '+'))
					flags.zero++;
				if (str[compt.j] == '.' && ((ft_isdigit(str[compt.j - 1]) || ft_isdigit(str[compt.j + 1])) || (str[compt.j - 1] == '%' && str[compt.j + 1] == 's')))
				{
					flags.point++;
					compt.k = compt.j;
				}
				if (str[compt.j] == ' ' && !flags.space)
					flags.space++;
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
			nb = chose_flag(flags, va, nb);
			//print_help(flags, compt, str);
		}
		//marche pas avec des espaces et crash avec un 1
		//mettre dans les flags sinon les espaces ne marche pas
		flags.forcent = 0;
		if (str[compt.i] == '%')
		{
			while (str[compt.i] == '%')
			{
				flags.forcent++;
				compt.i++;
			}
			if (flags.forcent % 2 == 0)
				ft_putncaract('%', (flags.forcent / 2));
			else
				ft_putncaract('%', ((flags.forcent + 1) / 2));
			compt.i--;
		}
	}
	va_end(va);
	return (nb);
}

int		my_printf(const char *format, ...)
{
	va_list		va;
	int		nb = 0;

	va_start(va, format);
	return (parse((char*)format, va));
}

int		main(void)
{
	return (0);
}
