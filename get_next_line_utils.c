/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:33:11 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/30 11:26:26 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	backslashn(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	mem = (void *) malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (size * nmemb));
	return (mem);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*d;

	if (!s)
		return (NULL);
	d = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
	{
		d[j] = s[i];
		i++;
		j++;
	}
	if (s[i] == '\n')
		d[j++] = '\n';
	d[j] = '\0';
	return (d);
}

/* char	*ft_strjoin(char *s1, char *s2)
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
		return ft_strdup("");
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
} */
