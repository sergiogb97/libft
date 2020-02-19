/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:37:19 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/17 15:28:28 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_output(char **s, char **line, int ret)
{
	char	*aux;
	char	*tmp;

	if (ret < 0)
		return (-1);
	if (!ret && !*s)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((aux = ft_strchr(*s, '\n')))
	{
		*aux = '\0';
		*line = ft_strdup(*s);
		tmp = ft_strdup(++aux);
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char *s[4096];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_output(&s[fd], line, ret));
}
