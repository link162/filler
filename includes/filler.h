/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:45:33 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/26 17:45:35 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libftprintf/libftprintf.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	char		number;
	t_point		start;
}				t_player;

typedef struct	s_piece
{
	int			height;
	int			heightreal;
	int			width;
	int			widthreal;
	char		**piece;
}				t_piece;

typedef struct	s_filler
{
	t_player	player;
	t_player	enemy;
	t_piece		field;
	t_piece		piece;
	t_point		candidat;
}				t_filler;

t_filler		g_filler;
void			filler(char **str);
void			find_real_piece(void);

#endif
