/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:38:30 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/21 18:38:27 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
    static char *next;
    char        *line;

    //printf("%s\n", next);
    line = NULL;
    if (!next)
        next = malloc(sizeof(char) * (BUFFER_SIZE +1));
    else
        line = ft_strjoin(line, next, BUFFER_SIZE);
    read(fd, next, BUFFER_SIZE);
    while (backslashn(next) == BUFFER_SIZE)
    {
        line = ft_strjoin(line, next, BUFFER_SIZE);
        read(fd, next, BUFFER_SIZE);
    }
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
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
}