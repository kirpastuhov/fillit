/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:43:59 by kpastukh          #+#    #+#             */
/*   Updated: 2019/10/10 11:47:27 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	read_file(char *file, char **str)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		*str = ft_strjoin(*str, ft_strjoin(line, "\n"));
		free(line);
	}
	close(fd);
}

int		get_count(t_figure *figures)
{
	int	i;

	i = 0;
	while (figures[i].name)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		count;
	t_figure figures[26];
	

	str = ft_strnew(1);
	if (argc != 2)
		return (0);

	read_file(argv[1], &str);
	printf("%s\n", str);
	parse(str, figures);
	count = get_count(figures);
	printf("count of t_figure = %d\n", count);
	solve(count, figures);
	return (0);
}

		/* call check for valid figure function */
		/* if valid */
			/* save data to array of figures */
				/* find smallest possible size of the grid and create matrix */
				/* backtracking with this matrix  (check matrix borders and figure borders) */
				/* if fail */
					/* matrix_size + 1 and backtracking one more time */
		/* else */
			/* show error */
