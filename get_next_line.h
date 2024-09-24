/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:14:16 by bcanals-          #+#    #+#             */
/*   Updated: 2024/09/24 18:31:22 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);

#endif
