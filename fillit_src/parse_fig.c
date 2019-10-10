/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/10 10:32:07 by mostrovs         ###   ########.fr       */
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

void	parse(char *str)
{
	t_deffig 	default_figures[19];
	
	if (!str)
		return ;
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 0, 0}, (int[4]){0, 1, 2, 3}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 3}, (int[4]){0, 0, 0, 0}, 1);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 0, 1}, (int[4]){0, 0, 1, 1}, 2);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 0, 0}, (int[4]){0, 0, 1, 2}, 3);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 0, 1}, (int[4]){0, 1, 2, 2}, 4);
	ft_filldefaultfig(default_figures, (int[4]){1, 1, 0, 1}, (int[4]){0, 1, 2, 2}, 5);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 1, 1}, (int[4]){0, 0, 1, 2}, 6);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 2}, (int[4]){0, 0, 0, 1}, 7);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 0}, (int[4]){0, 0, 0, 1}, 8);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 1, 2}, (int[4]){0, 1, 1, 1}, 9);
	ft_filldefaultfig(default_figures, (int[4]){2, 0, 1, 2}, (int[4]){0, 1, 1, 1}, 10);
	ft_filldefaultfig(default_figures, (int[4]){1, 0, 1, 0}, (int[4]){0, 1, 1, 2}, 11);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 1, 1}, (int[4]){0, 1, 1, 2}, 12);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 1, 2}, (int[4]){0, 0, 1, 1}, 13);
	ft_filldefaultfig(default_figures, (int[4]){1, 2, 0, 1}, (int[4]){0, 0, 1, 1}, 14);
	ft_filldefaultfig(default_figures, (int[4]){1, 0, 1, 2}, (int[4]){0, 1, 1, 1}, 15);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 1}, (int[4]){0, 0, 0, 1}, 16);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 1, 0}, (int[4]){0, 1, 1, 2}, 17);
	ft_filldefaultfig(default_figures, (int[4]){1, 0, 1, 1}, (int[4]){0, 1, 1, 2}, 18);

	// arr[i].y[] * (LEN_FIG + 1) + arr[i].x[] + start_position
	for (int i = 0; i < 19; i++)
		printf("x[1]=%d, y[1]=%d, x[2]=%d, y[2]=%d, x[3]=%d, y[3]=%d, x[4]=%d, y[4]=%d\n", 
			default_figures[i].x[0], default_figures[i].y[0], default_figures[i].x[1], default_figures[i].y[1],
			default_figures[i].x[2], default_figures[i].y[2], default_figures[i].x[3], default_figures[i].y[3]);
}
