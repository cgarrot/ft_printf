/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_float.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 15:31:36 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 16:10:11 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_countzeros(long double f)
{
	int zer;

	f = f - (int)f;
	zer = -1;
	while ((int)f == 0)
	{
		f = (float)(f * 10.00);
		zer++;
	}
	return (zer);
}

char	*ft_decpart(long double f, t_flags flags, int zer) //LOL IMPOSSIBLE A NORMER SINON T 1 GOD Y'A TROP DE MALLOC TOUT PETES
{
	char	*seg;
	int		dp;
	int		prec;
	int		i;
	int		skurt;

	i = 0;
	seg = ft_strnew(0);
	dp = -1;
	f = f - (int)f;
	if (!flags.precision)
	{
		flags.precision = 6;
		skurt = 1;
	}
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
		f = (10.00 * f);
		dp++;
	}
	if ((int)f != 0)
		seg = ft_strjoin(seg, ft_itoa((int)f));
		while (seg[flags.precision - zer + i] == 53)
			i--;

		if (seg[flags.precision - zer + i] >= 53 || !seg[flags.precision - zer + i])
		{
			while (seg[flags.precision - zer + i] == '9' && i != -flags.precision)
			{
				seg[flags.precision - zer + i] = '0';
				i--;
			}
			if (seg[flags.precision - zer + i] == '9')
				seg[flags.precision - zer + i] = 48;
			else
				seg[flags.precision - zer + i] += 1;
		}
	//printf("[[%s]]\n", seg);
	if (seg[0] == ';' || (skurt == 1 && seg[0] >= 53 && flags.point))
		return ("0");
	if (ft_strlen(seg) + zer > flags.precision)
		seg = ft_strsub(seg, 0, flags.precision - zer);


	return (seg);
}

char	*ft_ftoa(long double f, char *seg, t_flags flags)
{
	char	*decpart;
	int		pos;
	int		dp;
	int		zer;

	if (f == 0.0)
		return ("0");
	pos = 0;
	dp = 0;
	decpart = ft_strnew(0);
	if (f < 0)
	{
		f *= -1;
		seg[pos++] = '-';
	}
	zer = ft_countzeros(f);
	decpart = ft_decpart(f, flags, zer);
	if (ft_strcmp(decpart, "0") == 0)
		f = f + 1;
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
