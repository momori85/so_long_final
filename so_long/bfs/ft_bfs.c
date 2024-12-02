/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:19:45 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/15 13:19:47 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_empty(t_bfs *buf)
{
	return (buf->front == buf->last);
}

int	ft_verif_bfs(char **str, int next_x, int next_y)
{
	return (str[next_y][next_x] != '1' && str[next_y][next_x] != '*');
}

void	ft_bfs_move(t_bfs *buf, t_map *map, char **str)
{
	int			move;
	const int	direction[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
	};

	move = 0;
	while (move < 4)
	{
		buf->next_x = buf->recur_x + direction[move][0];
		buf->next_y = buf->recur_y + direction[move][1];
		if (ft_verif_bfs(str, buf->next_x, buf->next_y))
		{
			if (map->map[buf->next_y][buf->next_x] == 'C')
				buf->count_bfs_c++;
			if (map->map[buf->next_y][buf->next_x] == 'E')
				buf->count_bfs_e++;
			str[buf->next_y][buf->next_x] = '*';
			ft_start_buf(buf, buf->next_y * map->len + buf->next_x);
		}
		move++;
	}
}

int	ft_bfs(t_map *map, t_verif *count, char **str)
{
	t_bfs	buf;

	buf.count_bfs_c = 0;
	buf.count_bfs_e = 0;
	ft_init_buf(&buf, map->len * map->map_y);
	ft_start_buf(&buf, map->start_y * map->len + map->start_x);
	str[map->start_y][map->start_x] = '*';
	while (!ft_empty(&buf))
	{
		buf.recur = ft_end_buf(&buf);
		buf.recur_x = buf.recur % map->len;
		buf.recur_y = buf.recur / map->len;
		if (buf.count_bfs_e == 1 && buf.count_bfs_c == count->count_c)
		{
			free(buf.tab);
			return (1);
		}
		ft_bfs_move(&buf, map, str);
	}
	free(buf.tab);
	return (0);
}

int	ft_init_bfs(t_map *map, t_verif *count, char **str)
{
	if (ft_bfs(map, count, str) == 0)
		return (0);
	return (1);
}
