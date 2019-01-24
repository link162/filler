/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:57:29 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/24 15:28:26 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_field(void)
{
	char		*str;
	int			i;
	static int	x;

	i = 0;
	get_next_line(0, &str);
	free(str);
	if (x != 10)
		g_filler.field.piece = (char **)malloc(sizeof(char *)
				* g_filler.field.height);
	while (i < g_filler.field.height)
	{
		get_next_line(0, &str);
		if (x == 10)
			ft_strcpy(g_filler.field.piece[i], (&str[4]));
		else
			g_filler.field.piece[i] = ft_strdup(&str[4]);
		free(str);
		i++;
	}
	x = 10;
}

void	read_piece(void)
{
	int			i;
	char		*str;

	i = 0;
	g_filler.piece.piece = (char **)malloc(sizeof(char *)
			* (g_filler.piece.height + 1));
	while (i < g_filler.piece.height)
	{
		get_next_line(0, &str);
		g_filler.piece.piece[i] = strdup(str);
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
			filler(&str);
		}
		free(str);
	}
}

int		main(void)
{
	char *str;

	ft_bzero(&g_filler, sizeof(t_filler));
	if (!get_next_line(0, &str) || ft_strncmp("$$$ exec p", str, 10))
		return (1);
	g_filler.player.number = str[10] == '1' ? 'O' : 'X';
	g_filler.enemy.number = str[10] == '1' ? 'X' : 'O';
	free(str);
	cycle_filler();
}
