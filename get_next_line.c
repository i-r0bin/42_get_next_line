/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:47:15 by rilliano          #+#    #+#             */
/*   Updated: 2023/05/09 17:14:28 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *prev, int len)
{
	char	*n_line;
	int		i;

	if (!prev[len - 1])
	{
		free(prev);
		return (NULL);
	}
	n_line = ft_calloc((ft_strlen(prev) - len + 1), sizeof(char));
	i = 0;
	while (prev[len + i])
	{
		n_line[i] = prev[len + i];
		i++;
	}
	free(prev);
	return (n_line);
}

char	*ft_line(char *start, int len)
{
	char	*line;
	int		i;

	line = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (i < len)
	{
		line[i] = start[i];
		i++;
	}
	return (line);
}

char	*read_file(int fd, char *start)
{
	char	*buffer;
	int		bytes;

	if (!start)
		start = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		start = ft_join(start, buffer, bytes);
		if (buffer[bytes - 1] == '\n')
			break;
	}
	free(buffer);
	return (start);
}

char	*get_next_line(int fd)
{
	static char	*start;
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	start = read_file(fd, start);
	len = 0;
	if (!start || !start[len])
		return (NULL);
	while (start[len] != '\0' && start[len] != '\n')
		len++;
	len += (start[len] == '\n');
	line = ft_line(start, len);
	start = ft_next(start, len);
	return (line);
}
