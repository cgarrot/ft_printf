/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 08:24:10 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 14:21:39 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_flags
{
	int		hashtag;
	int		zero;
	int		minus;
	int		plus;
	int		point;
	char	flag;
	int		width;
	int		precision;
	int		nb_caract;
}				t_flags;

typedef struct	s_compt
{
	int		i;
	int		j;
	int		k;
	char	*num;
	char	*num2;
}				t_compt;

typedef struct	s_args
{
	char	*_s;
	int		_d;
}				t_args;

#endif
