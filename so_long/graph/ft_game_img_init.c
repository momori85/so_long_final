/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_img_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:51 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 17:40:20 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static int	ft_init_wall_one(t_map *map, int len)
{
	map->img_wall->top_right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_right.xpm", &len, &len);
	if (map->img_wall->top_right == 0)
		return (0);
	map->img_wall->solo_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_down.xpm", &len, &len);
	if (map->img_wall->solo_down == 0)
		return (0);
	map->img_wall->solo_top = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_top.xpm", &len, &len);
	if (map->img_wall->solo_top == 0)
		return (0);
	map->img_wall->top_left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_left.xpm", &len, &len);
	if (map->img_wall->top_left == 0)
		return (0);
	map->img_wall->top_midle = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_midle.xpm", &len, &len);
	if (map->img_wall->top_midle == 0)
		return (0);
	if (ft_init_wall_two(map, len) == 0)
		return (0);
	return (1);
}

static int	ft_init_wall(t_map *map, int len)
{
	map->img_wall->front_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/front_down.xpm", &len, &len);
	if (map->img_wall->front_down == 0)
		return (0);
	map->img_wall->left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/left.xpm", &len, &len);
	if (map->img_wall->left == 0)
		return (0);
	map->img_wall->left_and_right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/left_and_right.xpm", &len, &len);
	if (map->img_wall->left_and_right == 0)
		return (0);
	map->img_wall->left_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/left_down.xpm", &len, &len);
	if (map->img_wall->left_down == 0)
		return (0);
	map->img_wall->midle = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/midle.xpm", &len, &len);
	if (map->img_wall->midle == 0)
		return (0);
	if (ft_init_wall_three(map, len) == 0)
		return (0);
	return (1);
}

static int	ft_init_img_screen(t_map *map, int len)
{
	map->img->img_left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/left_game.xpm", &len, &len);
	if (map->img->img_left == 0)
		return (0);
	map->img->img_settings = mlx_xpm_file_to_image(
			map->game->mlx, ".img/settings_screen.xpm", &len, &len);
	if (map->img->img_settings == 0)
		return (0);
	map->img->img_game = mlx_xpm_file_to_image(
			map->game->mlx, ".img/start_screen.xpm", &len, &len);
	if (map->img->img_game == 0)
		return (0);
	map->img->img_game_save = mlx_xpm_file_to_image(
			map->game->mlx, ".img/save_screen.xpm", &len, &len);
	if (map->img->img_game_save == 0)
		return (0);
	map->img->img_480 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/480p.xpm", &len, &len);
	if (map->img->img_480 == 0)
		return (0);
	if (ft_init_img_screen_two(map, len) == 0)
		return (0);
	return (1);
}

static int	ft_init_player(t_map *map, int len)
{
	map->player->player_frame_1 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_1.xpm", &len, &len);
	if (map->player->player_frame_1 == 0)
		return (0);
	map->player->player_frame_2 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_2.xpm", &len, &len);
	if (map->player->player_frame_2 == 0)
		return (0);
	map->player->player_frame_3 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_3.xpm", &len, &len);
	if (map->player->player_frame_3 == 0)
		return (0);
	map->player->player_frame_4 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_4.xpm", &len, &len);
	if (map->player->player_frame_4 == 0)
		return (0);
	map->player->player_frame_5 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player/player_frame_5.xpm", &len, &len);
	if (map->player->player_frame_5 == 0)
		return (0);
	if (ft_init_player_two(map, len) == 0)
		return (0);
	return (1);
}

int	ft_init_img(t_map *map)
{
	int		len;

	len = 64;
	map->img->img_c = mlx_xpm_file_to_image(
			map->game->mlx, ".img/c.xpm", &len, &len);
	if (map->img->img_c == 0)
		return (0);
	if (ft_init_img_path(map, len) == 0)
		return (0);
	if (ft_init_wall_one(map, len) == 0)
		return (0);
	if (ft_init_wall(map, len) == 0)
		return (0);
	if (ft_init_img_screen(map, len) == 0)
		return (0);
	if (ft_init_player(map, len) == 0)
		return (0);
	if (ft_init_img_screen_three(map, len) == 0)
		return (0);
	if (ft_init_img_two(map, len) == 0)
		return (0);
	return (1);
}
