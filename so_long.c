/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:09 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 13:43:16 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	s_key(int key, void *ptr)
{
	t_long	*data;

	data = ptr;
	if (key == KEY_S
		&& data->map->map2d[data->player.y + 1][data->player.x] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.y += 1;
		data->moves++;
		putss("nb of moves now is : ");
		putnb(data->moves);
		putss("\n");
	}
	return (1);
}

int	d_key(int key, t_long *ptr)
{
	t_long	*data;

	data = ptr;
	if (key == KEY_D
		&& data->map->map2d[data->player.y][data->player.x + 1] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.x += 1;
		data->moves++;
		putss("nb of moves now is : ");
		putnb(data->moves);
		putss("\n");
	}
	return (1);
}

int	w_key(int key, void *ptr)
{
	t_long	*data;

	data = ptr;
	if (key == KEY_W
		&& data->map->map2d[data->player.y - 1][data->player.x] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.y -= 1;
		data->moves++;
		putss("nb of moves now is : ");
		putnb(data->moves);
		putss("\n");
	}
	return (1);
}

int	a_key(int key, void *ptr)
{
	t_long	*data;

	data = ptr;
	if (key == KEY_A
		&& data->map->map2d[data->player.y][data->player.x - 1] != '1')
	{
		if (data->map->map2d[data->player.y][data->player.x] == 'C')
		{
			data->map->map2d[data->player.y][data->player.x] = '0';
			data->nb_collectibles++;
		}
		data->player.x -= 1;
		data->moves++;
		putss("nb of moves now is : ");
		putnb(data->moves);
		putss("\n");
	}
	return (1);
}

int	handle_keys(int key, void *ptr)
{
	if (key == KEY_ESC)
		close_window(ptr);
	if (key == KEY_W)
		w_key(key, ptr);
	if (key == KEY_A)
		a_key(key, ptr);
	if (key == KEY_S)
		s_key(key, ptr);
	if (key == KEY_D)
		d_key(key, ptr);
	return (1);
}
