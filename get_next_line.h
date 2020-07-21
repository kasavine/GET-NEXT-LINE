/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isak <isak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:24:48 by isak              #+#    #+#             */
/*   Updated: 2020/07/21 14:03:35 by isak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h> // read, write
#include <stdio.h> // printf

#include <limits.h>

#include <fcntl.h> // open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif


size_t		ft_strlen(const char *s);
void		ft_strclr(char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*check_remainder(char *remainder, char **line);
int			get_next_line(int fd, char **line);


char		*ft_strcat(char *dst, const char *src);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strnew(size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);

#endif
