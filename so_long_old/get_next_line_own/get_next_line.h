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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *str);

#endif
