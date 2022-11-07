/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:11:35 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/07 14:27:35 by jonascim         ###   ########.fr       */
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
		buff++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	aux = ft_calloc(ft_strlen(buff - i + 1), sizeof(char));
	j = 0;
	while(buff)
		aux[j++] = buff[i++];
	free(buff);
	return (aux);
}

char	*ft_readline(char *buff)
{
	char	*line;
	int		count;

	count = 0;
	if (buff)
		return (NULL);
	while (buff[count] != '\n' && buff)
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (buff[count++] != '\n' && buff)
		line[count] = buff[count];
	if (buff[count] == '\n' && buff)
		line[count++] = '\n';
	return (line);
}

char	*ft_free(char *read_buffer, char *buff)
{
	char	*aux;

	aux = ft_strjoin(read_buffer, buff);
	free(read_buffer);
	return (aux);
}

char	*read_file(int fd, char *buff)
{
	char	*read_buffer;
	int		bytes;

	if (!buff)
		buff = ft_calloc(1,1);
	read_buffer = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, read_buffer, BUFF_SIZE); //change to buffer_size
		if (bytes == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes] = 0;
		buff = ft_free(read_buffer, buff); //join and free
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(buff);
	return (read_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	printf("%c",'A');
	if( fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE < 0) // change to buffer_size
		return (NULL);
	printf("%c",'A');
	buff = read_file(fd, buff);
	printf("%c",'A');
	if (!buff)
		return (NULL);
	printf("%c",'A');
	line = ft_readline(buff);
	buff = ft_nextline(buff);
	return (line);
}
