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

void	clean_buffer(char **full_string, char *string_to_return)
{
	char *to_delete;
	int		pos_nl;

	if(full_string == NULL)
		return;
	pos_nl = ft_strlen1(string_to_return);
	// if(ft_strlen1(*full_string) == ft_strlen1(string_to_return))
	// {
	// 	free(*full_string);
	// 	*full_string = NULL;
	// 	return ;
	// }
	to_delete = *full_string;
	*full_string = ft_strjoin1(*full_string + pos_nl, NULL);
	free(to_delete);
}

char	*get_return_value(char *full_string)
{
	int position_of_newline;

	if(full_string == NULL || full_string[0] == '\0')
		return (NULL);
	position_of_newline = get_position_of_first_newline(full_string);
	if(position_of_newline <= -1)
		position_of_newline = ft_strlen1(full_string) - 1;
	return (ft_substr1(full_string, 0, position_of_newline + 1));

}

int	buffer_filler(char **buffer, int fd)
{
	char		*helper_var;
	long long	read_val;

	while (1)
	{
		helper_var = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (helper_var == NULL)
			return (-1);
		read_val = read(fd, helper_var, BUFFER_SIZE);
		if (read_val <= 0)
			return (free(helper_var), read_val);
		helper_var[read_val] = '\0';
		*buffer = ft_strjoin1(*buffer, helper_var);
		if(*buffer == NULL)
			return(free(helper_var), -1); 
		if (get_position_of_first_newline(helper_var) >= 0)
		{
			free (helper_var);
			break;
		}
		free(helper_var);
	}
	return (1);
}


char	*get_next_line(int fd)
{
	char		*string_to_return;
	static char	*full_string = NULL;
	int			status;

	string_to_return = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (get_position_of_first_newline(full_string) < 0)
	{
		status = buffer_filler(&full_string, fd);
		if (status == -1)
		{
			free (full_string);
			full_string = NULL;
			return (NULL);
		}
	}
	string_to_return = get_return_value(full_string);
	if(string_to_return == NULL)
	{
		free(full_string);
		full_string = NULL;
		return NULL;
	}
	clean_buffer(&full_string, string_to_return);
	return (string_to_return);
}
