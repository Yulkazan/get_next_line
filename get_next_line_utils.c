/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulkazan <yulkazan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:00:34 by aconcept          #+#    #+#             */
/*   Updated: 2021/03/11 18:59:05 by yulkazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_strchr_gnl(const char *str, int ch)
{
	unsigned char	s;

	s = ch;
	if (*str == s)
		return ((char *)str);
	if (*str == '\0')
		return (NULL);
	while (*str++)
		if (*str == s)
			return ((char *)str);
	return (NULL);
}

char	*ft_strcpy_gnl(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup_gnl(char *src)
{
	char	*dst;

	if (!src)
		return (NULL);
	dst = (char *)malloc(ft_strlen_gnl(src) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy_gnl(dst, src);
	return (dst);
}
