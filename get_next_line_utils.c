/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:10:24 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/06 19:52:31 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	int		lenght;
	char	*aux;

	lenght = ft_strlen(str);
	aux = (char *)malloc(sizeof(char) * lenght + 1);
	if (!aux)
		return (NULL);
	lenght = 0;
	while (str[lenght])
	{
		aux[lenght] = str[lenght];
		lenght++;
	}
	aux[lenght] = '\0';
	return (aux);
}

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux] != '\0')
		aux++;
	return (aux);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = malloc(len);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, len);
	ft_strlcat(strjoin, s2, len);
	return (strjoin);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
