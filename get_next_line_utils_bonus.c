/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:12:49 by alexfuen          #+#    #+#             */
/*   Updated: 2025/11/02 17:12:57 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_trunc(char *bytes_read, char *buffer)
{
	size_t	i;
	char	*result;

	i = 0;
	while (bytes_read[i] != '\n')
		i++;
	result = malloc(i + 2);
	if (!result)
	{
		free(buffer);
		free(bytes_read);
		bytes_read = NULL;
		return (NULL);
	}
	i = 0;
	while (bytes_read[i] != '\n')
	{
		result[i] = bytes_read[i];
		i++;
	}
	result[i] = '\n';
	result[i + 1] = '\0';
	return (result);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	my_strchr(char *bytes_read)
{
	size_t	i;

	i = 0;
	while (bytes_read[i])
	{
		if (bytes_read[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*my_realloc(char *s, size_t	size)
{
	char			*result;
	unsigned int	i;

	i = 0;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	while (s[i] && i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	free(s);
	return (result);
}

void	*my_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (dest_cpy > src_cpy)
			dest_cpy[n - i - 1] = src_cpy[n - i - 1];
		else
			dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
