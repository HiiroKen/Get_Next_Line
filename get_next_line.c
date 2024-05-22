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
    else
    {
        line = ft_strjoin(line, next);
        printf("\n|line:%s|\n", next);
    }
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
    printf("\n|before:%s|\n", next);
    next = ft_substr(next, backslashn(next) + 1, BUFFER_SIZE);
    printf("\n|after:%s|\n", next);
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
    char    *erreur = "erreur.txt";
    char    *fdt = "fd.txt";
    int     nbr;

    nbr = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (strncmp(argv[1], erreur, ft_strlen(erreur)) == 0)
            nbr = 4;
        else if (strncmp(argv[1], fdt, ft_strlen(fdt)) == 0)
            nbr = 296;
        for (int i = 0; i < nbr; i++)
            printf("%s",get_next_line(fd));
        close(fd);
    }
}
