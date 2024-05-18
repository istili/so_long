/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:07 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 20:09:06 by istili           ###   ########.fr       */
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
	data->mlx.p = mlx_init();
	if (data->mlx.p == NULL)
		puterr(MALLOC_ERR);
}

static void	main_helper(t_long *data, t_map *map)
{
	init_image(data);
	mlx_hook(data->mlx.win, 17, (1L << 17), close_window, data);
	mlx_hook(data->mlx.win, 2, (1L << 0), handle_keys, data);
	data->map->map2d = lst_to_array(map->content);
	mlx_loop_hook(data->mlx.p, draw_map, data);
	mlx_loop(data->mlx.p);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_long	data;

	map = ft_parsing(ac, av);
	main_inits(&data, map);
	data.mlx.win = mlx_new_window(data.mlx.p,
			data.screen.x, data.screen.y, "My game");
	if (data.mlx.win == NULL)
		puterr(MLX_ERR);
	data.mlx.img.ptr = mlx_new_image(data.mlx.p, data.screen.x, data.screen.y);
	if (data.mlx.p == NULL)
	{
		mlx_destroy_window(data.mlx.p, data.mlx.win);
		puterr(MLX_ERR);
	}
	data.mlx.img.addr = mlx_get_data_addr(data.mlx.img.ptr,
			&data.mlx.img.bit_pr_pxl, &data.mlx.img.line_len,
			&data.mlx.img.endian);
	if (data.mlx.img.addr == NULL)
		close_window(&data);
	main_helper(&data, map);
	close_window(&data);
	return (0);
}

// keyp_events->>hooks->
// * mlx_connection *
// data.mlx.p = mlx_connection that we establish using mlx_init() function;
// 
// window is just another memory malloc'd
//
// * event loop *
// "mlx_loop" start the event loop 
// -> an event loop keeps the app running checking for events
// such as : mouse clicks, keyboard presses
// while (app runnning)
// {
//		check for events;
//			execute func for those events;
// }
// 
//  * hooks *
//	hooking into events 
// (when i press a key render is triggered)  