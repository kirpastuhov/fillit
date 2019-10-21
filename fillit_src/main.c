/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:43:59 by kpastukh          #+#    #+#             */
/*   Updated: 2019/10/21 15:40:09 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*read_file(char *file)
{
	int		fd;
	char	*str;
	char	*line;

	str = ft_strnew(1);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strjoin(str, ft_strjoin(line, "\n"));
		free(line);
	}
	close(fd);
	return (str);
}

static int	get_countfig(t_figure *figures)
{
	int	i;

	i = 0;
	while (figures[i].name)
		i++;
	return (i);
}

static int	error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int			solve(int count, t_figure *f)
{
	int len;

	if (!f)
		return (0);
	len = ft_find_smallest_grid(count);
	set_matrix(len, f);
	return (1);
}

int			main(int argc, char **argv)
{
	char		*str;
	int			count;
	t_figure	figures[26];

	if (argc != 2)
		return (error());
	str = read_file(argv[1]);
	if (!*str || !parse(str, figures))
		return (error());
	count = get_countfig(figures);
	solve(count, figures);
	return (0);
}
