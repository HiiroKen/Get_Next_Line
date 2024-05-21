/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:38:30 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/21 18:49:36 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
    static char *next;
    char        *line;
    int         daer;

    //printf("%s\n", next);
    line = NULL;
    if (!next)
        next = malloc(sizeof(char) * (BUFFER_SIZE +1));
    else
        line = ft_strjoin(line, next, BUFFER_SIZE);
    daer = read(fd, next, BUFFER_SIZE);
    while (backslashn(next) == BUFFER_SIZE && daer != 0 && daer != -1)
    {
        line = ft_strjoin(line, next, BUFFER_SIZE);
        daer = read(fd, next, BUFFER_SIZE);
    }
    if (daer != 0 && daer != -1)
        line = ft_strjoin(line, next, backslashn(next) + ft_strlen(line) + 2);
    next = ft_substr(next, backslashn(next) + 1, BUFFER_SIZE);
    //printf("%s\n", next);
    return (line);
}

int main(void)
{
    int fd;
    char    *line;
    fd = open("fd.txt", O_RDONLY);
    for (int i = 0; i < 5; i++)
        printf("%s",get_next_line(fd));
   close(fd);
}