/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:46:50 by istili            #+#    #+#             */
/*   Updated: 2024/04/26 14:42:04 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	len(char *str);
char	*ft_sjoin(char *s1, char *s2);
int		check_str(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

#endif
