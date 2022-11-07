/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:11:35 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/07 21:23:10 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while(buff[i])
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

char	*ft_join_n_free(char *buffer, char *rbuff)
{
	char	*aux;

	aux = ft_strjoin(buffer, rbuff);
	free(buffer);
	return (aux);
}

char	*file_read(int fd, char *read_buffer)
{
	char	*stash;
	int		bytes;

	if (!read_buffer)
		read_buffer = ft_calloc(1, 1);
	stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		stash[bytes] = 0;
		read_buffer = ft_join_n_free(read_buffer, stash);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(stash);
	return (read_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if( fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0) // change to buffer_size
		return (NULL);
	buff = file_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_readline(buff);
	buff = ft_nextline(buff);
	return (line);
}
