/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/18 16:21:40 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_nl(const char *str)
{
	int i;

	i = 0;
	while (str[i] && i < BLOCK - 1)
	{
		if (!IS_END_LINE(i))
		{
			if (str[i] != '\n')
				return (0);
		}
		else
		{
			if (str[i] == '\n')
				return (0);
		}
		i++;
	}
	if (!IS_END_BLOCK(i))
	{
		if (str[BLOCK] && str[i] != '\n')
			return (0);
		if (!str[BLOCK] && str[i] == '\n')
			return (0);
	}
	return (1);
}

static int	check_cells(const char *str)
{
	int	i;
	int count_hash;
	int count_point;

	i = 0;
	count_hash = 0;
	count_point = 0;
	while (str[i] && i < BLOCK)
	{
		if (str[i] == '#')
			count_hash++;
		if (str[i] == '.')
			count_point++;
		i++;
	}
	if (count_hash == 4 && count_point == 12)
		return (1);
	return (0);
}

int			check_find_fig(const char *str, int os, t_deffig *def)
{
	int	i;
	int	j;
	int	pos;

	j = 0;
	while (j < FIG_AMT)
	{
		i = 1;
		while (i < LEN_FIG)
		{
			pos = def[j].y[i] * (LEN_FIG + 1) + def[j].x[i] + os - def[j].x[0];
			if (pos >= END_POS(os) || str[pos] != '#')
				break ;
			i++;
		}
		if (i == LEN_FIG)
			return (j);
		j++;
	}
	return (-1);
}

int			check_file(char *str, t_deffig *def)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_nl(&str[i]))
			return (0);
		if (!check_cells(&str[i]))
			return (0);
		i += BLOCK;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (check_find_fig(str, i, def) == -1)
				return (0);
			i = BLOCK - i % BLOCK + i;
		}
		else
			i++;
	}
	return (1);
}
