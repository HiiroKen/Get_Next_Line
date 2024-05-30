/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:38:30 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/30 11:31:08 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*next;
	char		*line;
	int			daer;

	if (next && backslashn(next) != ft_strlen(next))
	{
		line = ft_strdup(next);
		next = ft_substr(next, backslashn(next) + 1, BUFFER_SIZE);
		return (line);
	}
	line = ft_strdup(next);
	free(next);
	next = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	daer = BUFFER_SIZE;
	while (daer == BUFFER_SIZE && daer != -1)
	{
		daer = read(fd, next, BUFFER_SIZE);
		line = ft_strjoin(line, next);
		if (backslashn(next) != BUFFER_SIZE)
			break ;
	}
	next = ft_substr(next, backslashn(next) + 1, BUFFER_SIZE);
	if (ft_strlen(next) == 0 && ft_strlen(line) == 0)
		return (free(next), free(line), NULL);
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i] && i <= backslashn(s2))
		res[j++] = s2[i++];
	free(s1);
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		free(s);
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	j = start;
	while (i < len && s[j])
	{
		str[i] = s[j];
		i++;
		j++;
	}
	free(s);
	return (str);
}

/* int main(int argc, char *argv[])
{
    int     fd;
    char    *line;

    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        line = "";
        while (line)
        {
            line = get_next_line(fd);
            printf("%s",line);
            free(line);
        }
        close(fd);
    }
} */
