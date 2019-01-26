/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:43:34 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/26 17:27:30 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
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

int		place_piece(int y, int x)
{
	int x2;
	int y2;
	int count;

	//переделать размерности и сравнения полей
	count = 0;
	y2 = g_filler.candidat.y;//0
	while (y2 < g_filler.piece.heightreal + g_filler.candidat.y)
	{
		x2 = g_filler.candidat.x;//1
		while (x2 < g_filler.piece.widthreal + g_filler.candidat.x)//2
		{
//			ft_printf("***y2 = %i x2 = %i\n", y, x);
			if (g_filler.piece.piece[y2][x2] == '*' && (g_filler.field.piece[y2 + y - g_filler.candidat.y][x2 + x - g_filler.candidat.x] == g_filler.player.number || g_filler.field.piece[y2 + y - g_filler.candidat.y][x2 + x - g_filler.candidat.x] == g_filler.player.number + 32))
				count++;
//			ft_printf("hellllo\n");
			if (g_filler.piece.piece[y2][x2] == '*' && (g_filler.field.piece[y2 + y - g_filler.candidat.y][x2 + x - g_filler.candidat.x] == g_filler.enemy.number || g_filler.field.piece[y2 + y - g_filler.candidat.y][x2 + x - g_filler.candidat.x] == g_filler.enemy.number + 32))
				return (0);
			x2++;
		}
		y2++;
	}
//	ft_printf("field y - %i x - %i\n", y, x);
	if (count == 1)
		return (1);
//	ft_putstr("out\n");
	return (0);
}

int		up_right(void)
{
	int x;
	int y;

//	ft_printf("ur");
	y = 0;
	while (y < g_filler.field.height)
	{
		x = g_filler.field.width - 1;
		while (x >= 0)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - g_filler.candidat.y - y >= 0 && g_filler.field.width - g_filler.piece.widthreal - g_filler.candidat.x - x >= 0)
				if (place_piece(y, x))
				{
//					ft_printf("will put y = %i  x = %i\n", y, x);
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

//	ft_printf("dl");
	y = g_filler.field.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - g_filler.candidat.y - y >= 0 && g_filler.field.width - g_filler.piece.widthreal - g_filler.candidat.x - x >= 0)
				if (place_piece(y, x))
				{
//					ft_printf("will put y = %i  x = %i\n", y, x);
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

//	ft_printf("ul");
	y = 0;
	while (y < g_filler.field.height)
	{
		x = 0;
		while (x < g_filler.field.width)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - g_filler.candidat.y - y >= 0 && g_filler.field.width - g_filler.piece.widthreal - g_filler.candidat.x - x >= 0)
				if (place_piece(y, x))
				{
//					ft_printf("will put y = %i  x = %i\n", y, x);
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

//	ft_printf("dr");
	y = g_filler.field.height - 1;
	while (y >= 0)
	{
		x = g_filler.field.width - 1;
		while (x >= 0)
		{
			if (g_filler.field.height - g_filler.piece.heightreal - g_filler.candidat.y - y >= 0 && g_filler.field.width - g_filler.piece.widthreal - g_filler.candidat.x - x >= 0)
			{
//				ft_printf("---y = %i x = %i\n", y, x);
				if (place_piece(y, x))
				{
//					ft_printf("willllll put y = %i  x = %i\n", y, x);
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
//	ft_printf("my y-%i x-%i enemy y-%i x-%i\n", g_filler.player.start.y, g_filler.player.start.x, g_filler.enemy.start.y, g_filler.enemy.start.x);
	if (g_filler.player.start.x <= g_filler.enemy.start.x && g_filler.player.start.y >= g_filler.enemy.start.y - 3)
		return (up_right());
	else if (g_filler.player.start.x <= g_filler.enemy.start.x && g_filler.player.start.y <= g_filler.enemy.start.y)
		return (down_right());
	else if (g_filler.player.start.x >= g_filler.enemy.start.x && g_filler.player.start.y <= g_filler.enemy.start.y)
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
//	ft_printf("put y-%i x-%i real y-%i x-%i\n", g_filler.piece.height, g_filler.piece.width, g_filler.piece.heightreal, g_filler.piece.widthreal);
/*	int x;
	int y;
	y = g_filler.candidat.y;
	while (y < g_filler.piece.heightreal + g_filler.candidat.y)
	{
//		ft_printf("$$$$$%i\n", g_filler.candidat.x);
		x = g_filler.candidat.x;
		while (x < g_filler.piece.widthreal + g_filler.candidat.x)
		{
			ft_printf("%c", g_filler.piece.piece[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}*/
	res = make_choise();
	if (!res)
	{
		g_filler.candidat.y = 0;
		g_filler.candidat.x = 0;
	}
	g_filler.player.start.x = g_filler.candidat.x;
	g_filler.player.start.y = g_filler.candidat.y;
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
