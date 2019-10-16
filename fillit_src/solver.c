/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/15 16:20:22 by kpastukh         ###   ########.fr       */
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

int		ft_find_smallest_grid(int count)
{
	int n = 4;
	if (count * 4 >= n * n)
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
			printf("%c", matrix[i][j]);
		printf("\n");
	}
	ft_putendl(" ");
	ft_putendl(" ");
}


int		move_fig(t_figure *f, int len, t_point p, char matrix[len][len])
{
	int i;

	i = -1;
	while (++i < LEN_FIG)
		if (((*f).x[i] + p.x < 0) || ((*f).y[i] + p.y < 0)
				|| ((*f).x[i] + p.x > len - 1)
				|| ((*f).y[i] + p.y > len - 1)
				|| matrix[(*f).y[i] + p.y][(*f).x[i] + p.x] != '.')
			return (0);
	i = -1;
	while (++i < LEN_FIG)
	{
		(*f).x[i] += p.x;
		(*f).y[i] += p.y;
	}
	return (1);
}


/* t_point		find_pos(int len, t_figure *f, char matrix[len][len]) */
int		find_pos(int len, t_figure *f, char matrix[len][len])
{
	int i = -1;
	int j = -1;
	printf("find_pos  11  x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n",
			f[0].x[0], f[0].y[0], f[0].x[1], f[0].y[1],
			f[0].x[2], f[0].y[2], f[0].x[3], f[0].y[3]);
	while (++i < len)
		while (++j < len)
			if (move_fig(f, len, (t_point){j, i}, matrix))
			{
				printf("find_pos  22  x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n",
						f[0].x[0], f[0].y[0], f[0].x[1], f[0].y[1],
						f[0].x[2], f[0].y[2], f[0].x[3], f[0].y[3]);
				return (1);
			}
				/* return ((t_point){j, i}); */
	/* return ((t_point){-1, -1}); */
	return (0);
}

void	set_fig(int len, t_figure *f, char matrix[len][len])
{
	int i = -1;
	while (++i < LEN_FIG)
		matrix[(*f).y[i]][(*f).x[i]] = (*f).name;
}

void		clean_fig(int len, t_figure *f, char matrix[len][len])
{
	int i = -1;
	while (++i < LEN_FIG)
		matrix[(*f).y[i]][(*f).x[i]] = '.';
}

int		backtrack(int len, t_figure *f, char matrix[len][len])
{
	static int i = 5;
	/* printf("backtrack()\n"); */
	while (1)
	{
		//find new fig position
		if (!find_pos(len, f, matrix))
			break;
		//set fig in matrix
		set_fig(len, f, matrix);
		//call solve for next fig
		/* printf("len = %d\n", len); */
		/* printf("figure x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", */
		/* 		f[0].x[0], f[0].y[0], f[0].x[1], f[0].y[1], */
		/* 		f[0].x[2], f[0].y[2], f[0].x[3], f[0].y[3]); */
		if (!f || backtrack(len, f+1, matrix))
			return (1);
		//else remove this fig in matrix
		clean_fig(len, f, matrix);
	}
	/* exit(0); */
	if (i == 0)
		exit(0);
	i--;
	printf("backtrack()2222\n");
	return (0);
}

void		set_matrix(int len, t_figure *f)
{
	char matrix[len][len];

	printf("set_matrix()\n");
	set_def(len, matrix);
	print(len, matrix);
	if (!backtrack(len, f, matrix))
		set_matrix(len + 1, f);
	print(len, matrix);
}

int		solve(int count, t_figure *f) // Backtracking
{
	int		len = 0;
	printf("COUNT = %d\n", count);

	if (!f)
		return (0);
	len = ft_find_smallest_grid(count);
	/* char	matrix[len][len]; */
	/* set_def(n, matrix); */
	printf("len = %d\n", len);
	printf("solve()\n");
	set_matrix(len, f);
	/* print(len, matrix); */
	return (1);
}

/* int		solve2(int count, t_figure *f, int i, int j, int n, char matrix[n][n]) */
/* { */
/* 	while (i < count) */
/* 	{ */
/* 		while (j <= 3) */
/* 		{ */
/* 			printf("i = %d | j = %d \n", i, j); */
/* 			print(n, matrix); */
			
/* 			printf("figure x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", */
/* 					f[i].x[0], f[i].y[0], f[i].x[1], f[i].y[1], */
/* 					f[i].x[2], f[i].y[2], f[i].x[3], f[i].y[3]); */
/* 			if (ft_issafe(n, matrix, f, i, j)) */
/* 			{ */
/* 				matrix[f[i].y[j]][f[i].x[j]] = alphabet[i]; */
/* 				j++; */
/* 				if (j == 4) */
/* 				{ */
/* 					j = 0; */
/* 					break; */
/* 				} */
/* 			} */
/* 			else */
/* 			{ */
/* 				ft_putstr("Not safe"); */
/* 				printf("i = %d | j = %d\n", i, j); */
/* 				if (!solve2(count, f, i, 0, n , matrix)) */
/* 					mov_y(f, i); */
/* 				return (0); */
/* 			} */
/* 		} */
/* 		printf("i = %d | j = %d\n", i, j); */
/* 		print(n, matrix); */
/* 		i++; */
/* 	} */
/* 	return (1); */
/* } */

/* int		ft_issafe(int n, char matrix[n][n], t_figure *f, int i, int j) */
/* { */
/* 	if (matrix[f[i].x[j]][f[i].y[j]] == '.') */
/* 		return (1); */
/* 		/1* matrix[f[i].x[j]][f[i].y[j]] = alphabet[k]; *1/ */
/* 	return (0); */

/* } */

