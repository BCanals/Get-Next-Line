/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:54:07 by bcanals-          #+#    #+#             */
/*   Updated: 2024/09/24 19:05:09 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	char	*array;
	int		fd;

	fd = open("text", O_RDONLY);
	array = ft_calloc(40);
	printf("lenght: %li\n", ft_strlen(array));
	printf("array: %s\n", array);
	read(fd, array, 4);
	printf("lenght: %li\n", ft_strlen(array));
	printf("array: %s\n", array);
	read(fd, array, 10);
	printf("lenght: %li\n", ft_strlen(array));
	printf("array: %s\n", array);
}
