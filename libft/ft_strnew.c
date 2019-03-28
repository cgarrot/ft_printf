/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 07:21:23 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:47:21 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size != 0)
		size++;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (0);
	while (size--)
		str[size] = '\0';
	return (str);
}
