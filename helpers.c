/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:42:27 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 17:48:33 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*remove_new_line(char *line)
{
	int		i;
	char	*tmp;
	int		size;

	size = ft_len(line);
	i = 0;
	if (line[size - 1] != '\n')
		tmp = ft_strdup(line);
	else
	{
		tmp = malloc(sizeof(char) * (size));
		if (!tmp)
			return (NULL);
		while (line[i] && line[i] != '\n')
		{
			tmp[i] = line[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

void	add_node(t_node **raw_map, char *line)
{
	t_node	*node;
	t_node	*tmp;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->data = line;
	node->next = NULL;
	tmp = *raw_map;
	if (!tmp)
	{
		*raw_map = node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	puterr(char *s)
{
	write(2, "Error\n", 6);
	if (s)
		write(2, s, ft_len(s));
	exit(1);
}

static int	lst_size(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char	**lst_to_array(t_node *map)
{
	t_node	*head;
	char	**map2d;
	int		i;

	i = 0;
	map2d = malloc(sizeof(char *) * (lst_size(map) + 1));
	if (!map2d)
		return (NULL);
	head = map;
	while (head)
	{
		map2d[i++] = ft_strdup(head->data);
		head = head->next;
	}
	map2d[i] = NULL;
	return (map2d);
}
