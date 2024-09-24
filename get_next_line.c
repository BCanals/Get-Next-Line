/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:49 by bcanals-          #+#    #+#             */
/*   Updated: 2024/09/24 20:47:34 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_next(char *buffer, char *line)
{
	char	*new_buffer;
	size_t	buf_len;
	size_t	line_len;

	line_len = ft_strlen(line);
	buf_len = ft_strlen(buffer) - line_len;
	new_buffer = ft_calloc(buf_len + 1);
	if (!new_buffer)
		return (NULL);
	new_buffer = ft_memcpy(new_buffer, buffer + line_len, buf_len);
	free(buffer);
	return (new_buffer);
}

char	*ft_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	int		read_bytes;

	while (!ft_strchr(buffer, '\n'))
	{
		reading = ft_calloc(BUFFER_SIZE + 1);
		if (!reading)
			return (NULL);
		read_bytes = read(fd, reading, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(reading);
			return (NULL);
		}
		else if (read_bytes == 0)
		{
			free(reading);
			break ;
		}
		else
			buffer = ft_strjoin(buffer, reading);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1);
	if (!buffer)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		return (NULL);
	buffer = ft_next(buffer, line);
	return (line);
}
