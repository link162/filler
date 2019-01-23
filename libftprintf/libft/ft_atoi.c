/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:58:21 by ybuhai            #+#    #+#             */
/*   Updated: 2018/11/07 22:12:54 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_return(unsigned long long res, int minus, const char *str)
{
	int	c;

	c = 0;
	while (*str <= '1' || *str >= '9')
		str++;
	while (ft_isdigit(*(str + c)))
		c++;
	if (c >= 19)
		return (minus == -1 ? 0 : -1);
	if (res > 9223372036854775807)
		return (minus == -1 ? 0 : -1);
	else
		return (res * minus);
}

int			ft_atoi(const char *str)
{
	unsigned long long	res;
	int					l;
	int					x;
	int					minus;

	minus = 1;
	x = -1;
	l = 0;
	res = 0;
	while (ft_isspace(*str))
		str++;
	while (str[l])
		l++;
	while (++x <= l)
	{
		if (ft_isdigit(str[x]))
			res = (res * 10) + (str[x] - '0');
		else if (x == 0 && (str[x] == '-' || str[x] == '+'))
			minus = str[x] == '-' ? -1 : 1;
		else
			return (get_return(res, minus, str));
	}
	return (get_return(res, minus, str));
}
