/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:57:29 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/23 11:19:15 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int res;

	res = find_place();
	ft_putnbr(g_filler.candidat.y);
	ft_putchar(' ');
	ft_putnbr(g_filler.candidat.x);
	ft_putchar('\n');
	if (!res)
		exit(1);
}

void	filler_p(void)
{
	int i;

	i = 0;
	ft_printf("FIELD\nheight = %i\nwidth = %i\n", g_filler.field.height, g_filler.field.width);
	while (i < g_filler.field.height)
		ft_printf("%s\n", g_filler.field.piece[i++]);
	i = 0;
	ft_printf("PIECE\nheight = %i\nwidth = %i\n", g_filler.piece.height, g_filler.piece.width);
	while (i < g_filler.piece.height)
		ft_printf("%s\n", g_filler.piece.piece[i++]);
}

void	clear_field(void)
{
	int i;

	i = 0;
	if (!g_filler.piece.piece)
		return ;
	while (i < g_filler.piece.height)
		ft_strdel(&g_filler.piece.piece[i++]);
	ft_memdel((void **)&g_filler.piece.piece);
}

void	read_field(void)
{
	char	*str;
	int		i;

	i = 0;
	get_next_line(0, &str);
	ft_strdel(&str);
	if (!g_filler.field.piece)
		g_filler.field.piece = (char **)malloc(sizeof(char *) * g_filler.field.height);
	while (i < g_filler.field.height)
	{
		get_next_line(0, &str);
		g_filler.field.piece[i] = ft_strdup(&str[4]);
		free(str);
		i++;
	}
}

void	read_piece(void)
{
	int		i;
	char	*str;

	i = 0;
	if (g_filler.piece.piece)
		clear_field();
	g_filler.piece.piece = (char **)malloc(sizeof(char *) * (g_filler.piece.height + 1));
	while (i < g_filler.piece.height)
	{
		get_next_line(0, &str);
		g_filler.piece.piece[i] = ft_strdup(str);
		free(str);
		i++;
	}
}

void	cycle_filler(void)
{
	char	*str;

	while (get_next_line(0, &str) > -1)
	{
		if (!str)
			continue ;
		if (!ft_strncmp(str, "Plateau ", 8))
		{
			g_filler.field.height = ft_atoi(&str[8]);
			g_filler.field.width = ft_atoi(ft_strchr(&str[8], ' '));
			read_field();
		}
		if (!strncmp(str, "Piece ", 6))
		{
			g_filler.piece.height = ft_atoi(&str[6]);
			g_filler.piece.width = ft_atoi(ft_strchr(&str[6], ' '));
			read_piece();
			filler();
		}
		ft_strdel(&str);
	}
}

int		main(void)
{
	char *str;

	ft_bzero(&g_filler, sizeof(t_filler));
	str = NULL;
	if (!get_next_line(0, &str) || ft_strncmp("$$$ exec p", str, 10))
		return (1);
	g_filler.player.number = str[10] == '1' ? 'O' : 'X';
	g_filler.enemy.number = str[10] == '1' ? 'X' : 'O';
	ft_strdel(&str);
	cycle_filler();
}
