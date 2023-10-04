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

int	first_and_last_case(int number, char *big_buffer)
{
	if (number == 1)
	{
		big_buffer = ft_calloc1(BUFFER_SIZE, sizeof(char));
		if (big_buffer == NULL)
			return (-1); 
	}
	if (number == 0)
	{
		free(big_buffer);
		return (0);
	}
	return (1);
}

int	filling_big_buffer_til_newline(char *big_buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char *big_buffer; 
	static long	called = 0;

	if (fd < 0)
		return (NULL);
	called ++;
	if (first_and_last_case(called, big_buffer) <= 0)
		return(NULL);
	if(get_position_of_first_newline(big_buffer) == -1)
	{

	}


}
