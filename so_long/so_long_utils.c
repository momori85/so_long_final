/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:39:01 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 13:49:01 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **ptr)
{
	char	**head;

	head = ptr;
	while (head && *head)
		free(*head++);
	if (ptr)
		free(ptr);
}

char	**ft_so_long_map_create(char **tmp, int fd)
{
	int	i;

	i = 0;
	tmp[i] = get_next_line(fd);
	while (tmp[i++] != NULL)
		tmp[i] = get_next_line(fd);
	return (tmp);
}

void	ft_save(t_map *map)
{
	int		bytesread;
	int		fd;
	char	buf[10];

	map->save->file_one = 0;
	map->save->file_two = 0;
	map->save->file_three = 0;
	fd = open("save_one.txt", O_CREAT | O_RDWR, 0644);
	bytesread = read(fd, buf, 10);
	if (bytesread > 5)
		map->save->file_one = 1;
	close(fd);
	fd = open("save_two.txt", O_CREAT | O_RDWR, 0644);
	bytesread = read(fd, buf, 10);
	if (bytesread > 5)
		map->save->file_two = 1;
	close(fd);
	fd = open("save_three.txt", O_CREAT | O_RDWR, 0644);
	bytesread = read(fd, buf, 10);
	if (bytesread > 5)
		map->save->file_three = 1;
	close(fd);
}

void	ft_create_mini_map_empty(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->mini_map[i])
	{
		while (map->mini_map[i][j])
		{
			map->mini_map[i][j] = '*';
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_verif_len(char **str)
{
	int		i;
	size_t	tmp;

	i = 0;
	tmp = ft_strlen(str[0]);
	while (str[i])
	{
		if (tmp != ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}
