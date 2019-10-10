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

void	read_file(char *file, char *str)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strjoin(str, ft_strjoin(line, "\n"));
		free(line);
	}
	ft_putstr(str);
	close(fd);
}

int		main(int argc, char **argv)
{
	char	*str;

	str = ft_strnew(1);
	if (argc != 2)
		return (0);
	read_file(argv[1], str);
	parse(str);
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
