/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:30:24 by fseles            #+#    #+#             */
/*   Updated: 2023/10/02 18:30:26 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_buffer(char **full_string, int fd)
{
	int		i;
	char	*read_buffer;
	int		control;
	char	*p;

	i = 1;
	while(i)
	{
		read_buffer = ft_calloc1(BUFFER_SIZE + 1, sizeof(char));
		if(read_buffer == NULL)
			return (-1);
		control = read(fd, read_buffer, BUFFER_SIZE);
		if (get_position_of_first_newline(read_buffer) >= 0)
			i = -1;
		if (control <= 0)
			return (0);
		p = *full_string;
		*full_string = ft_strjoin1(read_buffer, p);
		if (p != NULL)
			free (p);
		free(read_buffer);
		if (*full_string == NULL)
			return (-1);
	}
	return (1);
}

void	get_return_value(char **string_to_return, char **full_string)
{
	long	position;
	char	*to_delete;

	position = get_position_of_first_newline(*full_string);
	if (position < 0)
		string_to_return = full_string;
	*string_to_return = ft_substr1(*full_string, 0, position + 1);
	to_delete = *full_string;
	*full_string = ft_strjoin1(*full_string + position + 1, "");
	free(to_delete);
}

char	*get_next_line(int fd)
{
	char		*string_to_return;
	static char	*full_string = NULL;
	static int	control = 1;

	string_to_return = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (get_position_of_first_newline(full_string) < 0 || control == 0)
	{
		control = fill_buffer(&full_string, fd);
		if(control == -1)
		{
			if (full_string != NULL)
				free (full_string);
			return (NULL);
		}
	}
	get_return_value(&string_to_return, &full_string);
	return (string_to_return);
}
