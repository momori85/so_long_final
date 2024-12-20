/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:52 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 17:40:26 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

int	ft_init_img_path(t_map *map, int len)
{
	map->img->img_path = mlx_xpm_file_to_image(
			map->game->mlx, ".img/path/full.xpm", &len, &len);
	if (map->img->img_path == 0)
		return (0);
	map->img->img_mini_path = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_path.xpm", &len, &len);
	if (map->img->img_mini_path == 0)
		return (0);
	map->img->img_mini_bot = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_bot.xpm", &len, &len);
	if (map->img->img_mini_bot == 0)
		return (0);
	map->img->img_mini_wall = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_wall.xpm", &len, &len);
	if (map->img->img_mini_wall == 0)
		return (0);
	map->img->img_mini_player = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_player.xpm", &len, &len);
	if (map->img->img_mini_player == 0)
		return (0);
	map->img->img_save = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/save.xpm", &len, &len);
	if (map->img->img_save == 0)
		return (0);
	return (1);
}

void	ft_game_status_exit(t_map *map)
{
	if (map->start_y == map->bfs->next_y
		&& map->start_x == map->bfs->next_x && map->count_c <= 0)
	{
		if (map->save->file == 1)
		{
			map->fd = open("save_one.txt", O_CREAT | O_RDWR
					| O_TRUNC, 0644);
			close(map->fd);
		}
		if (map->save->file == 2)
		{
			map->fd = open("save_two.txt", O_CREAT | O_RDWR
					| O_TRUNC, 0644);
			close(map->fd);
		}
		if (map->save->file == 3)
		{
			map->fd = open("save_three.txt", O_CREAT | O_RDWR
					| O_TRUNC, 0644);
			close(map->fd);
		}
		mlx_loop_end(map->game->mlx);
	}
}

int	ft_init_player_two(t_map *map, int len)
{
	map->player->player_frame_6 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_6.xpm", &len, &len);
	if (map->player->player_frame_6 == 0)
		return (0);
	map->player->player_frame_7 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_7.xpm", &len, &len);
	if (map->player->player_frame_7 == 0)
		return (0);
	map->player->player_frame_8 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_8.xpm", &len, &len);
	if (map->player->player_frame_8 == 0)
		return (0);
	map->player->player_frame_9 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_9.xpm", &len, &len);
	if (map->player->player_frame_9 == 0)
		return (0);
	map->player->player_frame_10 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_10.xpm", &len, &len);
	if (map->player->player_frame_10 == 0)
		return (0);
	map->player->player_frame_11 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_11.xpm", &len, &len);
	if (map->player->player_frame_11 == 0)
		return (0);
	return (1);
}

int	ft_init_img_two(t_map *map, int len)
{
	map->img->fog = mlx_xpm_file_to_image(
			map->game->mlx, ".img/fog.xpm", &len, &len);
	if (map->img->fog == 0)
		return (0);
	map->img->fog_two = mlx_xpm_file_to_image(
			map->game->mlx, ".img/fog_two.xpm", &len, &len);
	if (map->img->fog_two == 0)
		return (0);
	map->img->fog_tree = mlx_xpm_file_to_image(
			map->game->mlx, ".img/fog_tree.xpm", &len, &len);
	if (map->img->fog_tree == 0)
		return (0);
	map->img->died = mlx_xpm_file_to_image(
			map->game->mlx, ".img/died.xpm", &len, &len);
	if (map->img->died == 0)
		return (0);
	map->img->gold_count = mlx_xpm_file_to_image(
			map->game->mlx, ".img/gold_count.xpm", &len, &len);
	if (map->img->gold_count == 0)
		return (0);
	map->img->img_player = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player.xpm", &len, &len);
	if (map->img->img_player == 0)
		return (0);
	return (1);
}
