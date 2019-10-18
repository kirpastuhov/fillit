/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:16 by kpastukh          #+#    #+#             */
/*   Updated: 2019/10/18 16:19:01 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_smallest_grid(int count)
{
	int n;

	n = 2;
	while (count * LEN_FIG > n * n)
		n++;
	return (n);
}

void	print(int count, char matrix[count][count])
{
	int		i;
	int		j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			ft_putchar(matrix[i][j]);
		ft_putendl("");
	}
}

void	set_fig(int len, t_figure *f, char matrix[len][len])
{
	int i;

	i = -1;
	while (++i < LEN_FIG)
		matrix[(*f).y[i]][(*f).x[i]] = (*f).name;
}

void	clean_fig(int len, t_figure *f, char matrix[len][len])
{
	int i;

	i = -1;
	while (++i < LEN_FIG)
		matrix[(*f).y[i]][(*f).x[i]] = '.';
}

int		cmp(int *val, int count)
{
	int i;

	i = -1;
	while (++i < LEN_FIG)
	{
		if (val[i] - count < 0)
			return (0);
	}
	return (1);
}
