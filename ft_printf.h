/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 08:24:10 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:26:23 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct	s_flags
{
	unsigned int		hashtag;
	unsigned int		zero;
	unsigned int		minus;
	unsigned int		plus;
	unsigned int		point;
	unsigned int		space;
	char	flag;
	unsigned int		width;
	unsigned int		precision;
	unsigned int		percent;
	unsigned int		_l;
	unsigned int		_h;
	unsigned int		_L;
	unsigned int		nb_caract;
}				t_flags;

typedef struct	s_compt
{
	int		i;
	int		j;
	int		k;
	int		m;
	char	*num;
	char	*num2;
}				t_compt;

typedef struct	s_args
{
	char				*_s;
	int					_d;
	long long			_ld;
	char				_c;
	unsigned int		_u;
	unsigned long long	_lu;
	long long			_x;
	unsigned long		_o;
	void				*_p;
}				t_args;

#endif
