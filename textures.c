/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:58:47 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 13:28:08 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	int		dst;

	dst = (y * data->line_len) + (x * (data->bit_pr_pxl / 8));
	*(unsigned int *)(data->addr + dst) = color;
}

int	close_window(t_long *data)
{
	mlx_destroy_image(data->mlx.p, data->mlx.img.ptr);
	mlx_destroy_window(data->mlx.p, data->mlx.win);
	exit(1);
	return (1);
}

char	*init_img_util(t_long *data, char *filename)
{
	int		tmp;
	void	*res;

	res = mlx_xpm_file_to_image(data->mlx.p, filename, &tmp, &tmp);
	if (!res)
		puterr("Failed to convert xpm file\n");
	return (res);
}

void	init_image(t_long *data)
{
	data->textures.player = init_img_util(data, "xpm/player.xpm");
	data->textures.collect = init_img_util(data, "xpm/collect.xpm");
	data->textures.exit = init_img_util(data, "xpm/exit.xpm");
	data->textures.wall = init_img_util(data, "xpm/wall.xpm");
}