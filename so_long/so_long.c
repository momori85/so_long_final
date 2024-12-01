/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:46:01 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/01 10:58:33 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_tabdup(t_map *map)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof (char *) * ( map->map_y + 1));
	if (str == NULL)
		return (NULL);
	while (map->map[i])
	{
		str[i] = ft_strdup(map->map[i]);
		if (str[i] == NULL)
		{
			while (i > 0)
				free(str[--i]);
			free(str);
			return (NULL);
		}
		i++;
	}
	return (str);
}

char	**ft_so_long(t_map *map)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open("so_long.ber", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	free(str);
	map->map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	fd = open("so_long.ber", O_RDONLY);
	map->map[i] = get_next_line(fd);
	while (map->map[i++] != NULL)
		map->map[i] = get_next_line(fd);
	close(fd);
	return (map->map);
}

int	main(void)
{
	int		i;
	char **str;
	t_map	map;
	t_verif	count;
	int test;

	i = 1;
	map.map = ft_so_long(&map);
	if (ft_verif_map(&map, &count) == 0)
	{
		ft_printf("error!");
		free_map(map.map, &map);
		return (0);
	}
	str = ft_tabdup(&map);
	if (ft_init_bfs(&map, &count, str) == 0 || str == NULL)
	{
		ft_printf("error! no path");
		free_map(map.map, &map);
		free_map(str, &map);
		return (0);
	}
	while (i != 0 && i != -1 && i != 2)
	{
		i = ft_init_game_sreen();
		if (i == 1)
			i = ft_init_settings_sreen();
	}
	printf("[[%d]]", i);
	if (i == 0)
		ft_graph(&map, &count);
	i = 0;
	while (i <= map.map_y)
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	free_map(map.map, &map);
	free_map(str, &map);
}
