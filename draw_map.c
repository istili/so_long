/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:30:31 by istili            #+#    #+#             */
/*   Updated: 2024/05/19 20:37:05 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_door(t_long *data, char c)
{
	if (c == 'E' && data->nb_collectibles == data->map->collectible)
		return (1);
	return (0);
}

static void	draw_map_check(t_long *data)
{
	if (check_door(data, data->map->map2d[data->player.y][data->player.x]))
		close_window(data);
}

static void	*draw_map_helper(t_long *data, int i, int j)
{
	if (data->map->map2d[i][j] == '1')
		return (data->textures.wall);
	else if (data->map->map2d[i][j] == 'C')
		return (data->textures.collect);
	else if (data->map->map2d[i][j] == 'E')
		return (data->textures.exit);
	else
		return (data->textures.road);
}

static void	init_vals(t_point *starting_pixel, int *i, int *j)
{
	*i = 0;
	*j = 0;
	starting_pixel->x = 0;
	starting_pixel->y = 0;
}

int	draw_map(t_long *data)
{
	int		i;
	int		j;
	t_point	starting_pixel;

	mlx_clear_window(data->game.p, data->game.win);
	init_vals(&starting_pixel, &i, &j);
	while (i < data->map->size.y)
	{
		j = 0;
		starting_pixel.x = 0;
		while (j < data->map->size.x)
		{
			mlx_put_image_to_window(data->game.p, data->game.win,
				draw_map_helper(data, i, j),
				starting_pixel.x, starting_pixel.y);
			j++;
			starting_pixel.x += BRICK_SIZE;
		}
		i++;
		starting_pixel.y += BRICK_SIZE;
	}
	player_image_to_window(data);
	score(data);
	draw_map_check(data);
	return (1);
}
