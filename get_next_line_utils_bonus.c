/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:18:09 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/09 17:32:07 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_calloc(size_t size)
{
	char	*rtrn;
	size_t	i;

	rtrn = malloc(size);
	if (rtrn == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		rtrn[i++] = '\0';
	return (rtrn);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	size;
	char			*rtrn;
	unsigned int	s1_len;
	unsigned int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	rtrn = malloc(size);
	if (rtrn == NULL)
		return (NULL);
	ft_memcpy(rtrn, s1, s1_len);
	ft_memcpy(rtrn + s1_len, s2, s2_len);
	rtrn[size - 1] = '\0';
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (rtrn);
}

char	*ft_strchr(char *s, int c)
{
	char	*s2;
	char	c2;

	s2 = s;
	c2 = c;
	while (*s2)
	{
		if (*s2 == c2)
			return (s2);
		s2++;
	}
	return (NULL);
}
