/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:03:58 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/29 13:04:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (size)
	{
		while (*src && i < size)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (ft_strlen(src) + i);
}

static char	*ft_rest(char *line, char **buf, int fd)
{
	int			len;

	if (ft_strlen(buf[fd]) > 0)
	{
		len = ft_strchr_gnl(buf[fd], '\n');
		if (len > 0)
		{
			line = ft_strjoin_gnl(line, buf[fd], len);
			ft_strlcpy_gnl(buf[fd], &buf[fd][len], BUFFER_SIZE - len + 1);
			return (line);
		}
		else
		{
			line = ft_strjoin_gnl(line, buf[fd], BUFFER_SIZE);
			ft_memset(buf[fd], 0, BUFFER_SIZE);
		}
	}
	return (line);
}

static char	*ft_line(char **buf, char *line, int fd)
{
	int	bytesread;
	int	len;

	bytesread = read(fd, buf[fd], BUFFER_SIZE);
	while (bytesread > 0)
	{
		buf[fd][bytesread] = '\0';
		len = ft_strchr_gnl(buf[fd], '\n');
		if (len >= 0)
		{
			line = ft_strjoin_gnl(line, buf[fd], len);
			ft_strlcpy_gnl(buf[fd], &buf[fd][len], BUFFER_SIZE - len + 1);
			return (line);
		}
		else
		{
			line = ft_strjoin_gnl(line, buf[fd], BUFFER_SIZE);
			ft_memset(buf[fd], 0, BUFFER_SIZE);
		}
		bytesread = read(fd, buf[fd], BUFFER_SIZE);
	}
	line = ft_invalid(line, bytesread);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buf[1024];
	char			*line;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf[fd])
			return (NULL);
		buf[fd] = ft_memset(buf[fd], 0, BUFFER_SIZE + 1);
	}
	line = malloc(sizeof(char) * 1);
	if (line == 0)
		return (NULL);
	line = ft_memset(line, 0, 1);
	line = ft_rest(line, buf, fd);
	if (ft_strchr_gnl(line, '\n') >= 0)
		return (line);
	line = ft_line(buf, line, fd);
	if (ft_strchr_gnl(line, '\n') >= 0 || ft_strlen(line) > 0)
		return (line);
	free_buffer(buf, fd);
	free(line);
	return (NULL);
}
