/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/10 11:53:25 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_def(int count, char matrix[count][count])
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

//int		check_move(char matrix[][LEN_FIG + 1], t_figure *f)

void	print(int count, char matrix[count][count])
{
	int		i;
	int		j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			printf("%c", matrix[i][j]);
		printf("\n");
	}
}

int		solve(int count, t_figure *f) // Backtracking
{
	char	matrix[count * 4][count * 4];

	if (!f)
		return (0);
	set_def(count * 4, matrix);
	print(count * 4, matrix);
	return (1);
}
