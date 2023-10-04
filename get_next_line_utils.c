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

long	get_position_of_first_newline(char *s)
{
	long i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}
