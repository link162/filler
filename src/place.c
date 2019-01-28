/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:43:34 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/28 17:41:37 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_field(void)
{
	int		i;
	char	*str;

	i = 0;
	while (i < g_filler.field.height)
		free(g_filler.field.piece[i++]);
	free(g_filler.field.piece);
	get_next_line(-5, &str);
	exit(1);
}

void	find_player_start(void)
{
	int x;
	int y;

	y = 0;
	while (y < g_filler.field.height)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.piece[y][x] == g_filler.player.number)
			{
				g_filler.player.start.x = x;
				g_filler.player.start.y = y;
			}
			else if (g_filler.field.piece[y][x] == g_filler.enemy.number)
			{
				g_filler.enemy.start.x = x;
				g_filler.enemy.start.y = y;
			}
			x++;
		}
		y++;
	}
}

void	coords_current(void)
{
	int			y;
	int			x;
	static int	z;

	if (z != 15)
	{
		find_player_start();
		z = 15;
	}
	y = 0;
	while (y < g_filler.field.height)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.piece[y][x] == g_filler.enemy.number + 32)
			{
				g_filler.enemy.start.x = x;
				g_filler.enemy.start.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int		make_choise(void)
{
	if (g_filler.player.start.x <= g_filler.enemy.start.x &&
			g_filler.player.start.y >= g_filler.enemy.start.y - 4)
		return (up_right());
	else if (g_filler.player.start.x <= g_filler.enemy.start.x &&
			g_filler.player.start.y <= g_filler.enemy.start.y)
		return (down_right());
	else if (g_filler.player.start.x >= g_filler.enemy.start.x &&
			g_filler.player.start.y <= g_filler.enemy.start.y)
		return (down_left());
	else
		return (up_left());
}

void	filler(char **str)
{
	int res;
	int i;

	coords_current();
	find_real_piece();
	res = make_choise();
	if (!res)
	{
		g_filler.candidat.y = 0;
		g_filler.candidat.x = 0;
	}
	g_filler.player.start.x = g_filler.candidat.x;
	g_filler.player.start.y = g_filler.candidat.y;
	ft_printf("%i %i\n", g_filler.candidat.y, g_filler.candidat.x);
	i = 0;
	while (i < g_filler.piece.height)
		free(g_filler.piece.piece[i++]);
	free(g_filler.piece.piece);
	if (!res)
	{
		free(*str);
		clear_field();
	}
}
