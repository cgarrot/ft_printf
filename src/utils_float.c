/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 15:31:36 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 16:39:14 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_countzeros(long double f)
{
	int zer;
	
	f = f - (int)f;
	printf("[%d]\n", (int)f);
	zer = -1;
	while ((int)f == 0)
	{
		f = (float)(f * 10.00);
		zer++;
	}
	return (zer);
}

char	*ft_decpart(long double f, t_flags flags) //LOL IMPOSSIBLE A NORMER SINON T 1 GOD Y'A TROP DE MALLOC TOUT PETES
{
	char	*seg;
	int		dp;
	int		zer;
	int		prec;
	int		i;

	i = 0;
	seg = ft_strnew(0);
	dp = -1;
	f = f - (int)f;
	if (!flags.precision)
		flags.precision = 6;
	prec = flags.precision;
	while (dp < prec)
	{
		if (dp == 7)
		{
			seg = ft_strjoin(seg, ft_itoa((int)f));
			f = f - (int)f;
			dp = 0;
			prec -= 6;
		}
		f = (10 * f);
		dp++;
	}
	if ((int)f != 0)
		seg = ft_strjoin(seg, ft_itoa((int)f));
	while (seg[flags.precision + i] == 53)
		i++;
	if (seg[flags.precision + i] > 53)
		seg[flags.precision - 1] += 1;
	if (ft_strlen(seg) > flags.precision)
		seg = ft_strsub(seg, 0, flags.precision);
	return (seg);
}

char	*ft_ftoa(long double f, char *seg, t_flags flags)
{
	char	*decpart;
	int		pos;
	int		dp;
	int		zer;

	pos = 0;
	dp = 0;
	decpart = ft_strnew(0);
	if (f < 0)
	{
		f *= -1;
		seg[pos++] = '-';
	}
	zer = ft_countzeros(f);
	decpart = ft_decpart(f, flags);
	while (f >= 10.0)
	{
		f = (float)(f / 10.0);
		dp++;
	}
	while (dp >= 0)
	{
		seg[pos++] = 48 + (int)f;
		f = (float)((f - (int)f) * 10.0);
		dp--;
	}
	seg[pos++] = '.';
	while (zer > 0)
	{
		seg[pos++] = 48;
		zer--;
	}
	seg = ft_strjoin(seg, decpart);
	return (seg);
}
