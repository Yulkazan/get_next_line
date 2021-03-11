/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulkazan <yulkazan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:05:42 by aconcept          #+#    #+#             */
/*   Updated: 2021/03/11 19:07:15 by yulkazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoin_gnl(char *s1, const char *s2);
char		*ft_strchr_gnl(const char *str, int ch);
size_t		ft_strlen_gnl(const char *str);
char		*ft_strdup_gnl(char *src);
char		*ft_strcpy_gnl(char *dst, char *src);
#endif
