/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:54:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 19:29:10 by cgarrot     ###    #+. /#+    ###.fr     */
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

	if (!str)
	{
		ft_strdel(&str);
		str = ft_strnew(7);
		str = ft_strcpy(str, "(null)");
	}
	size = flags.width - ft_strlen(str);
	if (size == 1)
		size++;
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
				if (flags.minus && !flags.width)
				{
					ft_putnstr(str, flags.precision);
					ft_putncaract(' ', size);
					return (size + flags.precision);
				}
				else if (flags.minus && flags.width)
				{
					ft_putnstr(str, flags.precision);
					ft_putncaract(' ', flags.width - flags.precision);
					return ((flags.width - flags.precision) + flags.precision);
				}
				else if (flags.precision < flags.width)
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
		if (flags.zero && !flags.minus)
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

char*	ft_lltoa_base(long long val, int base)
{
	static char buf[64] = {0};
	int i = 62;
	int sign = (val < 0);
	
	if (sign)
		val = -val;
	if (val == 0)
		return ("0");
	while (val && i)
	{
		buf[i] = "0123456789abcdef"[val % base];
		val /= base;
		--i;
	}
	if (sign)
		buf[i--] = '-';
	return (&buf[i + 1]);
}

int		check_p_w_digit(long long digit, t_flags flags)
{
	char	*number;
	int		yesno;
	int		negdigit;
	int		space2;
	int		space3;

	yesno = 0;
	space2 = 0;
	space3 = 0;
	negdigit = digit;
	if (digit < 0)
		negdigit = -digit;
	if (flags._l)
		number = ft_lltoa_base(digit, 10);
	if (!flags._l)
		number = ft_itoa(digit);
	if (((flags.space && (digit >= 0) && !flags.plus)) && ((1 < ft_strlen(number)) || flags.precision > ft_strlen(number)))
		ft_putchar(' ');
	else if (flags.space)
	{
		flags.space = 0;
		space3 = 1;
	}
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
				return (ft_strlen(number) + flags.space + (flags.width - ft_strlen(number) - yesno));
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
				if (digit > 0)
				{
					ft_putchar('+');
					yesno++;
				}
				ft_putstr(number);
				return (ft_strlen(number) + flags.space + yesno + (flags.width - ft_strlen(number)));
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
				return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number) + (flags.width - flags.precision - yesno) + yesno));
			}
			return (ft_strlen(number) + flags.space + (flags.precision - ft_strlen(number)) + yesno);
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
					return ((flags.width - flags.precision) + flags.space + (flags.precision - ft_strlen(number)) + yesno);
				return ((flags.precision - ft_strlen(number) + flags.space + ft_strlen(number)) + yesno);
			}
			if (flags.precision < ft_strlen(number))
			{
				if (flags.precision < 1)
				{
					ft_putncaract(' ', (flags.width - ft_strlen(number)));
					yesno++;
				}
				ft_putstr(number);
				if (yesno)
					return ((flags.width - ft_strlen(number) + flags.space + ft_strlen(number)));
				return (ft_strlen(number));
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
					if (space3 == 1 && flags.width == 1 && ft_strlen(number) < 2)
						ft_putchar(' ');
					ft_putstr(number);
					return (flags.width + flags.space + space3);
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
				return (ft_strlen(number) + flags.space);
			}
			return (flags.space);
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
		args._d = va_arg(va, long long);
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
			compt.i--;
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
				//if (str[compt.j] == '+' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '-' || str[compt.j - 1] == '0'))
				if (str[compt.j] == '+' && flags.plus < 1)
					flags.plus++;
				if (str[compt.j] == '-' && flags.minus < 1)
					flags.minus++;
				//if (str[compt.j] == '0' && (str[compt.j - 1] == '%' || str[compt.j - 1] == '+'))
				if (str[compt.j] == '0' && flags.zero < 1 && !ft_isdigit(str[compt.j - 1]))
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
			if (str[compt.j - 1] == '%')
				printf("yolo");
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

int		ft_printf(const char *format, ...)
{
	va_list		va;

	va_start(va, format);
	return (parse((char*)format, va));
}

int		main(void)
{
printf("---- Digit ----\n\n");

	ft_printf("[%d]\n", ft_printf("|%01.d| |%02.d| |%03.d| |%1.d| |%2.d| |%.1d| |%.2d|\n", 5, 5, 5, 5, 5, 5, 5));
	printf("[%d]\n", printf("|%01.d| |%02.d| |%03.d| |%1.d| |%2.d| |%.1d| |%.2d|\n", 5, 5, 5, 5, 5, 5, 5));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%01.d| |%02.d| |%03.d| |%1.d| |%2.d| |%.1d| |%.2d|\n", -40, -20, -4, -120, -578, -9, -8));
	printf("[%d]\n", printf("|%01.d| |%02.d| |%03.d| |%1.d| |%2.d| |%.1d| |%.2d|\n", -40, -20, -4, -120, -578, -9, -8));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1.5d| |%1.d| |%-5.d| |%-5.3d| |%+3.d| |%-.5d| |%.d|\n", -4, -2, -4, -1, -5, -9, -8));
	printf("[%d]\n", printf("|%1.5d| |%1.d| |%-5.d| |%-5.3d| |%+3.d| |%-.5d| |%.d|\n", -4, -2, -4, -1, -5, -9, -8));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%01.d| |%02.d| |%03.d| |%1.d| |%2.d| |%.1d| |%.d|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("[%d]\n", printf("|%01.d| |%02.d| |%03.d| |%1.d| |%2.d| |%.1d| |%.d|\n", 0, 0, 0, 0, 0, 0, 0));
	
	printf("\n");
	
	ft_printf("[%d]\n", ft_printf("|%10.d| |%-10.d| |%10.d| |%10.d| |%-10.d| |%5.d| |%-5.d|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("[%d]\n", printf("|%10.d| |%-10.d| |%10.d| |%10.d| |%-10.d| |%5.d| |%-5.d|\n", 0, 0, 0, 0, 0, 0, 0));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1.d| |%2.d| |%3.d| |%1.d| |%2.d| |%.1d| |%.2d|\n", 5, 5, 5, 5, 5, 5, 5));
	printf("[%d]\n", printf("|%1.d| |%2.d| |%3.d| |%1.d| |%2.d| |%.1d| |%.2d|\n", 5, 5, 5, 5, 5, 5, 5));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-1.5d| |%+2.4d| |%-3.d| |%-1.d| |%-2.d| |%-3.1d| |%5.2d|\n", 5, 5, 5, 5, 5, 5, 5));
	printf("[%d]\n", printf("|%-1.5d| |%+2.4d| |%-3.d| |%-1.d| |%-2.d| |%-3.1d| |%5.2d|\n", 5, 5, 5, 5, 5, 5, 5));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1.0d| |%2.1d| |%3.0d| |%1.1d| |%2.0d| |%1.1d| |%1.2d|\n", 5, 5, 5, 5, 5, 5, 5));
	printf("[%d]\n", printf("|%1.0d| |%2.1d| |%3.0d| |%1.1d| |%2.0d| |%1.1d| |%1.2d|\n", 5, 5, 5, 5, 5, 5, 5));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1.1d| |%2.0d| |%3.1d| |%1.0d| |%2.1d| |%1.0d| |%0.2d|\n", 15, 300, 140, 9, 7, 15488, 203));
	printf("[%d]\n", printf("|%1.1d| |%2.0d| |%3.1d| |%1.0d| |%2.1d| |%1.0d| |%0.2d|\n", 15, 300, 140, 9, 7, 15488, 203));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%+1.1d| |%+2.0d| |%+3.1d| |%+1.0d| |%+2.1d| |%+1.0d| |%+0.2d|\n", 15, 300, 140, 9, 7, 15488, 203));
	printf("[%d]\n", printf("|%+1.1d| |%+2.0d| |%+3.1d| |%+1.0d| |%+2.1d| |%+1.0d| |%+0.2d|\n", 15, 300, 140, 9, 7, 15488, 203));

	printf("\n");
	
	ft_printf("[%d]\n", ft_printf("|% 1.1d| |% 2.0d| |% 3.1d| |% 1.0d| |% 2.1d| |% 1.0d| |% 0.2d|\n", 15, 4, 3, 9, 7, 1, 0));
	printf("[%d]\n", printf("|% 1.1d| |% 2.0d| |% 3.1d| |% 1.0d| |% 2.1d| |% 1.0d| |% 0.2d|\n", 15, 4, 3, 9, 7, 1, 0));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%+1.1d| |%+2.0d| |%+3.1d| |%+1.0d| |%+2.1d| |%+1.0d| |%+0.2d|\n", 15, 300, 140, 9, 7, 15488, 203));
	printf("[%d]\n", printf("|%+1.1d| |%+2.0d| |%+3.1d| |%+1.0d| |%+2.1d| |%+1.0d| |%+0.2d|\n", 15, 300, 140, 9, 7, 15488, 203));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1d| |%.10d| |%10d| |%-10d| |%+10d| |%+10.d| |%-10.d|\n", -4, -2, -4, -1, -5, -9, -8));
	printf("[%d]\n", printf("|%1d| |%.10d| |%10d| |%-10d| |%+10d| |%+10.d| |%-10.d|\n", -4, -2, -4, -1, -5, -9, -8));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-.10d| |%+.10d| |% .10d| |%- .5d| |%+ .5d| |%+ .10d|\n", 2, 4, 1, 5, 9, 8));
	printf("[%d]\n", printf("|%-.10d| |%+.10d| |% .10d| |%- .5d| |%+ .5d| |%+ .10d|\n", 2, 4, 1, 5, 9, 8));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-.10d| |%+.10d| |% .10d| |%- .5d| |%+ .5d| |%+ .10d|\n", 0, 0, 0, 0, 0, 0));
	printf("[%d]\n", printf("|%-.10d| |%+.10d| |% .10d| |%- .5d| |%+ .5d| |%+ .10d|\n", 0, 0, 0, 0, 0, 0));
	
	printf("\n");
/*
	// --- U
	printf("---- Unsigned --- \n\n");
	
	ft_printf("|%10x|\n", 42);
	printf("|%10x|\n", 42);

	printf("\n");

	ft_printf("|%01.u| |%02.u| |%03.u| |%1.u| |%2.u| |%.1u| |%.2u|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%01.u| |%02.u| |%03.u| |%1.u| |%2.u| |%.1u| |%.2u|\n", 5, 5, 5, 5, 5, 5, 5);


	printf("\n");

	ft_printf("|%01.u| |%02.u| |%03.u| |%1.u| |%2.u| |%.1u| |%.2u|\n", -40, -20, -4, -120, -578, -9, -8);
	printf("|%01.u| |%02.u| |%03.u| |%1.u| |%2.u| |%.1u| |%.2u|\n", -40, -20, -4, -120, -578, -9, -8);
	
	printf("\n");

	ft_printf("|%1.5u| |%1.u| |%-5.u| |%-5.3u| |%+3.u| |%-.5u| |%8.3u|\n", -4, -2, -4, -1, -5, -9, -8);
	printf("|%1.5u| |%1.u| |%-5.u| |%-5.3u| |%+3.u| |%-.5u| |%8.3u|\n", -4, -2, -4, -1, -5, -9, -8);

	printf("\n");

	ft_printf("|%01.u| |%02.u| |%03.u| |%1.u| |%2.u| |%.1u| |%.u|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%01.u| |%02.u| |%03.u| |%1.u| |%2.u| |%.1u| |%.u|\n", 0, 0, 0, 0, 0, 0, 0);

	printf("\n");
	
	ft_printf("|%10.u| |%-10.u| |%10.u| |%10.u| |%-10.u| |%5.u| |%-5.u|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%10.u| |%-10.u| |%10.u| |%10.u| |%-10.u| |%5.u| |%-5.u|\n", 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n");

	ft_printf("|%1.u| |%2.u| |%3.u| |%1.u| |%2.u| |%.1u| |%.u|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%1.u| |%2.u| |%3.u| |%1.u| |%2.u| |%.1u| |%.u|\n", 5, 5, 5, 5, 5, 5, 5);

	printf("\n");

	ft_printf("|%-1.5u| |%+2.4u| |%-3.u| |%-1.u| |%-2.u| |%-3.1u| |%5.2u|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%-1.5u| |%+2.4u| |%-3.u| |%-1.u| |%-2.u| |%-3.1u| |%5.2u|\n", 5, 5, 5, 5, 5, 5, 5);

	printf("\n");

	ft_printf("|%1.0u| |%2.1u| |%3.0u| |%1.1u| |%2.0u| |%1.1u| |%1.2u|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%1.0u| |%2.1u| |%3.0u| |%1.1u| |%2.0u| |%1.1u| |%1.2u|\n", 5, 5, 5, 5, 5, 5, 5);
	
	printf("\n");

	ft_printf("|%1.1u| |%2.0u| |%3.1u| |%1.0u| |%2.1u| |%1.0u| |%0.2u|\n", 15, 300, 140, 9, 7, 15488, 203);
	printf("|%1.1u| |%2.0u| |%3.1u| |%1.0u| |%2.1u| |%1.0u| |%0.2u|\n", 15, 300, 140, 9, 7, 15488, 203);
	
	printf("\n");

	ft_printf("|%1u| |%.10u| |%10u| |%-10u| |%+10u| |%+10.u| |%-10.u|\n", -4, -2, -4, -1, -5, -9, -8);
	printf("|%1u| |%.10u| |%10u| |%-10u| |%+10u| |%+10.u| |%-10.u|\n", -4, -2, -4, -1, -5, -9, -8);

	printf("\n");

	ft_printf("|% .10lu| |%-.10u| |%+.10u| |% .10u| |%- .5u| |%+ .5u| |%+ .10u|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|% .10lu| |%-.10u| |%+.10u| |% .10u| |%- .5u| |%+ .5u| |%+ .10u|\n", 4, 2, 4, 1, 5, 9, 8);
	
	printf("\n");

	ft_printf("|%.10lu| |%-.10u| |%+.10u| |%.10u| |%-.5u| |%+.5u| |%+.10u|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%.10lu| |%-.10u| |%+.10u| |%.10u| |%-.5u| |%+.5u| |%+.10u|\n", 0, 0, 0, 0, 0, 0, 0);

	printf("\n");

	ft_printf("|%10.lu| |%-10.u| |%10.u| |%10.u| |%-10.u| |%5.u| |%-5.u|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|%10.lu| |%-10.u| |%10.u| |%10.u| |%-10.u| |%5.u| |%-5.u|\n", 4, 2, 4, 1, 5, 9, 8);
	
	printf("\n");

	// --- X

	printf("---- Hexa ----\n\n");	

	ft_printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 5, 5, 5, 5, 5, 5, 5);
	
	printf("\n");

	ft_printf("|%#01.x| |%#02.x| |%03.x| |%1.x| |%2.x| |%.1x| |%.2x|\n", -45, 20, 96000, 2, -1, 60, -47);
	printf("|%#01.x| |%#02.x| |%03.x| |%1.x| |%2.x| |%.1x| |%.2x|\n", -45, 20, 96000, 2, -1, 60, -47);
	
	printf("\n");

	ft_printf("|%#01.X| |%#02.X| |%03.X| |%1.X| |%2.X| |%.1X| |%.2X|\n", -45, 20, 96000, 2, -1, 60, -47);
	printf("|%#01.X| |%#02.X| |%03.X| |%1.X| |%2.X| |%.1X| |%.2X|\n", -45, 20, 96000, 2, -1, 60, -47);
	
	printf("\n");

	ft_printf("|%#01.x| |%#02.x| |%-#03.x| |%#1.x| |%#2.x| |%#-.1x| |%#-.2x|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%#01.x| |%#02.x| |%-#03.x| |%#1.x| |%#2.x| |%#-.1x| |%#-.2x|\n", 0, 0, 0, 0, 0, 0, 0);

	printf("\n");

	ft_printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n");
	
	ft_printf("|%10.x| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%10.x| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 0, 0, 0, 0, 0, 0, 0);

	printf("\n");

	ft_printf("|%#01x| |%#0.10x| |%#010x| |%#0-10x| |%#0+10x| |%#0+10.x| |%#0-10.x|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|%#01x| |%#0.10x| |%#010x| |%#0-10x| |%#0+10x| |%#0+10.x| |%#0-10.x|\n", 4, 2, 4, 1, 5, 9, 8);

	printf("\n");
	
	
	ft_printf("|%+1.1x| |%+2.0x| |%+3.1x| |%+1.0x| |%+2.1x| |%+1.0x| |%+0.2x|\n", 15, 300, 140, 9, 7, 15488, 203);
	printf("|%+1.1x| |%+2.0x| |%+3.1x| |%+1.0x| |%+2.1x| |%+1.0x| |%+0.2x|\n", 15, 300, 140, 9, 7, 15488, 203);
	
	printf("\n");	
	
	ft_printf("|% .10lx| |%-.10x| |%+.10x| |% .10x| |%- .5x| |%+ .5x| |%+ .10x|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|% .10lx| |%-.10x| |%+.10x| |% .10x| |%- .5x| |%+ .5x| |%+ .10x|\n", 4, 2, 4, 1, 5, 9, 8);

	printf("\n");
	
	ft_printf("|%10.lx| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|%10.lx| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 4, 2, 4, 1, 5, 9, 8);
	
	printf("\n");

	// --- O
	printf("---- Octal ----\n\n");		
	
	ft_printf("|%#01.o| |%02.o| |%-03.o| |%1.o| |%2.x| |%-.1o| |%-.2o|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%#01.o| |%02.o| |%-03.o| |%1.o| |%2.o| |%-.1o| |%-.2o|\n", 5, 5, 5, 5, 5, 5, 5);
			
	printf("\n");

	ft_printf("|%01.o| |%02.o| |%03.o| |%1.o| |%2.o| |%.1o| |%.2o|\n", -45, 20, 96000, 2, -1, 60, -47);
	printf("|%01.o| |%02.o| |%03.o| |%1.o| |%2.o| |%.1o| |%.2o|\n", -45, 20, 96000, 2, -1, 60, -47);
	
	printf("\n");

	ft_printf("|%#01.O| |%#02.O| |%03.O| |%1.O| |%2.O| |%.1O| |%.2O|\n", -45, 20, 96000, 2, -1, 60, -47);
	printf("|%#01.O| |%#02.O| |%03.O| |%1.O| |%2.O| |%.1O| |%.2O|\n", -45, 20, 96000, 2, -1, 60, -47);
	
	printf("\n");

	ft_printf("|%#01.o| |%02.o| |%-03.o| |%1.o| |%2.o| |%-.1o| |%-.2o|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%#01.o| |%02.o| |%-03.o| |%1.o| |%2.o| |%-.1o| |%-.2o|\n", 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n");

	ft_printf("|%1.o| |%.1o| |%-1.o| |%-.1o| |%.3o| |%5.o| |%-.2o|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%1.o| |%.1o| |%-1.o| |%-.1o| |%.3o| |%5.o| |%-.2o|\n", 0, 0, 0, 0, 0, 0, 0);

	printf("\n");
	
	
	ft_printf("|%10.o| |%-10.o| |%10.o| |%10.o| |%-10.o| |%5.o| |%-5.o|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%10.o| |%-10.o| |%10.o| |%10.o| |%-10.o| |%5.o| |%-5.o|\n", 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n");
	
	ft_printf("|%#01o| |%#0.10o| |%#010o| |%#0-10o| |%#0+10o| |%#0+10.o| |%#0-10.o|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%#01x| |%#0.10o| |%#010o| |%#0-10o| |%#0+10o| |%#0+10.o| |%#0-10.o|\n", 0, 0, 0, 0, 0, 0, 0);

	printf("\n");

	ft_printf("|%+1.1o| |%+2.0o| |%+3.1o| |%+1.0o| |%+2.1o| |%+1.0o| |%+0.2o|\n", 15, 300, 140, 9, 7, 15488, 203);
	printf("|%+1.1o| |%+2.0o| |%+3.1o| |%+1.0o| |%+2.1o| |%+1.0o| |%+0.2o|\n", 15, 300, 140, 9, 7, 15488, 203);

	printf("\n");
	
	ft_printf("|%-1.5o| |%+2.4o| |%-3.o| |%-1.o| |%-2.o| |%-3.1o| |%5.2o|\n", 125, -78, 58, 8, 48, 1, 0);
	printf("|%-1.5o| |%+2.4o| |%-3.o| |%-1.o| |%-2.o| |%-3.1o| |%5.2o|\n",  125, -78, 58, 8, 48, 1, 0);
	
	printf("\n");
	
	ft_printf("|%+1.1o| |%+2.0o| |%+3.1o| |%+1.0o| |%+2.1o| |%+1.0o| |%+0.2o|\n", 15, 3, 1, 9, 7, 15, 9);
	printf("|%+1.1o| |%+2.0o| |%+3.1o| |%+1.0o| |%+2.1o| |%+1.0o| |%+0.2o|\n", 15, 3, 1, 9, 7, 15, 9);
	
	printf("\n");

	ft_printf("|%#01o| |%#0.10o| |%#010o| |%#0-10o| |%#0+10o| |%#0+10.o| |%#0-10.o|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|%#01o| |%#0.10o| |%#010o| |%#0-10o| |%#0+10o| |%#0+10.o| |%#0-10.o|\n", 4, 2, 4, 1, 5, 9, 8);
	
	printf("\n");
	
	ft_printf("|% .10lo| |%-.10o| |%+.10o| |% .10o| |%- .5o| |%+ .5o| |%+ .10o|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|% .10lo| |%-.10o| |%+.10o| |% .10o| |%- .5o| |%+ .5o| |%+ .10o|\n", 4, 2, 4, 1, 5, 9, 8);

	printf("\n");
	
	ft_printf("|%10.lo| |%-10.o| |%10.o| |%10.o| |%-10.o| |%5.o| |%-5.o|\n", 4, 2, 4, 1, 5, 9, 8);
	printf("|%10.lo| |%-10.o| |%10.o| |%10.o| |%-10.o| |%5.o| |%-5.o|\n", 4, 2, 4, 1, 5, 9, 8);
	
	printf("\n");
*/
	// --- S
	
	printf("---- Chaines de chararacteres ----\n\n");

	ft_printf("[%d]\n", ft_printf("|%01.s| |%02.s| |%03.s| |%1.s| |%2.s| |%.1s| |%.2s|\n", "aa", "bb", "cc", "dd", "ee", "ff", "dd"));
	printf("[%d]\n", printf("|%01.s| |%02.s| |%03.s| |%1.s| |%2.s| |%.1s| |%.2s|\n", "aa", "bb", "cc", "dd", "ee", "ff", "dd"));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%01.s| |%02.s| |%03.s| |%1.s| |%2.s| |%.1s| |%.2s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("[%d]\n", printf("|%01.s| |%02.s| |%03.s| |%1.s| |%2.s| |%.1s| |%.2s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL));

	printf("\n");
	
	ft_printf("[%d]\n", ft_printf("|%10.s| |%-10.s| |%10.s| |%10.s| |%-10.s| |%5.s| |%-5.s|\n",NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("[%d]\n", printf("|%10.s| |%-10.s| |%10.s| |%10.s| |%-10.s| |%5.s| |%-5.s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	
	printf("\n");


	ft_printf("[%d]\n", ft_printf("|%01.s| |%02.s| |%-03.s| |%1.s| |%2.s| |%-.1s| |%-.2s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("[%d]\n", printf("|%01.s| |%02.s| |%-03.s| |%1.s| |%2.s| |%-.1s| |%-.2s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-1.1s| |%+2.6s| |%-3.s| |%-1.s| |%-2.s| |%-3.1s| |%5.2s|\n","aa", "bb", "cc", "dd", "ee", "ff", "dd"));
	printf("[%d]\n", printf("|%-1.1s| |%+2.6s| |%-3.s| |%-1.s| |%-2.s| |%-3.1s| |%5.2s|\n", "aa", "bb", "cc", "dd", "ee", "ff", "dd"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-9.1s| |%+9.6s| |%-7.s| |%-3.s| |%9.s| |%4.1s| |%10.1s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));
	printf("[%d]\n", printf("|%-9.1s| |%+9.6s| |%-7.s| |%-3.s| |%9.s| |%4.1s| |%10.1s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-9.s| |%9.s| |%1.s| |%1.0s| |%1s| |%.1s| |%.6s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));
	printf("[%d]\n", printf("|%-9.s| |%9.s| |%1.s| |%1.0s| |%1s| |%.1s| |%.6s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-9.s| |%9.s| |%1.s| |%1.0s| |%1s| |%.1s| |%.6s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));
	printf("[%d]\n", printf("|%-9.s| |%9.s| |%1.s| |%1.0s| |%1s| |%.1s| |%.6s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-9.3s| |%9.7s| |%1.1s| |%1.9s| |%2.1s| |%3.7s| |%.6s|\n","aaccrrr", "bbccrrr", "ccccrrr", "ddccrrr", "eeccrr", "ffccrrr", "ddccrrr"));
	printf("[%d]\n", printf("|%-9.3s| |%9.7s| |%1.1s| |%1.9s| |%2.1s| |%3.7s| |%.6s|\n","aaccrrr", "bbccrrr", "ccccrrr", "ddccrrr", "eeccrr", "ffccrrr", "ddccrrr"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1s| |%.10s| |%10s| |%-10s| |%+10s| |%+10.s| |%-10.s|\n", "a","b", "c","d", "e","f","g"));
	printf("[%d]\n", printf("|%1s| |%.10s| |%10s| |%-10s| |%+10s| |%+10.s| |%-10.s|\n", "a","b", "c","d", "e","f","g"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|% .3s| |%-.2s| |%+.0s| |% .3s| |%- .2s| |%+ .1s| |%+ .10s|\n","aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));
	printf("[%d]\n", printf("|% .3s| |%-.2s| |%+.0s| |% .3s| |%- .2s| |%+ .1s| |%+ .10s|\n", "aacc", "bbcc", "cccc", "ddcc", "eecc", "ffcc", "ddcc"));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%10.s| |%-10.s| |%10.s| |%10.s| |%-10.s| |%5.s| |%-5.s|\n", "aaccrrr", "bbccrrr", "ccccrrr", "ddccrrr", "eeccrr", "ffccrrr", "ddccrrr"));
	printf("[%d]\n", printf("|%10.s| |%-10.s| |%10.s| |%10.s| |%-10.s| |%5.s| |%-5.s|\n", "aaccrrr", "bbccrrr", "ccccrrr", "ddccrrr", "eeccrr", "ffccrrr", "ddccrrr"));
	
	printf("\n");

	// --- C

	printf("---- Characteres ----\n\n");

	ft_printf("[%d]\n", ft_printf("|%10.c| |%-10.c| |%10.c| |%10.c| |%-10.c| |%5.c| |%-5.c|\n", '0', '0', '0', '0', '0', '0', '0'));
	printf("[%d]\n", printf("|%10.c| |%-10.c| |%10.c| |%10.c| |%-10.c| |%5.c| |%-5.c|\n", '0', '0', '0', '0', '0', '0', '0'));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%01.c| |%02.c| |%03.c| |%1.c| |%2.c| |%-.1c| |%-.2c|\n", '0', '0', '0', '0', '0', '0', '0'));
	printf("[%d]\n", printf("|%01.c| |%02.c| |%03.c| |%1.c| |%2.c| |%-.1c| |%-.2c|\n", '0', '0', '0', '0', '0', '0', '0'));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1c| |%.10c| |%10c| |%-10c| |%+10c| |%+10.c| |%-10.c|\n", 'a','b', 'c','d', 'e','f','g'));
	printf("[%d]\n", printf("|%1c| |%.10c| |%10c| |%-10c| |%+10c| |%+10.c| |%-10.c|\n", 'a','b', 'c','d', 'e','f','g'));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-9.1c| |%+9.6c| |%-7.c| |%-3.c| |%9.c| |%4.1c| |%10.1c|\n",'a','b', 'c','d', 'e','f','g'));
	printf("[%d]\n", printf("|%-9.1c| |%+9.6c| |%-7.c| |%-3.c| |%9.c| |%4.1c| |%10.1c|\n", 'a','b', 'c','d', 'e','f','g'));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%-9.3c| |%9.7c| |%1.1c| |%1.9c| |%2.1c| |%3.7c| |%.6c|\n", 'a','b', 'c','d', 'e','f','g'));
	printf("[%d]\n", printf("|%-9.3c| |%9.7c| |%1.1c| |%1.9c| |%2.1c| |%3.7c| |%.6c|\n", 'a','b', 'c','d', 'e','f','g'));
	
	printf("\n");
	
	ft_printf("[%d]\n", ft_printf("|% .3c| |%-.2c| |%+.0c| |% .3c| |%- .2c| |%+ .1c| |%+ .10c|\n", 'a','b', 'c','d', 'e','f','g'));
	printf("[%d]\n", printf("|% .3c| |%-.2c| |%+.0c| |% .3c| |%- .2c| |%+ .1c| |%+ .10c|\n", 'a','b', 'c','d', 'e','f','g'));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%10.c| |%-10.c| |%10.c| |%10.c| |%-10.c| |%5.c| |%-5.c|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("[%d]\n", printf("|%10.c| |%-10.c| |%10.c| |%10.c| |%-10.c| |%5.c| |%-5.c|\n", 0, 0, 0, 0, 0, 0, 0));
	
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%01.c| |%02.c| |%03.c| |%1.c| |%2.c| |%-.1c| |%-.2c|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("[%d]\n", printf("|%01.c| |%02.c| |%03.c| |%1.c| |%2.c| |%-.1c| |%-.2c|\n", 0, 0, 0, 0, 0, 0, 0));

	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%1c| |%.10c| |%10c| |%-10c| |%+10c| |%+10.c| |%-10.c|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("[%d]\n", printf("|%1c| |%.10c| |%10c| |%-10c| |%+10c| |%+10.c| |%-10.c|\n", 0, 0, 0, 0, 0, 0, 0));
/*
	// --- P
	printf("---- Pointers ----\n\n");
	ft_printf("|%01.p| |%02.p| |%03.p| |%1.p| |%2.p| |%.1p| |%.2p|\n", "aa", "bb", "cc", "dd", "ee", "ff", "dd");
	printf("|%01.p| |%02.p| |%03.p| |%1.p| |%2.p| |%.1p| |%.2p|\n", "aa", "bb", "cc", "dd", "ee", "ff", "dd");
	
	printf("\n");

	ft_printf("|%01.p| |%02.p| |%03.p| |%1.p| |%2.p| |%.1p| |%.2p|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%01.p| |%02.p| |%03.p| |%1.p| |%2.p| |%.1p| |%.2p|\n", 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n");
	
	ft_printf("|%10.p| |%-10.p| |%10.p| |%10.p| |%-10.p| |%5.p| |%-5.p|\n", 0, 0, 0, 0, 0, 0, 0);
	printf("|%10.p| |%-10.p| |%10.p| |%10.p| |%-10.p| |%5.p| |%-5.p|\n", 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n");
	
	ft_printf("|%-1.5p| |%+2.4p| |%-3.p| |%-1.p| |%-2.p| |%-3.1p| |%5.2p|\n", 5, 5, 5, 5, 5, 5, 5);
	printf("|%-1.5p| |%+2.4p| |%-3.p| |%-1.p| |%-2.p| |%-3.1p| |%5.2p|\n", 5, 5, 5, 5, 5, 5, 5);
	
	printf("\n");
	
	ft_printf("|%-9.p| |%9.p| |%1.p| |%1.0p| |%1p| |%.1p| |%.6p|\n", 4, 5, 8, 6, 2, 1, 9);
	printf("|%-9.p| |%9.p| |%1.p| |%1.0p| |%1p| |%.1p| |%.6p|\n", 4, 5, 8, 6, 2, 1, 9);
	
	printf("\n");

	ft_printf("|%-9.3p| |%9.7p| |%1.1p| |%1.9p| |%2.1p| |%3.7p| |%.6p|\n", 4, 5, 8, 6, 2, 1, 9);
	printf("|%-9.3p| |%9.7p| |%1.1p| |%1.9p| |%2.1p| |%3.7p| |%.6p|\n", 4, 5, 8, 6, 2, 1, 9);
	
	printf("\n");

	ft_printf("|%1.1p| |%2.0p| |%3.1p| |%1.0p| |%2.1p| |%1.0p| |%0.2p|\n", 15, 300, 140, 9, 7, 15488, 203);
	printf("|%1.1p| |%2.0p| |%3.1p| |%1.0p| |%2.1p| |%1.0p| |%0.2p|\n", 15, 300, 140, 9, 7, 15488, 203);
	
	printf("\n");
	
	ft_printf("|%01.p| |%02.p| |%-03.p| |%1.p| |%2.p| |%-.1p| |%-.2p|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("|%01.p| |%02.p| |%-03.p| |%1.p| |%2.p| |%-.1p| |%-.2p|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	
	ft_printf("|%1p| |%.10p| |%10p| |%-10p| |%+10p| |%+10.p| |%-10.p|\n", 4, 5, 8, 6, 2, 1, 9);
	printf("|%1p| |%.10p| |%10p| |%-10p| |%+10p| |%+10.p| |%-10.p|\n", 4, 5, 8, 6, 2, 1, 9);
	
	ft_printf("|%10.p| |%-10.p| |%10.p| |%10.p| |%-10.p| |%5.p| |%-5.p|\n",  4, 5, 8, 6, 2, 1, 9);
	printf("|%10.p| |%-10.p| |%10.p| |%10.p| |%-10.p| |%5.p| |%-5.p|\n", 4, 5, 8, 6, 2, 1, 9);
	*/
	return (0);
}
