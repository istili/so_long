/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:07 by istili            #+#    #+#             */
/*   Updated: 2024/05/20 15:02:16 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	main_inits(t_long *data, t_map *map)
{
	data->map = map;
	data->screen.x = map->size.x * BRICK_SIZE;
	data->screen.y = map->size.y * BRICK_SIZE;
	data->player.x = map->start.x;
	data->player.y = map->start.y;
	data->moves = 0;
	data->nb_collectibles = 0;
	data->game.p = mlx_init();
	if (data->game.p == NULL)
		puterr(MLX_ERR);
}

static void	main_helper(t_long *data, t_map *map)
{
	init_image(data);
	mlx_hook(data->game.win, 17, (1L << 17), close_window, data);
	mlx_hook(data->game.win, 2, (1L << 0), handle_keys, data);
	data->map->map2d = lst_to_array(map->content);
	if (!data->map->map2d)
		puterr(MALLOC_ERR);
	mlx_loop_hook(data->game.p, draw_map, data);
	mlx_loop(data->game.p);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_long	data;

	map = ft_parsing(ac, av);
	main_inits(&data, map);
	data.game.win = mlx_new_window(data.game.p,
			data.screen.x, data.screen.y, "My game");
	if (data.game.win == NULL)
		puterr(MLX_ERR);
	data.game.img.ptr = mlx_new_image(data.game.p,
			data.screen.x, data.screen.y);
	if (data.game.p == NULL)
	{
		mlx_destroy_window(data.game.p, data.game.win);
		puterr(MLX_ERR);
	}
	data.game.img.addr = mlx_get_data_addr(data.game.img.ptr,
			&data.game.img.bpp, &data.game.img.line_len,
			&data.game.img.endian);
	if (data.game.img.addr == NULL)
		close_window(&data);
	main_helper(&data, map);
	return (0);
}
