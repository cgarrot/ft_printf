/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:54:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 15:10:25 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_isflags(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '\0')
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
			|| str[i] == '%' || str[i] == '0' || str[i] == '+' || str[i] == '-'
			|| str[i] == '#' || str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
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
	flags._l = 0;
	flags._h = 0;
	flags._L = 0;
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
	printf("l = [%d]\n", flags._l);
	printf("h = [%d]\n", flags._h);
	printf("L = [%d]\n", flags._L);
	printf("space = [%d]\n", flags.space);
	printf("width = [%d]\n", flags.width);
	printf("precision = [%d]\n\n", flags.precision);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	rev;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		rev = str[i];
		str[i] = str[j];
		str[j] = rev;
		j--;
		i++;
	}
	return (str);
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
					return (size + flags.precision);
				}
				else
				{
					if (flags.precision < flags.width)
					{
						ft_putncaract(' ', (flags.width - flags.precision));
						ft_putnstr(str, flags.precision);
						return ((flags.width - flags.precision) + flags.precision);
					}
					else
					{
						ft_putncaract(' ', size);
						ft_putnstr(str, flags.precision);
						return (size + flags.precision);
					}
				}
			}
			else
				ft_putnstr(str, flags.precision);
			return (flags.precision);
		}
		else
		{
			if (flags.minus)
			{
				ft_putstr(str);
				ft_putncaract(' ', size);
				return (size + ft_strlen(str));
			}
			else
			{
				ft_putncaract(' ', size);
				ft_putstr(str);
				return (size + ft_strlen(str));
			}
		}
	}
	else if (flags.point && !flags.precision)
	{
		if (flags.zero)
			ft_putncaract('0', flags.width);
		else
			ft_putncaract(' ', flags.width);
		return (flags.width);
	}
	else if (flags.width)
	{
		if (flags.minus)
		{
			ft_putstr(str);
			ft_putncaract(' ', size);
			return (size + ft_strlen(str));
		}
		else if (flags.zero)
		{
			ft_putncaract('0', size);
			ft_putstr(str);
			return (size + ft_strlen(str));
		}
		else
		{
			ft_putncaract(' ', size);
			ft_putstr(str);
			return (size + ft_strlen(str));
		}
	}
	else if (flags.plus && flags.minus && (size + 1))
	{
		ft_putstr(str);
		ft_putncaract(' ', size + 1);
		return (size + ft_strlen(str));
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int		check_p_w_digit(int digit, t_flags flags)
{
	char	*number;
	int		yesno;
	int		negdigit;
	yesno = 0;
	negdigit = digit;
	if (digit < 0)
		negdigit = -digit;
	number = ft_itoa(digit);
	//test flag espaces marche pas avec 1 de with et strlen de 1
	/*ft_printf("|% 1.1d| |% 2.0d| |% 3.1d| |% 1d| |%   2.1d| |% 1.0d| |% 0.2d|\n", 15, 41, 3, 9, 7, 1, 0);
	  printf("|% 1.1d| |% 2.0d| |% 3.1d| |% 1d| |%   2.1d| |% 1.0d| |% 0.2d|\n", 15, 41, 3, 9, 7, 1, 0);*/
	if (((flags.space && (digit >= 0) && !flags.plus)) && ((1 < ft_strlen(number)) || flags.precision > ft_strlen(number)))
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
			else if (flags.precision < ft_strlen(number))
			{
				if (flags.width > ft_strlen(number))
					ft_putncaract(' ', (flags.width - ft_strlen(number) - 1));
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + 1);
			}
			else
			{
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return(ft_strlen(number) + 1);
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
				if (digit > 0)
					yesno++;
				ft_putncaract(' ', (flags.width - ft_strlen(number) - yesno));
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + 1 + (flags.width - ft_strlen(number) - yesno));
			}
			else if (flags.width < ft_strlen(number))
			{
				if (digit > 0)
					ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + 1);
			}
			else
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				ft_putchar('+');
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number) - 1));
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
		if ((flags.width > flags.precision && flags.precision >= ft_strlen(number)) || flags.precision > ft_strlen(number))
		{
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
			{
				ft_putncaract(' ', (flags.width - flags.precision - yesno));
				return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number) + (flags.width - flags.precision - yesno)));
			}
			return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number)));
		}
		if (flags.precision < ft_strlen(number))
		{
			if (digit == 0)
				yesno++;
			else
				ft_putstr(number);
			if (flags.width > flags.precision)
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number) + yesno));
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number)));
			}
			return (ft_strlen(number) + flags.space);
		}
	}
	else
	{
		if (flags.precision)
		{
			if ((flags.width > flags.precision && flags.precision > ft_strlen(number)) || flags.precision >= ft_strlen(number))
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
				if (flags.precision < 1)
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
			else if ((!flags.point && (flags.width > ft_strlen(number))) || ((flags.point && (flags.width >= ft_strlen(number)))))
			{
				ft_putncaract(' ', (flags.width - ft_strlen(number)));
				if (digit != 0)
				{
					ft_putstr(number);
					return (flags.width + flags.space);
				}
				else
					ft_putchar(' ');
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
			if (digit != 0)
			{
				ft_putstr(number);
				return (flags.space);
			}
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

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char	*dectohexa(unsigned int n)
{
	char	*seg;
	int		i;
	int		tmp;

	seg = ft_strnew(0);
	i = 0;
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
		{
			seg[i] = tmp + 48;
			i++;
		}
		else
		{
			seg[i] = tmp + 87;
			i++;
		}
		n = n / 16;
	}
	return (ft_strrev(seg));
}

int		check_p_w_hexa(unsigned int dec, t_flags flags)
{
	int		size;
	char	*str;
	int		surplus;

	surplus = 0;
	if (flags.hashtag)
	{
		if (dec != 0)
		{
			ft_putstr("0x");
			surplus = 2;
		}
	}
	str = dectohexa(dec);
	if (flags.flag == 'X')
		str = ft_strcapitalize(str);
	size = flags.width - ft_strlen(str);
	if (size < 0)
		size = 0;
	if (flags.width && !flags.precision)
	{
		if (flags.hashtag && flags.point && dec == 0)
		{
			ft_putncaract(' ', flags.width - surplus);
			return (flags.width + surplus);
		}
		if (flags.width > ft_strlen(str))
		{
			if (flags.minus)
			{
				ft_putstr(str);
				ft_putncaract(' ', (flags.width - ft_strlen(str) - surplus));
			}
			else
			{
				if (flags.zero && !flags.point)
				{
					ft_putncaract('0', (flags.width - ft_strlen(str) - surplus));
					ft_putstr(str);
					return (flags.width + surplus);
				}
				ft_putncaract(' ', size - surplus);
				ft_putstr(str);
			}
			return (size + ft_strlen(str) + surplus);
		}
		else
		{
			ft_putstr(str);
			return (ft_strlen(str) + surplus);
		}
	}
	else if (flags.width && flags.precision)
	{
		if (flags.width > flags.precision)
		{
			if (!flags.minus)
			{
				ft_putncaract(' ', (flags.width - flags.precision - surplus));
				ft_putncaract('0', (flags.width - ft_strlen(str) - (flags.width - flags.precision) - surplus));
				ft_putstr(str);
				return (flags.width + surplus);
			}
			else
			{
				ft_putncaract('0', (flags.width - ft_strlen(str) - (flags.width - flags.precision) - surplus));
				ft_putstr(str);
				ft_putncaract(' ', (flags.width - flags.precision - surplus));
				return (flags.precision + surplus);
			}
		}
		else if (flags.width < flags.precision)
		{
			ft_putncaract('0', (flags.precision - ft_strlen(str) - surplus));
			ft_putstr(str);
			return (flags.precision + surplus);
		}
	}
	else if (!flags.width && flags.precision)
	{
		if (flags.precision > ft_strlen(str))
		{
			ft_putncaract('0', flags.precision - ft_strlen(str) - surplus);
			ft_putstr(str);
			return (flags.precision + surplus);
		}
		else
		{
			ft_putstr(str);
			return (ft_strlen(str) + surplus);
		}
	}
	else
	{
		ft_putstr(str);
		return (ft_strlen(str) + surplus);
	}
	return (0);
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
	if (flags.flag == 'x' || flags.flag == 'X')
	{
		args._x = va_arg(va, unsigned int);
		nb += check_p_w_hexa(args._x, flags);
	}
	/*if (flags.flag == 'u')
	  {
	  args._c = va_arg(va, unsigned int);
	  nb += check_p_w_unsidigit(args._u, flags);
	  }*/
	return (nb);
}

/*int		check_p_w_unsidigit(unsigned int udigi, t_flags flags)
  {
  return (0);
  }*/

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
				if (str[compt.j] == '#' && flags.hashtag < 1)
					flags.hashtag++;
				//if (str[compt.j] == '+' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '-' || str[compt.j - 1] == '0'))
				if (str[compt.j] == '+' && flags.plus < 1)
					flags.plus++;
				if (str[compt.j] == '-' && flags.minus < 1)
					flags.minus++;
				//if (str[compt.j] == '0' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '+'))
				if (str[compt.j] == '0' && flags.zero < 1)
					flags.zero++;
				if (str[compt.j] == '.' && ((ft_isdigit(str[compt.j - 1]) || ft_isdigit(str[compt.j + 1])) || (str[compt.j - 1] == '%' && str[compt.j + 1] == 's')))
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
			if (str[compt.j - 2] == 'l' || str[compt.j - 2] == 'h')
				return (0);
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

int		ft_printf(const char *format, ...)
{
	va_list		va;

	va_start(va, format);
	return (parse((char*)format, va));
}

int		main(void)
{
	return (0);
}
