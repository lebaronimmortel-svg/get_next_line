/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:12:41 by alexfuen          #+#    #+#             */
/*   Updated: 2025/11/02 17:12:44 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
char			*ft_strdup(char *src);
int				my_strchr(char *bytes_read);
void			*my_memmove(void *dest, const void *src, size_t n);
char			*my_realloc(char *s, size_t	size);
char			*my_trunc(char *bytes_read, char *buffer);

#endif
