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

void	*free_and_null(char **full_string)
{
	free(*full_string);
	*full_string = NULL;
	return (NULL);
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

	if (s == NULL)
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
	p = malloc(size_new_string * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[size_new_string - 1] = '\0';
	return (p);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (len > ft_strlen1(s + start))
		len = ft_strlen1(s + start);
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while ((i < len) && (s[start] != '\0'))
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
