/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game_echap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:43:51 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 13:41:50 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_create_save_variable_two(t_map *map, char *tmp)
{
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
}

static void	ft_create_save_variable(t_map *map, char *tmp)
{
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
	tmp = ft_itoa(map->len);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : map_x\n", 9);
	tmp = ft_itoa(map->map_y);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : map_y\n", 9);
}

void	ft_create_save(t_map *map)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (map->map[i])
	{
		write(map->fd, map->map[i], ft_strlen(map->map[i]));
		write(map->fd, "\n", 1);
		i++;
	}
	ft_create_save_variable_two(map, tmp);
	ft_create_save_variable(map, tmp);
	tmp = ft_itoa(map->count_c);
	write(map->fd, tmp, ft_strlen(tmp));
	free(tmp);
	write(map->fd, " : count_c\n", 11);
	write(map->fd, "******************************\n", 31);
}

static void	ft_create_img_echap(t_map *map)
{
	if (map->i == 2)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_save_exit, 0, 0);
	if (map->i == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_save, 0, 0);
	if (map->i == 3)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_resume, 0, 0);
}

void	ft_create_game_echap(int keycode, t_map *map)
{
	if (map->game_status == 4)
	{
		if (keycode == 65307 && map->i == 1)
			mlx_loop_end(map->game->mlx);
		if (map->i == 0)
			map->i = 1;
		if (keycode == 115 && map->i < 3)
		{
			map->i++;
			ft_create_img_echap(map);
		}
		if (keycode == 119 && map->i > 1)
		{
			map->i--;
			ft_create_img_echap(map);
		}
		if (keycode == 65293)
		{
			if (map->i == 2)
				mlx_loop_end(map->game->mlx);
			ft_echap_resume(map);
			ft_read_create_save(map);
		}
	}
}
