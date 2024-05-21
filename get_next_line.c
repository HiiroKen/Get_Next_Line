/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:38:30 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/21 17:33:05 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
    static char *next;
    char        *line;

    next = malloc(sizeof(char) * (BUFFER_SIZE +1));
    read(fd, next, BUFFER_SIZE);
    while (backslashn(next) == BUFFER_SIZE)
    {
        line = ft_strjoin(line, next);
        read(fd, next, BUFFER_SIZE);
    }
    line = ft_strjoin(line, next);
    printf("%s", line);
    return (next);
}

int main(void)
{
    int fd;
    
    fd = open("fd.txt", O_RDONLY);
    get_next_line(fd);
}