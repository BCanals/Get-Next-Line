/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:18:09 by bizcru            #+#    #+#             */
/*   Updated: 2024/09/14 14:07:06 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"


void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*ptr = c;
		i++;
		ptr++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtrn;

	rtrn = malloc(nmemb * size);
	if (rtrn == NULL)
		return (NULL);
	ft_memset(s, 0, n);
	return (rtrn);
}
