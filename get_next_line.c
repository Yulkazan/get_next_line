/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulkazan <yulkazan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:48:46 by aconcept          #+#    #+#             */
/*   Updated: 2021/03/11 19:00:12 by yulkazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew_ez(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ost_checker(char **ost, char **line)
{
	char	*smp;

	smp = NULL;
	if (*ost)
	{
		if ((smp = ft_strchr_gnl(*ost, '\n')))
		{
			*smp = '\0';
			*line = ft_strdup_gnl(*ost);
			*ost = ft_strcpy_gnl(*ost, ++smp);
		}
		else
		{
			*line = ft_strdup_gnl(*ost);
			free(*ost);
			*ost = NULL;
		}
	}
	else
		*line = ft_strnew_ez();
	return (smp);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			bwr;
	char		*extra_buf;
	static char	*ost;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, buf, 0) < 0))
		return (-1);
	extra_buf = ost_checker(&ost, line);
	while (!extra_buf && (bwr = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bwr] = '\0';
		if ((extra_buf = ft_strchr_gnl(buf, '\n')))
		{
			*extra_buf = '\0';
			if (!(ost = ft_strdup_gnl(++extra_buf)))
				return (-1);
		}
		if (!(*line = ft_strjoin_gnl(*line, buf)))
			return (-1);
	}
	if (!ost && !bwr)
		return (0);
	return (1);
}
