/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:54:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 11:08:57 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	print_nb_caract(char c, int size)
{
	while (size--)
		write(1, &c, 1);
}

/*void	print_extra(char *str, char c, int i)
{
	if 
}*/

int		check_caract(char *str, int cst)
{
	int		i;
	int		count;
	int		c1;
	int		tmp;
	char	*nb;

	i = -1;
	count = 0;
	c1 = -1;
	while (--cst)
		while (str[++i])
			if (str[i] == '%')
			{
				i++;
				while (str[i] == ' ')
					i++;
				if (str[i] == '-' || str[i] == '+')
				{
					tmp = i + 1;
					while (ft_isdigit(str[tmp]))
						count++;
					if (!(nb = malloc(sizeof(char) * count + 1)))
							return (0);
					tmp = i + 1;
					while (ft_isdigit(str[tmp]))
						nb[++c1] = str[tmp];
					nb[count + 1] = '\0';
					if (ft_atoi(nb) > ft_strlen(/*argument*/))
						print_nb_caract(' ', ft_atoi(nb) - ft_strlen(/*argument*/));
				}
			}
	return (0);
}

int		parse(char *str)
{
	int		i;
	int		cst;

	cst = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '%')
			cst++;
	if (!cst)
		ft_putstr(str);
	else
		check_caract(str, cst + 1);
	return (0);
}

/*int		for_digit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '%' && str[i + 1] == 'd')
			return (1);
	return (0);
}*/

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	if (for_digit((char*)format))
		ft_putnbr(va_arg(ap, int));
	va_end(ap);
	return (0);
}

int		main(void)
{
	ft_printf("%d", 123);
	return (0);
}
