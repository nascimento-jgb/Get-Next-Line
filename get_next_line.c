/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:10:04 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/06 19:52:33 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10000
#define FD_SIZE 2058

static int	read_add_line(char **str, char **line, int file, int fd)
{
	int		count;
	char	*aux;

	if (file < 0)
		return (-1);
	else if (file == 0 && !str[fd])
		return (0);
	count = 0;
	while (*str[count] && *str[count] != '\n')
		count++;
	if ((*str)[count] == '\n')
	{
		*line = ft_strsub(str, 0, count);
		aux = ft_strdup(&str[count +1]);
		ft_free(str, ft_strlen(str));
		*str = aux;
		if (!str[0])
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

void	ft_free(char *str, unsigned int len)
{
	if (!str)
		return ;
	while (len--)
		*str++ = '\0';
	free(str);
}

void	ft_strdel(void **str)
{
	if (!str)
		return ;
	else if (str)
	{
		free(*str);
		*str = NULL;
	}
}

int	get_next_line(const int fd, char **line)
{
	int			file;
	char		*aux;
	char		buf[BUFFER_SIZE + 1];
	static char	str[FD_SIZE];

	if (!line || fd < 0 || fd > FD_SIZE)
		return (-1);
	file = read(fd, buf, BUFFER_SIZE);
	while (file)
	{
		buf[file] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buf);
		else
		{
			aux = ft_strjoin(str[fd], buf);
			ft_free(str[fd], ft_strlen(str[fd]));
			str[fd] = aux;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		file = read(fd, buf, BUFFER_SIZE);
	}
	return (read_add_line(str, line, file, fd));
}
