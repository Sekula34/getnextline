/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:30:46 by fseles            #+#    #+#             */
/*   Updated: 2023/10/02 18:30:47 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc1(size_t nmemb, size_t size);
char	*get_next_line(int fd);
long	get_position_of_first_newline(char *s);


#endif