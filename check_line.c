/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:44:09 by istili            #+#    #+#             */
/*   Updated: 2024/05/19 15:35:40 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		return (0);
	return (1);
}

void	check_line(t_map *map, char *line, int size)
{
	static int	e;
	static int	p;
	int			i;

	i = 0;
	if (size != ft_len(line))
		puterr(RECTANGULAR_ERR);
	if (line[size - 1] != '1' || line[0] != '1')
		puterr(WALL_ERR);
	while (line[++i])
	{
		if (!is_valid_char(line[i]))
			puterr(MAP_ERR);
		if (line[i] == 'C')
			map->collectible++;
		if (line[i] == 'E' && e == 0 && ++e)
			map->exit.x = i;
		else if (line[i] == 'E' && e != 0)
			puterr(EXIT_ERR);
		if (line[i] == 'P' && p == 0 && ++p)
			map->start.x = i;
		else if (line[i] == 'P' && p != 0)
			puterr(PLAYER_ERR);
	}
}
