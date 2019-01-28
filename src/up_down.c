/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:40:55 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/28 17:44:32 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_piece(int y, int x, int count)
{
	int x2;
	int y2;
	int cx;
	int cy;

	cy = g_filler.candidat.y;
	cx = g_filler.candidat.x;
	y2 = cy;
	while (y2 < g_filler.piece.heightreal + cy)
	{
		x2 = cx;
		while (x2 < g_filler.piece.widthreal + cx)
		{
			if (PZ && (FP == PN || FP == PN + 32))
				count++;
			if (PZ && (FP == EN || FP == EN + 32))
				return (0);
			x2++;
		}
		y2++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		up_right(void)
{
	int x;
	int y;

	y = 0;
	while (y < g_filler.field.height)
	{
		x = g_filler.field.width - 1;
		while (x >= 0)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - y >= 0 &&
					g_filler.field.width - g_filler.piece.widthreal - x >= 0)
				if (place_piece(y, x, 0))
				{
					g_filler.candidat.x = x - g_filler.candidat.x;
					g_filler.candidat.y = y - g_filler.candidat.y;
					return (1);
				}
			x--;
		}
		y++;
	}
	return (0);
}

int		down_left(void)
{
	int x;
	int y;

	y = g_filler.field.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - y >= 0 &&
					g_filler.field.width - g_filler.piece.widthreal - x >= 0)
				if (place_piece(y, x, 0))
				{
					g_filler.candidat.x = x - g_filler.candidat.x;
					g_filler.candidat.y = y - g_filler.candidat.y;
					return (1);
				}
			x++;
		}
		y--;
	}
	return (0);
}

int		up_left(void)
{
	int x;
	int y;

	y = 0;
	while (y < g_filler.field.height)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - y >= 0 &&
					g_filler.field.width - g_filler.piece.widthreal - x >= 0)
				if (place_piece(y, x, 0))
				{
					g_filler.candidat.x = x - g_filler.candidat.x;
					g_filler.candidat.y = y - g_filler.candidat.y;
					return (1);
				}
			x++;
		}
		y++;
	}
	return (0);
}

int		down_right(void)
{
	int x;
	int y;

	y = g_filler.field.height - 1;
	while (y >= 0)
	{
		x = g_filler.field.width - 1;
		while (x >= 0)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - y >= 0 &&
					g_filler.field.width - g_filler.piece.widthreal - x >= 0)
			{
				if (place_piece(y, x, 0))
				{
					g_filler.candidat.x = x - g_filler.candidat.x;
					g_filler.candidat.y = y - g_filler.candidat.y;
					return (1);
				}
			}
			x--;
		}
		y--;
	}
	return (0);
}
