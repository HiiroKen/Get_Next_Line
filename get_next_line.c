/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:38:30 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/22 18:23:46 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
    static char *next;
    char        *line;
    int         daer;

    line = NULL;
    if (!next)
        next = malloc(sizeof(char) * (BUFFER_SIZE +1));
    else if (backslashn(next) != ft_strlen(next))
    {
        line = ft_strjoin(line, next);
        next = ft_substr(next, backslashn(next) + 1, BUFFER_SIZE);
        return (line);
    }
    else
        line = ft_strjoin(line, next);
    ft_bzero(next, BUFFER_SIZE);
    daer = read(fd, next, BUFFER_SIZE);
    while (backslashn(next) == BUFFER_SIZE && daer == BUFFER_SIZE && daer != -1)
    {
        line = ft_strjoin(line, next);
        ft_bzero(next, BUFFER_SIZE);
        daer = read(fd, next, BUFFER_SIZE);
    }
    if (daer != 0 && daer != -1)
        line = ft_strjoin(line, next);
    next = ft_substr(next, backslashn(next) + 1, BUFFER_SIZE);
    return (line);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int main(int argc, char *argv[])
{
    int     fd;

    fd = open(argv[1], O_RDONLY);
    for (int i = 0; i < 340; i++)
        printf("%s",get_next_line(fd));
    close(fd);
}
