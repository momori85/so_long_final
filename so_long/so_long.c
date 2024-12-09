/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:46:01 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/07 23:11:54 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_tabdup(t_map *map)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof (char *) * (map->map_y + 1));
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

char	**ft_so_long(t_map *map, char *name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
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
	fd = open(name, O_RDONLY);
	map->map[i] = get_next_line(fd);
	while (map->map[i++] != NULL)
		map->map[i] = get_next_line(fd);
	close(fd);
	return (map->map);
}

int	ft_verif_name(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	str = "reb.";
	if (argc != 2)
		return (ft_printf("error, argument not good\n"));
	i = 0;
	while (argv[1][i])
		i++;
	if (i < 4)
		return (ft_printf("error, map name is not .ber\n"));
	j = 0;
	i--;
	while (str[j])
		if (str[j++] != argv[1][i--])
			return (ft_printf("error, map name is not .ber\n"));
	return (1);
}

void	ft_error_exit(char **map, char **str, t_map *data_map, char *error)
{
	if (!map)
		free_map(data_map->map, data_map);
	if (!str)
		free_map(str, data_map);
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	**str;
	t_map	map;
	t_verif	count;

	if (ft_verif_name(argc, argv) != 1)
		return (0);
	map.map = ft_so_long(&map, argv[1]);
	if (map.map == 0)
		return (ft_printf("error, map name not good\n"));
	if (ft_verif_map(&map, &count) == 0)
		ft_error_exit(map.map, NULL, &map, "error, map invalid\n");
	str = ft_tabdup(&map);
	if (ft_init_bfs(&map, &count, str) == 0 || str == NULL)
		ft_error_exit(map.map, str, &map, "error, no path\n");
	ft_graph(&map);
	free_map(map.map, &map);
	free_map(str, &map);
}
