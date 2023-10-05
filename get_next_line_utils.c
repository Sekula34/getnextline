/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:30:37 by fseles            #+#    #+#             */
/*   Updated: 2023/10/02 18:30:39 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc1(size_t nmemb, size_t size)
{
	void	*p;
	char	*s;
	int		i;
	size_t	n;

	i = 0;
	p = malloc (size * nmemb);
	if (p == NULL)
		return (NULL);
	s = (char *)p;
	n = nmemb * sizeof(char);
	while (n > 0)
	{
		s[i] = '\0';
		i++;
		n--;
	}
	return (p);
}

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

long	get_position_of_first_newline(char *s)
{
	long	i;

	if(s == NULL)
		return (-2);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	size_t	size_new_string;
	char	*p;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	size_new_string = ft_strlen1(s1) + ft_strlen1(s2) + 1;
	p = ft_calloc1(size_new_string, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0' && s1 != NULL)
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2 != NULL)
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	return (p);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (start >= ft_strlen1(s) || len == 0)
	{
		p = ft_calloc1(1, 1);
		return (p);
	}
	if (len > ft_strlen1(s + start))
		len = ft_strlen1(s + start);
	p = ft_calloc1(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	while ((i < len) && (s[start] != '\0'))
	{
		p[i] = s[start];
		i++;
		start++;
	}
	return (p);
}
