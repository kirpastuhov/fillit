/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/10 11:53:25 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_filldefaultfig(t_deffig *arr, int *x, int *y, int i)
{
	int count = 0;

	while (count < LEN_FIG)
	{
		arr[i].x[count] = x[count];
		arr[i].y[count] = y[count];
		count++;
	}
		printf("arr: i=%d, x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", i,
			arr[i].x[0], arr[i].y[0], arr[i].x[1], arr[i].y[1],
			arr[i].x[2], arr[i].y[2], arr[i].x[3], arr[i].y[3]);
}

void	ft_filldefaultfigs(t_deffig *arr)
{
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 0, 0, 0}, (int[LEN_FIG]){0, 1, 2, 3}, 0);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 2, 3}, (int[LEN_FIG]){0, 0, 0, 0}, 1);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 2);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 0, 0}, (int[LEN_FIG]){0, 0, 1, 2}, 3);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 0, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 4);
	ft_filldefaultfig(arr, (int[LEN_FIG]){1, 1, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 5);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 1, 1}, (int[LEN_FIG]){0, 0, 1, 2}, 6);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 2, 2}, (int[LEN_FIG]){0, 0, 0, 1}, 7);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 2, 0}, (int[LEN_FIG]){0, 0, 0, 1}, 8);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 9);
	ft_filldefaultfig(arr, (int[LEN_FIG]){2, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 10);
	ft_filldefaultfig(arr, (int[LEN_FIG]){1, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 11);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 12);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 1, 2}, (int[LEN_FIG]){0, 0, 1, 1}, 13);
	ft_filldefaultfig(arr, (int[LEN_FIG]){1, 2, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 14);
	ft_filldefaultfig(arr, (int[LEN_FIG]){1, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 15);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 1, 2, 1}, (int[LEN_FIG]){0, 0, 0, 1}, 16);
	ft_filldefaultfig(arr, (int[LEN_FIG]){0, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 17);
	ft_filldefaultfig(arr, (int[LEN_FIG]){1, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 18);
}

int check_fig(char *str, int offset, t_deffig *def)
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
			pos = def[j].y[i] * (LEN_FIG + 1) + def[j].x[i] + offset - def[j].x[0];
			if (str[pos] != '#')
				break ;
			i++;
		}
		if (i == LEN_FIG)
			return (j);
		j++;
	}
	return (0);
}

void	ft_fillfigs(t_figure *figures, t_deffig default_figures, int n)
{
	int	i;

	i = 0;
	figures[n].name = n + '0';
	figures[n].offset = default_figures.x[0];
	while (i < LEN_FIG)
	{
		figures[n].x[i] = default_figures.x[i];
		figures[n].y[i] = default_figures.y[i];
		i++;
	}
}

int	checkch(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && i < BLOCK)
	{
		if (str[i] == '#')
			count++;
		i++;
	}
	if (count == 4)
		return (count);
	return (0);
}

int	parse(char *str, t_figure *figures)
{
	int			i;
	int			j;
	int			k;
	int			res;
	t_deffig	default_figures[19];
	
	if (!str)
		return (-1);
	ft_filldefaultfigs(default_figures);
	k = 0;
	i = 0;
	while (str[i])
	{
		if (((i + 1) % (LEN_FIG + 1) - (i / BLOCK) % (LEN_FIG + 1) == 0) || (i % BLOCK == BLOCK - 1))
		{
			if (str[i] != '\n')
				return (-1);
		}
		else if (str[i] != '#' && str[i] != '.')
			return (-1);
		if (str[i] == '#')
		{
			j = 0;
			while (j <= FIG_AMT)
			{
				if ((res = check_fig(str, i, default_figures)))
					break ;
				j++;
			}
			if (res == -1)
				return (-1);
			if (!checkch(&str[BLOCK * (i / BLOCK)]))
			{
				printf("if (!checkch(&str[BLOCK * (i / BLOCK)]))\n");
				return (-1);
			}
			ft_fillfigs(figures, default_figures[res], k);
			k++;
			printf("ft_fillfigs: k=%d, res=%d, x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", k-1, res,
					figures[k-1].x[0], figures[k-1].y[0], figures[k-1].x[1], figures[k-1].y[1],
					figures[k-1].x[2], figures[k-1].y[2], figures[k-1].x[3], figures[k-1].y[3]);
			i = BLOCK - i % BLOCK + i; 
		}
		else
			i++;
	}

	return (1);
}
