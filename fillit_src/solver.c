/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/18 16:06:52 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_def(int count, char matrix[count][count])
{
	int		i;
	int		j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			matrix[i][j] = '.';
	}
}

static int	move_fig(t_figure *f, int len, t_point p, char matrix[len][len])
{
	int i;

	i = -1;
	while (++i < LEN_FIG)
	{
		if (((*f).x[i] + p.x < 0) || ((*f).y[i] + p.y < 0)
				|| ((*f).x[i] + p.x > len - 1)
				|| ((*f).y[i] + p.y > len - 1)
				|| matrix[(*f).y[i] + p.y][(*f).x[i] + p.x] != '.')
			return (0);
	}
	i = -1;
	while (++i < LEN_FIG)
	{
		(*f).x[i] += p.x;
		(*f).y[i] += p.y;
	}
	return (1);
}

static void	reset_fig(t_figure *f)
{
	int i;
	int count;

	count = 1;
	while (cmp((*f).x, count))
		count++;
	i = -1;
	while (++i < LEN_FIG)
		(*f).x[i] = (*f).x[i] - count + 1;
	count = 1;
	while (cmp((*f).y, count))
		count++;
	i = -1;
	while (++i < LEN_FIG)
		(*f).y[i] = (*f).y[i] - count + 1;
}

static int	backtrack(int len, t_figure *f, char matrix[len][len])
{
	t_point start_pos;

	start_pos.y = -1;
	while (++(start_pos.y) < len)
	{
		start_pos.x = -1;
		while (++(start_pos.x) < len)
		{
			if (move_fig(f, len, (t_point) {start_pos.x, start_pos.y}, matrix))
			{
				set_fig(len, f, matrix);
				if (!f[1].name || backtrack(len, f + 1, matrix))
					return (1);
				clean_fig(len, f, matrix);
				reset_fig(f);
			}
		}
	}
	return (0);
}

void		set_matrix(int len, t_figure *f)
{
	char matrix[len][len];

	set_def(len, matrix);
	if (!backtrack(len, f, matrix))
		set_matrix(len + 1, f);
	else
		print(len, matrix);
}
