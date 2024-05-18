/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:46:14 by istili            #+#    #+#             */
/*   Updated: 2024/04/26 14:42:51 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check(char *bufr, int fd)
{
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX || read(fd, bufr, 0) < 0)
		return (free(bufr), bufr = NULL, NULL);
	if (!bufr)
		bufr = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!bufr)
		return (NULL);
	return (bufr);
}

char	*get_next_line(int fd)
{
	static char		*bufr;
	char			*line;
	int				i;

	bufr = check(bufr, fd);
	if (!bufr)
		return (NULL);
	line = ft_sjoin(NULL, bufr);
	if (!line)
		return (free(bufr), bufr = NULL, NULL);
	if (check_str(bufr) != 0)
		return (line);
	i = 1;
	while (i > 0)
	{
		i = read(fd, bufr, BUFFER_SIZE);
		if (i == -1 || (i == 0 && line[0] == '\0'))
			return (free(bufr), bufr = NULL, free(line), NULL);
		line = ft_sjoin(line, bufr);
		if (!line)
			return (free(bufr), bufr = NULL, NULL);
		if (check_str(bufr) != 0)
			return (line);
	}
	return (line);
}
