/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:15:57 by davifer2          #+#    #+#             */
/*   Updated: 2024/02/23 20:22:57 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

size_t ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	char *substring;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substring = ft_calloc((len + 1), sizeof(char));
	if (!substring)
		return (0);
	ft_strlcpy(substring, (char *)s + start, len + 1);
	return (substring);
}

char *ft_strdup(const char *src)
{
	char *dest;
	int i;
	int size;

	i = 0;
	size = 0;
	while (src[size])
		i++;
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[size] = '\0';
	return (dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

size_t ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;
	size_t i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void *ft_calloc(size_t nitems, size_t size)
{
	size_t total_size;
	void *p;

	total_size = nitems * size;
	p = malloc(total_size);
	if (p != NULL)
	{
		ft_memset(p, 0, total_size);
	}
	return (p);
}