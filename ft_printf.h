/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 08:24:10 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 09:38:15 by cgarrot     ###    #+. /#+    ###.fr     */
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
}				t_flags;

typedef struct	s_compt
{
	int		i;
	int		j;
	int		k;
	char	*num;
	char	*num2;
}				t_compt;

#endif
