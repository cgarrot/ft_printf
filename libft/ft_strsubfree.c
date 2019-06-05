/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsubfree.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:35:07 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 15:35:47 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s1, size_t start, size_t len)
{
	char	*str;

	str = ft_strsub(s1, start, len);
	free(s1);
	return (str);
}
