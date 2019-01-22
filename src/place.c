/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:43:34 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/22 19:36:04 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_piece(int y, int x)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < g_filler.piece.height)
	{
		j = 0;
		while (j < g_filler.piece.width)
		{
			if (g_filler.piece.piece[i][j] == '.')
				;
			else if (g_filler.piece.piece[i][j] == '*' && g_filler.field.piece[y][x] == '.')
				;
			else if (g_filler.piece.piece[i][j] == '*' && (g_filler.field.piece[y][x] == g_filler.player.number || g_filler.field.piece[y][x] == g_filler.player.number + 32))
				count++;
			else
				return (0);
			j++;
			x++;
		}
		i++;
		y++;
		x -= g_filler.piece.width;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		find_place(void)
{
	int x;
	int y;

	y = 0;
	while (y < g_filler.field.height)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.height - g_filler.piece.height >= 0 && g_filler.field.width - g_filler.piece.width >= 0)
				if (place_piece(y, x))
				{
					g_filler.candidat.y = y;
					g_filler.candidat.x = x;
					return (1);
				}
			x++;
		}
		y++;
	}
	g_filler.candidat.y = 0;
	g_filler.candidat.x = 0;
	return (0);
}
