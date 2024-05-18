/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:25:57 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 18:24:54 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window(t_long *data)
{
	mlx_put_image_to_window(data->mlx.p, data->mlx.win, data->textures.player,
		data->player.x * BRICK_SIZE, data->player.y * BRICK_SIZE);
}

static int	is_valid(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

static void	flood_fill_helper(char **map2d, t_point size, t_point begin,
	t_point p)
{
	if (begin.x > 0 && is_valid(map2d[begin.y][begin.x - 1]))
	{
		p.y = begin.y;
		p.x = begin.x - 1;
		flood_fill(map2d, size, p);
	}
	if (begin.x < (size.x - 1) && is_valid(map2d[begin.y][begin.x + 1]))
	{
		p.y = begin.y;
		p.x = begin.x + 1;
		flood_fill(map2d, size, p);
	}
}

void	flood_fill(char **map2d, t_point size, t_point begin)
{
	t_point	p;

	if (begin.x < 0 || begin.x >= size.x - 1
		|| begin.y < 0 || begin.y >= size.y - 1)
		return ;
	map2d[begin.y][begin.x] = 'k';
	if (begin.y > 0 && is_valid(map2d[begin.y - 1][begin.x]))
	{
		p.y = begin.y - 1;
		p.x = begin.x;
		flood_fill(map2d, size, p);
	}
	if (begin.y < (size.y - 1) && is_valid(map2d[begin.y + 1][begin.x]))
	{
		p.y = begin.y + 1;
		p.x = begin.x;
		flood_fill(map2d, size, p);
	}
	flood_fill_helper(map2d, size, begin, p);
}
