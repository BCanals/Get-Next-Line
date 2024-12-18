/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:49 by bcanals-          #+#    #+#             */
/*   Updated: 2024/10/08 18:23:02 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_next(char *buffer, char *line)
{
	char	*new_buffer;
	size_t	buf_len;
	size_t	line_len;

	line_len = ft_strlen(line);
	buf_len = ft_strlen(buffer) - line_len;
	new_buffer = ft_calloc(buf_len + 1);
	if (!new_buffer)
		return (ft_free(&line), ft_free(&buffer));
	new_buffer = ft_memcpy(new_buffer, buffer + line_len, buf_len);
	ft_free(&buffer);
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
		return (ft_free(&line));
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
			return (ft_free(&reading), ft_free(&buffer));
		else if (read_bytes == 0)
		{
			ft_free(&reading);
			return (buffer);
		}
		buffer = ft_strjoin(buffer, reading);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			ft_free(&buffer);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(1);
	if (!buffer)
		return (ft_free(&buffer));
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!*buffer)
		return (ft_free(&buffer));
	line = ft_line(buffer);
	if (!line)
		return (ft_free(&buffer), ft_free(&line));
	buffer = ft_next(buffer, line);
	if (!buffer)
		return (ft_free(&buffer));
	return (line);
}
