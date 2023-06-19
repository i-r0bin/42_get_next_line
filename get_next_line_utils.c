/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:17:29 by rilliano          #+#    #+#             */
/*   Updated: 2023/05/05 17:12:31 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	tot;
	size_t	i;

	tot = size * count;
	if (size != 0 && tot / size != count)
		return (0);
	else if (count != 0 && tot / count != size)
		return (0);
	arr = (void *)malloc(tot);
	if (!arr)
		return (0);
	i = 0;
	while (i < tot)
	{
		*(char *)(arr + i) = 0;
		i++;
	}
	return (arr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_join(char *s1, char *s2, int len)
{
	char	*jo;
	int		s1len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	jo = ft_calloc(s1len + len + 1, sizeof(char));
	ft_memcpy(jo, s1, s1len);
	ft_memcpy((jo + s1len), s2, len);
	free(s1);
	return (jo);
}
