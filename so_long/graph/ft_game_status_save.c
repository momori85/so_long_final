
#include "ft_graph.h"

void	ft_init_save(t_map *map, char *name)
{
		int i;

		i = 0;
		map->save->len = 0;
		map->save->save = ft_so_long(name);
		if (map->save->save != NULL)
		{
			while(map->save->save[i][0] != '*')
				i++;
			map->save->save_map = ft_calloc(i + 1, sizeof(char *));
			while (map->save->len < i)
			{
				map->save->save_map[map->save->len] = ft_strdup(map->save->save[map->save->len]);
				map->save->len++;
			}
			map->save->len++;
		}
}

void    ft_game_status_save_move(int keycode, t_map *map)
{
	if (keycode == 119 && map->i > 1)
	{
		map->i--;
		if (map->i == 1)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->save_one, 0, 0);
		if (map->i == 2)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->save_two, 0, 0);
		if (map->i == 3)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->save_tree, 0, 0);
	}
	if (keycode == 115 && map->i < 4)
	{
		map->i++;
		if (map->i == 2)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->save_two, 0, 0);
		if (map->i == 3)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->save_tree, 0, 0);
		if (map->i == 4)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->save_exit, 0, 0);
	}
}

static void	ft_game_menu_save_move(t_map *map)
{
	if (map->i == 1)
	{
		ft_init_save(map, "save_one.txt");
		map->start_x = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->start_y = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->bot->bot1_x = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->bot->bot1_y = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->bot->bot2_x = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->bot->bot2_y = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->bot->bot3_x = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->bot->bot3_y = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->path = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->count->vision = ft_atoi(map->save->save[map->save->len]);
		map->save->len++;
		map->save->file = 1;
	}
	if (map->i == 2)
	{
		;
	}
	if (map->i == 3)
	{
		;
	}
	if (map->i == 4)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->img_game, 0, 0);
		map->game_status = 0;
		map->i = -1;
	}
}

void    ft_game_status_save(int keycode, t_map *map)
{
	if (map->game_status == 6)
	{
		ft_game_status_save_move(keycode, map);
		if (keycode == 65307)
			mlx_loop_end(map->game->mlx);
		if (keycode == 65293 && (map->i == 1 || map->i == 2 || map->i == 3 || map->i == 4))
			ft_game_menu_save_move(map);
		if (map->i == -1)
			map->i = 1;
	}
}