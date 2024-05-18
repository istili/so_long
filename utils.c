/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:36:42 by istili            #+#    #+#             */
/*   Updated: 2024/05/18 13:39:20 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	putchr(char c)
{
	write(1, &c, 1);
}

void	putnb(int n)
{
	if (n >= 10)
	{
		putnb(n / 10);
		putnb(n % 10);
	}
	else
		putchr(n + '0');
}

void	putss(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		putchr(s[i++]);
}
