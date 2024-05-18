/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:25:57 by davifer2          #+#    #+#             */
/*   Updated: 2024/02/23 20:32:57 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

#include <fcntl.h>
#include "libft.h"

char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, int len);
char *ft_strdup(const char *str);
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(const char *str);
void *ft_calloc(size_t count, size_t size);

#endif
