/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:09 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 18:14:18 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	s_key(void *ptr)
{
	t_long	*data;

	data = ptr;
	if (data->map->map2d[data->player.y + 1][data->player.x] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.y += 1;
		data->moves++;
	}
	return (1);
}

static int	d_key(t_long *ptr)
{
	t_long	*data;

	data = ptr;
	if (data->map->map2d[data->player.y][data->player.x + 1] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.x += 1;
		data->moves++;
	}
	return (1);
}

static int	w_key(void *ptr)
{
	t_long	*data;

	data = ptr;
	if (data->map->map2d[data->player.y - 1][data->player.x] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.y -= 1;
		data->moves++;
	}
	return (1);
}

static int	a_key(void *ptr)
{
	t_long	*data;

	data = ptr;
	if (data->map->map2d[data->player.y][data->player.x - 1] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.x -= 1;
		data->moves++;
	}
	return (1);
}

int	handle_keys(int key, void *ptr)
{
	if (key == KEY_ESC)
		close_window(ptr);
	else if (key == KEY_W)
		w_key(ptr);
	else if (key == KEY_A)
		a_key(ptr);
	else if (key == KEY_S)
		s_key(ptr);
	else if (key == KEY_D)
		d_key(ptr);
	return (1);
}
