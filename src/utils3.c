/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/05 18:02:06 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/25 18:39:58 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*octa_zero(char *seg)
{
	seg = ft_strnew(1);
	seg[0] = 48;
	return (seg);
}

int		ret_int(unsigned long long n, int base)
{
	int		j;

	j = 0;
	while (n != 0)
	{
		n = n / base;
		j++;
	}
	return (j);
}
