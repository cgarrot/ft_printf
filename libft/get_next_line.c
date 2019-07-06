/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 18:27:53 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/06 15:00:37 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_treat(char **str, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = *str;
	while (tmp[i] != '\n')
		i++;
	*line = ft_strsub(*str, 0, i);
	tmp = *str;
	*str = ft_strsub(tmp, i + 1, ft_strlen(*str) - (i + 1));
	free(tmp);
	return (1);
}

int			ft_readline(int const fd, char *buffer, char **str, char **line)
{
	int		res;
	char	*tmp;

	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[res] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(*str, '\n') != NULL)
			return (ft_treat(str, line));
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*str[10240];
	char		*tmp;

	if (fd < 0 || read(fd, buffer, 0) == -1 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (!str[fd])
		str[fd] = ft_strnew(0);
	if (ft_strchr(str[fd], '\n') != NULL)
		return (ft_treat(&str[fd], line));
	if (ft_readline(fd, buffer, &str[fd], line) == 1)
		return (1);
	else
	{
		if (ft_strlen(str[fd]) > 0)
		{
			tmp = str[fd];
			str[fd] = ft_strjoin(tmp, "\n");
			free(tmp);
			return (ft_treat(&str[fd], line));
		}
	}
	return (0);
}
