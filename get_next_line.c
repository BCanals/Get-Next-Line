/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:49 by bcanals-          #+#    #+#             */
/*   Updated: 2024/09/17 18:00:12 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i + 1);
	buffer += i;
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	char	*temp;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1);
	reading = ft_calloc(BUFFER_SIZE + 1);
	if (!reading || !buffer)
		return (NULL);
	read(fd, reading, BUFFER_SIZE);
	temp = ft_strjoin(buffer, reading);
	free(buffer);
	free(reading);
	buffer = temp;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	//printf("%s\n", buffer);
	line = ft_line(buffer);
	//printf("%s\n", buffer);
	//printf("\n\nnext line:\n");
	//buffer = ft_next(buffer);
	return (line);
}
