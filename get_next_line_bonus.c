/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:52:30 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/08 14:43:45 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_nextline(char *buff)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		aux[j++] = buff[i++];
	free(buff);
	return (aux);
}

char	*ft_readline(char *buff)
{
	char	*line;
	int		count;

	count = 0;
	if (!buff[count])
		return (NULL);
	while (buff[count] != '\n' && buff[count])
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (buff[count] != '\n' && buff[count])
	{
		line[count] = buff[count];
		count++;
	}
	if (buff[count] == '\n' && buff[count])
		line[count++] = '\n';
	return (line);
}

char	*ft_join_n_free(char *stash, char *rbuff)
{
	char	*aux;

	aux = ft_strjoin(stash, rbuff);
	free(stash);
	return (aux);
}

char	*file_read(int fd, char *stash)
{
	char	*read_buffer;
	int		bytes;

	if (!stash)
		stash = ft_calloc(1, 1);
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes] = 0;
		stash = ft_join_n_free(stash, read_buffer);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[OPEN_MAX];

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = file_read(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_readline(buff[fd]);
	buff[fd] = ft_nextline(buff[fd]);
	return (line);
}
