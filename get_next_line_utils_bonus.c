/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:51:59 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/08 14:43:48 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (len + 1));
	if (!strjoin || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[len] = 0;
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != c && *aux != 0)
		aux++;
	if (*aux == c)
		return (aux);
	else
		return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;

	aux = malloc(count * size);
	if (!aux)
		return (NULL);
	ft_bzero(aux, count * size);
	return (aux);
}

void	ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	i;

	aux = (char *)s;
	i = 0;
	while (i < n)
		aux[i++] = '\0';
}

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux])
		aux++;
	return (aux);
}
