/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_real_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:59:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/26 17:49:17 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		cut_down(void)
{
	int x;
	int y;

	y = g_filler.piece.heightreal + g_filler.candidat.y - 1;
	x = g_filler.candidat.x;
	while (x < g_filler.piece.widthreal + g_filler.candidat.x)
	{
		if (g_filler.piece.piece[y][x] == '*')
			return (0);
		x++;
	}
	return (1);
}

int		cut_left(void)
{
	int x;
	int y;

	y = g_filler.candidat.y;
	x = g_filler.candidat.x;
	while (y < g_filler.piece.height)
	{
		if (g_filler.piece.piece[y][x] == '*')
			return (0);
		y++;
	}
	return (1);
}

int		cut_right(void)
{
	int x;
	int y;

	y = g_filler.candidat.y;
	x = g_filler.piece.widthreal + g_filler.candidat.x - 1;
	while (y < g_filler.piece.heightreal + g_filler.candidat.y)
	{
		if (g_filler.piece.piece[y][x] == '*')
			return (0);
		y++;
	}
	return (1);
}

int		cut_up(void)
{
	int x;
	int y;

	y = g_filler.candidat.y;
	x = g_filler.candidat.x;
	while (x < g_filler.piece.widthreal)
	{
		if (g_filler.piece.piece[y][x] == '*')
			return (0);
		x++;
	}
	return (1);
}

void	find_real_piece(void)
{
	g_filler.piece.widthreal = g_filler.piece.width;
	g_filler.piece.heightreal = g_filler.piece.height;
	g_filler.candidat.x = 0;
	g_filler.candidat.y = 0;
	while (cut_up())
	{
		g_filler.piece.heightreal--;
		g_filler.candidat.y++;
	}
	while (cut_left())
	{
		g_filler.piece.widthreal--;
		g_filler.candidat.x++;
	}
	while (cut_down())
		g_filler.piece.heightreal--;
	while (cut_right())
		g_filler.piece.widthreal--;
}
