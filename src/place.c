/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:43:34 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/24 18:25:44 by ybuhai           ###   ########.fr       */
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
			if (g_filler.piece.piece[i][j] == '*' && (g_filler.field.piece[y][x] ==
									g_filler.player.number || g_filler.field.piece[y][x] == g_filler.player.number + 32))
				count++;
			if (g_filler.piece.piece[i][j] == '*' && (g_filler.field.piece[y][x] ==
									g_filler.enemy.number || g_filler.field.piece[y][x] == g_filler.enemy.number + 32))
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

int		down_left(void)
{
	int x;
	int y;

	y = g_filler.field.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < g_filler.field.height)
		{
			if (g_filler.field.height - y - g_filler.piece.height >= 0 && g_filler.field.width - x - g_filler.piece.width >= 0)
				if (place_piece(y, x))
				{
					g_filler.candidat.y = y;
					g_filler.candidat.x = x;
					return (1);
				}
			x++;
		}
		y--;
	}
	g_filler.candidat.y = 0;
	g_filler.candidat.x = 0;
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
			if (g_filler.field.height - y - g_filler.piece.height >= 0 && g_filler.field.width - x - g_filler.piece.width >= 0)
				if (place_piece(y, x))
				{
					g_filler.candidat.y = y;
					g_filler.candidat.x = x;
					return (1);
				}
			x--;
		}
		y--;
	}
	g_filler.candidat.y = 0;
	g_filler.candidat.x = 0;
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
			if (g_filler.field.height - y - g_filler.piece.height >= 0 && g_filler.field.width - x - g_filler.piece.width >= 0)
				if (place_piece(y, x))
				{
					g_filler.candidat.y = y;
					g_filler.candidat.x = x;
					return (1);
				}
			x--;
		}
		y++;
	}
	g_filler.candidat.y = 0;
	g_filler.candidat.x = 0;
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
			if (g_filler.field.height - y - g_filler.piece.height >= 0 && g_filler.field.width - x - g_filler.piece.width >= 0)
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

void	find_current_enemy_coords(void)
{
	int x;
	int y;

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

void	clear_field(void)
{
	int	i;
	char *str;

	i = 0;
	while (i < g_filler.field.height)
		free(g_filler.field.piece[i++]);
	free(g_filler.field.piece);
	get_next_line(-5, &str);
	exit (1);
}

void	coords_start(void)
{
	int			x;
	int			y;
	static int	z;

	if (z != 5)
	{
		y = 0;
		while (y < g_filler.field.height)
		{
			x = 0;
			while (x < g_filler.field.width)
			{
				if (g_filler.field.piece[y][x] == g_filler.enemy.number)
				{
					g_filler.enemy.start.x = x;
					g_filler.enemy.start.y = y;
				}
				else if (g_filler.field.piece[y][x] == g_filler.player.number)
				{
					g_filler.player.start.x = x;
					g_filler.player.start.y = y;
				}
				x++;
			}
			y++;
		}
	}
	z = 5;
}

int		find_place(void)
{
//	ft_printf("p.x-%i e.x-%i p.y-%i p.e-%i\n", g_filler.player.start.x, g_filler.enemy.start.x, g_filler.player.start.y, g_filler.enemy.start.y);
	if (g_filler.player.start.x > g_filler.enemy.start.x && g_filler.player.start.y > g_filler.enemy.start.y)
	{
//		ft_printf("upleft\n");
		return (up_left());
	}
	else if (g_filler.player.start.x > g_filler.enemy.start.x && g_filler.player.start.y < g_filler.enemy.start.y)
	{
//		ft_printf("down_left\n");
		return (down_left());
	}
	else if (g_filler.player.start.x < g_filler.enemy.start.x && g_filler.player.start.y > g_filler.enemy.start.y)
	{
//		ft_printf("upright\n");
		return (up_right());
	}
	else
	{
//		ft_printf("downright\n");
		return (down_right());
	}
}

void	filler(char **str)
{
	int res;
	int i;

	g_filler.enemy.start.x = -1;
	coords_start();
//	find_real_piece();
	if (g_filler.enemy.start.x == -1)
		find_current_enemy_coords();
//	ft_printf("+++%i\n", g_filler.enemy.start.x);
	res = find_place();
	ft_putnbr(g_filler.candidat.y);
	ft_putchar(' ');
	ft_putnbr(g_filler.candidat.x);
	ft_putchar('\n');
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
