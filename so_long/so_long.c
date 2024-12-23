/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:46:01 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 13:43:58 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_tabdup(t_map *map)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof (char *) * (map->map_y + 2));
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
	str[map->map_y + 1] = 0;
	return (str);
}

char	**ft_so_long(char *name)
{
	int		fd;
	int		i;
	char	*str;
	char	**tmp;

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
	if (i == 0)
		return (NULL);
	tmp = malloc(sizeof(char *) * (i + 1));
	fd = open(name, O_RDONLY);
	tmp = ft_so_long_map_create(tmp, fd);
	close(fd);
	return (tmp);
}

static int	ft_verif_name(int argc, char **argv)
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

static void	ft_error_exit(char **map, char **str, t_map *data_map, char *error)
{
	if (map)
		free_map(data_map->map);
	if (str)
		free_map(str);
	ft_printf("%s", error);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	**str;
	t_map	map;
	t_verif	count;

	if (ft_verif_name(argc, argv) != 1)
		return (0);
	map.map = ft_so_long(argv[1]);
	if (map.map == 0)
		return (ft_printf("error, map name not good\n"));
	if (ft_verif_map(&map, &count) == 0 || ft_verif_len(map.map) == 0)
		ft_error_exit(map.map, NULL, &map, "error, map invalid\n");
	str = ft_tabdup(&map);
	if (ft_init_bfs(&map, &count, str) == 0 || str == NULL)
		ft_error_exit(map.map, str, &map, "error, no path\n");
	map.mini_map = ft_tabdup(&map);
	ft_create_mini_map_empty(&map);
	ft_graph(&map);
	free_map(str);
	free_map(map.mini_map);
	if (map.save->verif == 0)
		free_map(map.map);
	if (map.save->save_map)
		free_map(map.save->save_map);
	ft_clear_graph(&map);
}
