/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:02:04 by bizcru            #+#    #+#             */
/*   Updated: 2024/09/17 18:31:54 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int	fd;
	char *buf;

	fd = open("text", O_RDONLY);
	if (fd == -1)
		printf("Cannot read file.\n");
	buf = malloc(11*sizeof(char));
	int i = 0;
	while (i < 10)
		buf[i++] = 0;
	read(fd, buf, 10);
	printf("%s\n", buf);
	read(fd, buf, 10);
	printf("%s\n", buf);
	free(buf);
	close(fd);
}
