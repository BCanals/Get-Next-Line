/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:37:40 by bizcru            #+#    #+#             */
/*   Updated: 2024/09/14 12:58:35 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*read_line;

	if (argc == 1)
	{
		printf("File name missing.\n");
		return (0);
	}
	else if (argc > 2)
	{
		printf("Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot read file.\n");
		return (0);
	}
	printf("fd = %i\n", fd);
	read_line = get_next_line(fd);
	if (!read_line)
	{
		printf("read_line not available");
		return (0);
	}
	printf("%s", read_line);
	free(read_line);
	close(fd);
}
