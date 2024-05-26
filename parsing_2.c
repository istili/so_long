/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:27:42 by istili            #+#    #+#             */
/*   Updated: 2024/05/19 20:00:04 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_one(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] && s[i] == '1')
		i++;
	if (s[i] && s[i] != '1')
		return (0);
	return (1);
}

static int	check_map_helper(t_map *map, int size, int i, t_node *node)
{
	map->size.x = size;
	map->size.y = i + 1;
	if (!is_one(node->data) || size != ft_len(node->data))
		return (0);
	if (map->collectible == 0 || map->exit.x == -1 || map->exit.y == -1)
		return (0);
	map->map2d = lst_to_array(map->content);
	if (!map->map2d)
		puterr(MALLOC_ERR);
	flood_fill(map->map2d, map->size, map->start);
	i = -1;
	while (map->map2d[++i])
		if (ft_strchr(map->map2d[i], 'C') || ft_strchr(map->map2d[i], 'E'))
			return (0);
	free_arr(map->map2d);
	return (1);
}

int	check_map(t_map *map)
{
	t_node	*node;
	int		i;
	int		size;

	if (map->content == NULL)
		return (0);
	node = map->content;
	size = ft_len(node->data);
	i = 1;
	if (!is_one(node->data))
		return (0);
	node = node->next;
	while (node->next)
	{
		check_line(map, node->data, size);
		if (map->exit.x != -1 && map->exit.y == -1)
			map->exit.y = i;
		if (map->start.x != -1 && map->start.y == -1)
			map->start.y = i;
		node = node->next;
		i++;
	}
	return (check_map_helper(map, size, i, node));
}
