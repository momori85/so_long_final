/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_img_init_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:31:07 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 17:38:31 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

int	ft_init_wall_two(t_map *map, int len)
{
	map->img_wall->top_and_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_and_down.xpm", &len, &len);
	if (map->img_wall->top_and_down == 0)
		return (0);
	map->img_wall->solo_left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_left.xpm", &len, &len);
	if (map->img_wall->solo_left == 0)
		return (0);
	map->img_wall->solo_right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_right.xpm", &len, &len);
	if (map->img_wall->solo_right == 0)
		return (0);
	map->img_wall->water_one = mlx_xpm_file_to_image(
			map->game->mlx, ".img/water/water_one.xpm", &len, &len);
	if (map->img_wall->water_one == 0)
		return (0);
	map->img_wall->water_two = mlx_xpm_file_to_image(
			map->game->mlx, ".img/water/water_two.xpm", &len, &len);
	if (map->img_wall->water_two == 0)
		return (0);
	map->img_wall->water_tree = mlx_xpm_file_to_image(
			map->game->mlx, ".img/water/water_tree.xpm", &len, &len);
	if (map->img_wall->water_tree == 0)
		return (0);
	return (1);
}

int	ft_init_wall_three(t_map *map, int len)
{
	map->img_wall->midle_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/midle_down.xpm", &len, &len);
	if (map->img_wall->midle_down == 0)
		return (0);
	map->img_wall->right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/right.xpm", &len, &len);
	if (map->img_wall->right == 0)
		return (0);
	map->img_wall->right_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/right_down.xpm", &len, &len);
	if (map->img_wall->right_down == 0)
		return (0);
	map->img_wall->solo = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo.xpm", &len, &len);
	if (map->img_wall->solo == 0)
		return (0);
	map->img->empty = mlx_xpm_file_to_image(
			map->game->mlx, ".img/empty.xpm", &len, &len);
	if (map->img->empty == 0)
		return (0);
	map->img->full = mlx_xpm_file_to_image(
			map->game->mlx, ".img/full.xpm", &len, &len);
	if (map->img->full == 0)
		return (0);
	return (1);
}

int	ft_init_img_screen_two(t_map *map, int len)
{
	map->img->img_720 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/720p.xpm", &len, &len);
	if (map->img->img_720 == 0)
		return (0);
	map->img->img_1080 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/1080p.xpm", &len, &len);
	if (map->img->img_1080 == 0)
		return (0);
	map->img->img_exit_settings = mlx_xpm_file_to_image(
			map->game->mlx, ".img/settings_exit.xpm", &len, &len);
	if (map->img->img_exit_settings == 0)
		return (0);
	map->img->img_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/exit.xpm", &len, &len);
	if (map->img->img_exit == 0)
		return (0);
	map->img->save_one = mlx_xpm_file_to_image(
			map->game->mlx, ".img/save_one.xpm", &len, &len);
	if (map->img->save_one == 0)
		return (0);
	map->img->save_two = mlx_xpm_file_to_image(
			map->game->mlx, ".img/save_two.xpm", &len, &len);
	if (map->img->save_two == 0)
		return (0);
	return (1);
}

int	ft_init_img_screen_three(t_map *map, int len)
{
	map->img->save_tree = mlx_xpm_file_to_image(
			map->game->mlx, ".img/save_tree.xpm", &len, &len);
	if (map->img->save_tree == 0)
		return (0);
	map->img->save_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/save_exit.xpm", &len, &len);
	if (map->img->save_exit == 0)
		return (0);
	map->player->player_frame_12 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_12.xpm", &len, &len);
	if (map->player->player_frame_12 == 0)
		return (0);
	map->img->img_save_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/save_exit.xpm", &len, &len);
	if (map->img->img_save_exit == 0)
		return (0);
	map->img->img_resume = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/resume.xpm", &len, &len);
	if (map->img->img_resume == 0)
		return (0);
	map->img->bot = mlx_xpm_file_to_image(
			map->game->mlx, ".img/goblin.xpm", &len, &len);
	if (map->img->bot == 0)
		return (0);
	return (1);
}
