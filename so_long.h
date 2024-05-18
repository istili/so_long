/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:22 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 18:23:30 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define OPEN_ERR "open error\n"
# define EXTENSION_ERR "Extension .ber not found!\n"
# define MALLOC_ERR "allocation fail\n"
# define RECTANGULAR_ERR "The map must be rectangular.\n"
# define WALL_ERR "The map must be closed/surrounded by walls..\n"
# define PLAYER_ERR "map have more than one player\n"
# define EXIT_ERR "map have more than one exit\n"
# define MAP_ERR "map error\n"
# define MLX_ERR "Error\n"
# define ARG_ERR "Error: No map.xpm found!"
# define BRICK_SIZE 32

typedef struct s_img
{
	void	*collect;
	void	*player;
	void	*road;
	void	*wall;
	void	*exit;
	void	*closed;
}	t_img;

typedef struct s_node
{
	struct s_node	*next;
	char			*data;
}	t_node;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_map
{
	char	**map2d;
	t_node	*content;
	t_point	size;
	int		collectible;
	t_point	start;
	t_point	exit;
}	t_map;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		line_len;
	int		bit_pr_pxl;
	int		endian;
}	t_image;

typedef struct s_var
{
	void	*p;
	void	*win;
	t_image	img;
}	t_var;

typedef struct s_long
{
	t_map	*map;
	t_var	mlx;
	t_point	screen;
	int		nb_collectibles;
	t_img	textures;
	int		moves;
	t_point	player;
}				t_long;

int		ft_len(char *s);
void	puterr(char *s);
void	putnb(int n);
void	putss(char *s);
void	add_node(t_node **head, char *line);
t_map	*ft_parsing(int ac, char **av);
void	check_line(t_map *map, char *line, int size);
int		check_map(t_map *map);
char	*remove_new_line(char *line);
char	**lst_to_array(t_node *map);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, char c);
void	free_arr(char **arr);
int		close_window(t_long *data);
int		handle_keys(int key, void *ptr);
void	flood_fill(char **map2d, t_point size, t_point begin);
int		draw_map(t_long *data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	init_image(t_long *data);
char	*ft_itoa(int n);
void	score(t_long *data);
void	image_to_window(t_long *data);

#endif
