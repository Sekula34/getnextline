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

void	set_empty_to_null(char **full_string, char **string_to_return, int *control)
{
	if (*string_to_return != NULL)
	{
		if (*string_to_return[0] == '\0')
		{
			free(*full_string);
			*full_string = NULL;
			*string_to_return = NULL;
			*control = 1;
		}
	}
}

int	fill_buffer(char **full_string, int fd)
{
	int		i;
	char	*read_buffer;
	int		control;
	char	*p;

	i = 1;
	while (i)
	{
		read_buffer = ft_calloc1(BUFFER_SIZE + 1, sizeof(char));
		if (read_buffer == NULL)
			return (-1);
		control = read(fd, read_buffer, BUFFER_SIZE);
		if (control <= 0)
			return (free(read_buffer), control);
		if (get_position_of_first_newline(read_buffer) >= 0)
			i = 0;
		p = *full_string;
		*full_string = ft_strjoin1(p, read_buffer);
		free (p);
		free(read_buffer);
		if (*full_string == NULL)
			return (-1);
	}
	return (1);
}

void	get_return_value(char **ret_str, char **full_string, int *control)
{
	long	position;
	char	*to_delete;

	position = get_position_of_first_newline(*full_string);
	if (position < 0)
	{
		*ret_str = *full_string;
		*control = -1;
		return ;
	}
	*ret_str = ft_substr1(*full_string, 0, position + 1);
	if (*ret_str == NULL)
		return (free(*full_string));
	to_delete = *full_string;
	*full_string = ft_strjoin1(*full_string + position + 1, "");
	if(*full_string == NULL)
	{
		free(ret_str); 
		ret_str = NULL;
	}
	free(to_delete);
}

char	*get_next_line(int fd)
{
	char		*string_to_return;
	static char	*full_string = NULL;
	static int	control = 1;

	string_to_return = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || control == -1)
		return (NULL);
	if (get_position_of_first_newline(full_string) < 0 || control == 0)
	{
		if (control != 0)
			control = fill_buffer(&full_string, fd);
		if (control == -1)
		{
			if (full_string != NULL)
				free (full_string);
			full_string = NULL;
			control = 1;
			return (NULL);
		}
	}
	get_return_value(&string_to_return, &full_string, &control);
	set_empty_to_null(&full_string, &string_to_return, &control);
	return (string_to_return);
}
