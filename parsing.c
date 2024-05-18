/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:26:00 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 20:05:17 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	check_extension(char *s)
{
	int	size;

	size = ft_len(s);
	if (size >= 4 && !ft_strcmp(&s[size - 4], ".ber"))
		return (1);
	return (0);
}

static t_map	*create_map(t_map *map, t_node *raw_map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		puterr(MALLOC_ERR);
	map->collectible = 0;
	map->start.x = -1;
	map->start.y = -1;
	map->exit.x = -1;
	map->exit.y = -1;
	map->content = raw_map;
	if (!check_map(map))
		puterr(MAP_ERR);
	return (map);
}

t_map	*ft_parsing(int ac, char **av)
{
	int		fd;
	char	*line;
	t_node	*raw_map;
	t_map	*map;

	map = NULL;
	if (ac != 2)
		puterr(ARG_ERR);
	if (!check_extension(av[1]))
		puterr(EXTENSION_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		puterr(OPEN_ERR);
	line = get_next_line(fd);
	raw_map = NULL;
	while (line)
	{
		add_node(&raw_map, remove_new_line(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = create_map(map, raw_map);
	return (map);
}
