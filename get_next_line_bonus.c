/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:12:31 by alexfuen          #+#    #+#             */
/*   Updated: 2025/11/02 17:12:33 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*cut(char **bytes_read, char *buffer)
{
	char	*result;
	int		index[2];

	index[0] = 0;
	index[1] = 0;
	if (my_strchr(*bytes_read) == 1)
	{
		result = my_trunc(*bytes_read, buffer);
		if (!result)
			return (NULL);
		while (result[index[0]])
			index[0]++;
		while ((*bytes_read + index[0])[index[1]])
			index[1]++;
		my_memmove(*bytes_read, *bytes_read + index[0], index[1] + 1);
		free(buffer);
		return (result);
	}
	result = ft_strdup(*bytes_read);
	free(buffer);
	free(*bytes_read);
	*bytes_read = NULL;
	return (result);
}

static char	*file_end(char **bytes_read, char *buffer, ssize_t to_read)
{
	char	*result;
	int		i;

	i = 0;
	if (to_read < 0 || to_read > BUFFER_SIZE)
	{
		free(buffer);
		free(*bytes_read);
		*bytes_read = NULL;
		return (NULL);
	}
	while ((*bytes_read)[i])
		i++;
	if (to_read == 0 && i != 0)
	{
		result = cut(bytes_read, buffer);
		return (result);
	}
	free(buffer);
	free(*bytes_read);
	*bytes_read = NULL;
	return (NULL);
}

static int	extract(ssize_t *ind, char *buf, char **res, char **stock)
{
	buf[ind[5]] = '\0';
	while ((*stock)[ind[0]])
		ind[0]++;
	*stock = my_realloc(*stock, ind[5] + ind[0]);
	if (!(*stock))
		return (-1);
	while (buf[ind[1]])
	{
		(*stock)[ind[0] + ind[1]] = buf[ind[1]];
		ind[1]++;
	}
	(*stock)[ind[0] + ind[1]] = '\0';
	if (my_strchr(*stock) == 1)
	{
		*res = my_trunc(*stock, buf);
		if (!(*res))
			return (-1);
		while ((*res)[ind[2]])
			ind[2]++;
		while ((*stock + ind[2])[ind[3]])
			ind[3]++;
		my_memmove(*stock, *stock + ind[2], ind[3] + 1);
		return (1);
	}
	return (0);
}

static int	init(char **bytes_read, char **buffer, int fd, ssize_t *index)
{
	int	i;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (-1);
	if (!(*bytes_read))
	{
		*bytes_read = malloc(1);
		if (!(*bytes_read))
			return (-1);
		*bytes_read[0] = '\0';
	}
	*buffer = malloc((size_t)(BUFFER_SIZE + 1));
	if (!(*buffer))
	{
		free(*bytes_read);
		return (-1);
	}
	i = 0;
	while (i < 7)
		index[i++] = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t			index[7];
	static char		*bytes_read[4096];
	char			*array[2];

	if (init(&bytes_read[fd], &array[0], fd, index) < 0)
		return (NULL);
	index[5] = read(fd, array[0], BUFFER_SIZE);
	while (index[5] > 0)
	{
		index[4] = extract(index, array[0], &array[1], &bytes_read[fd]);
		if (index[4] != 0)
			free(array[0]);
		if (index[4] == -1)
			free(bytes_read[fd]);
		if (index[4] == -1)
			return (NULL);
		else if (index[4] == 1)
			return (array[1]);
		index[6] = 0;
		while (index[6] < 6)
			index[index[6]++] = 0;
		index[5] = read(fd, array[0], BUFFER_SIZE);
	}
	array[1] = file_end(&bytes_read[fd], array[0], index[5]);
	return (array[1]);
}
