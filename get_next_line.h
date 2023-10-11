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

size_t	ft_strlen1(const char *s);
long	get_position_of_first_newline(char *s);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
void	*free_and_NULL(char **full_string);
char	*get_next_line(int fd);

#endif