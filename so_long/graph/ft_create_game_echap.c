/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game_echap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:43:51 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/15 22:20:09 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_create_save(t_map *map)
{
	int	i;
	char *tmp;

	i = 0;
	while (map->map[i])
	{
		write(map->fd, map->map[i], ft_strlen(map->map[i] + 1));
		write(map->fd, "\n", 1);
		i++;
	}
	write(map->fd, "******************************\n", 31);
	tmp = ft_itoa(map->start_x);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : player_x\n", 12);
	tmp = ft_itoa(map->start_y);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : player_y\n", 12);
	tmp = ft_itoa(map->bot->bot1_x);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : bot one x\n", 13);
	tmp = ft_itoa(map->bot->bot1_y);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : bot one y\n", 13);
	tmp = ft_itoa(map->bot->bot2_x);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : bot two x\n", 13);
	tmp = ft_itoa(map->bot->bot2_y);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : bot two y\n", 13);
	tmp = ft_itoa(map->bot->bot3_x);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : bot tree x\n", 14);
	tmp = ft_itoa(map->bot->bot3_y);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : bot tree y\n", 14);
	tmp = ft_itoa(map->path);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : path\n", 8);
	tmp = ft_itoa(map->count->vision);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : vision\n", 10);
	write(map->fd, "******************************\n", 31);
}



void	ft_create_game_echap(int keycode, t_map *map)
{
	char buf[1];
	int bytesread;

	if (map->game_status == 4)
	{
		if (keycode == 65307 && map->i == 1)
			mlx_loop_end(map->game->mlx);
		if (map->i == 0)
			map->i = 1;
		if (keycode == 115 && map->i < 3)
		{
			map->i++;
			if (map->i == 2)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_save_exit, 0, 0);
			if (map->i == 3)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_resume, 0, 0);
		}
		if (keycode == 119 && map->i > 1)
		{
			map->i--;
			if (map->i == 2)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_save_exit, 0, 0);
			if (map->i == 1)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_save, 0, 0);
		}
		if (keycode == 65293)
		{
			if (map->i == 2)
				mlx_loop_end(map->game->mlx);
			if (map->i == 3)
			{
				map->game_status = 1;
				mlx_clear_window(map->game->mlx, map->game->window);
				mlx_destroy_window(map->game->mlx, map->game->window);
				map->game->window = mlx_new_window(map->game->mlx,
					map->screen_x, map->screen_y, "so_long");
				mlx_key_hook(map->game->window, move, map);
				mlx_hook(map->game->window, 17, 0, ft_close, map);
				ft_create_map_init(map, 0, 0);
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->fog, map->screen_x / 2 - (32 * 3 + 16),
					map->screen_y / 2 - (32 * 3 + 16));
			}
			if (map->i == 1)
			{
				map->fd = open("save_one.txt", O_CREAT | O_RDWR, 0644);
				bytesread = read(map->fd, buf, 1);
				if (bytesread == 0)
					ft_create_save(map);
				else
				{
					map->fd = open("save_two.txt", O_CREAT | O_RDWR, 0644);
					bytesread = read(map->fd, buf, 1);
					if (bytesread == 0)
						ft_create_save(map);
					else
					{
						map->fd = open("save_tree.txt", O_CREAT | O_RDWR, 0644);
						bytesread = read(map->fd, buf, 1);
						if (bytesread == 0)
							ft_create_save(map);
					}
				}
				if (map->fd != -1)
					close(map->fd);
			}
		}
	}
}
