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
}

int check_fig(char *str, int offset, t_deffig *def)
{
	int i = 1;
	int j = 0;
	int pos;
	while (j < FIG_AMT)
	{
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
	int i = 0;
	figures[n].name = n + '0';
	figures[n].offset = default_figures.x[0];
	while (i < LEN_FIG)
	{
		figures[n].x[i] = default_figures.x[i];
		figures[n].y[i] = default_figures.y[i];
		i++;
	}
}

int	parse(char *str, t_figure *figures)
{
	t_deffig 	default_figures[19];
	int i = 0;
	int j = 0;
	int k = 0;
	int res;
	
	if (!str)
		return (-1);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 0, 0, 0}, (int[LEN_FIG]){0, 1, 2, 3}, 0);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 2, 3}, (int[LEN_FIG]){0, 0, 0, 0}, 1);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 2);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 0, 0}, (int[LEN_FIG]){0, 0, 1, 2}, 3);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 0, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 4);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){1, 1, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 5);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 1, 1}, (int[LEN_FIG]){0, 0, 1, 2}, 6);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 2, 2}, (int[LEN_FIG]){0, 0, 0, 1}, 7);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 2, 0}, (int[LEN_FIG]){0, 0, 0, 1}, 8);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 9);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){2, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 10);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){1, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 11);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 12);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 1, 2}, (int[LEN_FIG]){0, 0, 1, 1}, 13);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){1, 2, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 14);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){1, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 15);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 1, 2, 1}, (int[LEN_FIG]){0, 0, 0, 1}, 16);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){0, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 17);
	ft_filldefaultfig(default_figures, (int[LEN_FIG]){1, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 18);

	// arr[i].y[] * (LEN_FIG + 1) + arr[i].x[] + start_position
	for (i = 0; i < 19; i++)
		printf("x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", 
			default_figures[i].x[0], default_figures[i].y[0], default_figures[i].x[1], default_figures[i].y[1],
			default_figures[i].x[2], default_figures[i].y[2], default_figures[i].x[3], default_figures[i].y[3]);
	i = 0;
	while (str[i])
	{
		if (i % 5 != 4)
			i++;
		else if (i % 5 == 4 && str[i] == '.')
			i++;
		else
		{
			if (str[i] != '#')
				return (-1);
			break ;
		}
	}
	while (j <= FIG_AMT)
	{
		res = check_fig(str, i, default_figures);
		if (res)
			break ;
		j++;
	}
	if (res == -1)
		return (-1);

	// check '.'
	ft_fillfigs(figures, default_figures[res], k++);
	printf("HERERERERE");
	printf("x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", 
			figures[0].x[0], figures[0].y[0], figures[0].x[1], figures[0].y[1],
			figures[0].x[2], figures[0].y[2], figures[0].x[3], figures[0].y[3]);
	return (1);
}
