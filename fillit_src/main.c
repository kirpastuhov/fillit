/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:43:59 by kpastukh          #+#    #+#             */
/*   Updated: 2019/10/09 16:03:25 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_filldefaultfig(t_deffig *arr, int *x, int *y, int i)
{
	int count = 0;

	arr[i].count = 0;
	while (count < LEN_FIG)
	{
		arr[i].x[count] = x[count];
		arr[i].y[count] = y[count];
		count++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*str;
	t_deffig default_figures[19];
	
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 0, 0}, (int[4]){0, 1, 2, 3}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 3}, (int[4]){0, 0, 0, 0}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 0, 1}, (int[4]){0, 0, 1, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 0, 0}, (int[4]){0, 0, 1, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 0, 1}, (int[4]){0, 1, 2, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){1, 1, 0, 1}, (int[4]){0, 1, 2, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 1, 1}, (int[4]){0, 0, 1, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 2}, (int[4]){0, 0, 0, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 0}, (int[4]){0, 0, 0, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 1, 2}, (int[4]){0, 1, 1, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){2, 0, 1, 2}, (int[4]){0, 1, 1, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){1, 0, 1, 0}, (int[4]){0, 1, 1, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 1, 1}, (int[4]){0, 1, 1, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 1, 2}, (int[4]){0, 0, 1, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){1, 2, 0, 1}, (int[4]){0, 0, 1, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){1, 0, 1, 2}, (int[4]){0, 1, 1, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 1, 2, 1}, (int[4]){0, 0, 0, 1}, 0);
	ft_filldefaultfig(default_figures, (int[4]){0, 0, 1, 0}, (int[4]){0, 1, 1, 2}, 0);
	ft_filldefaultfig(default_figures, (int[4]){1, 0, 1, 1}, (int[4]){0, 1, 1, 2}, 0);

	printf("count = %d, x[1] = %d, y[1] = %d, x[2] = %d, y[2] = %d, x[3] = %d, y[3] = %d, x[4] = %d, y[4] = %d", default_figures[0].count, default_figures[0].x[0], default_figures[0].y[0] , default_figures[0].x[1], default_figures[0].y[1]  , default_figures[0].x[2], default_figures[0].y[2]  , default_figures[0].x[3], default_figures[0].y[3]);  

	str = ft_strnew(1);
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		/* call check for valid figure function */
		/* if valid */
			/* save data to array of figures */
				/* find smallest possible size of the grid and create matrix */
				/* backtracking with this matrix  (check matrix borders and figure borders) */
				/* if fail */
					/* matrix_size + 1 and backtracking one more time */
		/* else */
			/* show error */
		str = ft_strjoin(str, ft_strjoin(line, "\n"));
		free(line);
	}
	ft_putstr(str);
	if (argc == 2)
		close(fd);
}

