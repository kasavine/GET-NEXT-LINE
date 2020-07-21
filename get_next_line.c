/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isak <isak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:22:14 by isak              #+#    #+#             */
/*   Updated: 2020/07/21 14:04:18 by isak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh_new;
	size_t			len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	fresh_new = (char *)malloc((len + 1) * sizeof(char));
	if (fresh_new == NULL)
		return (NULL);
	ft_strcpy(fresh_new, s1);
	ft_strcat(fresh_new, s2);
	return (fresh_new);
}

char				*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char				*check_rem(char *rem, char **line)
{
	char			*p_n;

	p_n = NULL;
	if (rem)
	{
		if ((p_n = ft_strchr(rem, '\n')))
		{
			*p_n = '\0';
			*line = ft_strjoin("", rem);
			ft_strcpy(rem, ++p_n);
		}
		else
		{
			*line = ft_strjoin("", rem);
			ft_strclr(rem);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (p_n);
}

int					get_next_line(int fd, char **line)
{
	static char		*rem;
	char			*p_n;
	int				bwr;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	p_n = check_rem(rem, line);
	while (!p_n && (bwr = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bwr] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			rem = ft_strjoin("", p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((bwr || ft_strlen(rem) || ft_strlen(*line)) ? 1 : 0);
}
