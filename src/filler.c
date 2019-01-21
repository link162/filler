/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:57:29 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/21 17:45:41 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cycle_filler(void)
{
	char	*str;
	int		res;

	while ((res = get_next_line(0, &str)) > -1)
	{
		if (!str)
			continue ;
		if (!ft_strncmp(str, "Plateau ", 8))
			read_field(str, &g_filler.field);
		if (!strncmp(str, "Piece ", 6))
		{
			read_field(str, &g_filler.piece);
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
