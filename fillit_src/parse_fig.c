/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/18 15:40:18 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_ff(t_deffig *f, const int *x, const int *y, int p)
{
	int i;

	i = -1;
	while (++i < LEN_FIG)
	{
		f[p].x[i] = x[i];
		f[p].y[i] = y[i];
	}
}

static void	ft_filldeffigs(t_deffig *f)
{
	ft_ff(f, (int[LEN_FIG]){0, 0, 0, 0}, (int[LEN_FIG]){0, 1, 2, 3}, 0);
	ft_ff(f, (int[LEN_FIG]){0, 1, 2, 3}, (int[LEN_FIG]){0, 0, 0, 0}, 1);
	ft_ff(f, (int[LEN_FIG]){0, 1, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 2);
	ft_ff(f, (int[LEN_FIG]){0, 1, 0, 0}, (int[LEN_FIG]){0, 0, 1, 2}, 3);
	ft_ff(f, (int[LEN_FIG]){0, 0, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 4);
	ft_ff(f, (int[LEN_FIG]){1, 1, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 5);
	ft_ff(f, (int[LEN_FIG]){0, 1, 1, 1}, (int[LEN_FIG]){0, 0, 1, 2}, 6);
	ft_ff(f, (int[LEN_FIG]){0, 1, 2, 2}, (int[LEN_FIG]){0, 0, 0, 1}, 7);
	ft_ff(f, (int[LEN_FIG]){0, 1, 2, 0}, (int[LEN_FIG]){0, 0, 0, 1}, 8);
	ft_ff(f, (int[LEN_FIG]){0, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 9);
	ft_ff(f, (int[LEN_FIG]){2, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 10);
	ft_ff(f, (int[LEN_FIG]){1, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 11);
	ft_ff(f, (int[LEN_FIG]){0, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 12);
	ft_ff(f, (int[LEN_FIG]){0, 1, 1, 2}, (int[LEN_FIG]){0, 0, 1, 1}, 13);
	ft_ff(f, (int[LEN_FIG]){1, 2, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 14);
	ft_ff(f, (int[LEN_FIG]){1, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 15);
	ft_ff(f, (int[LEN_FIG]){0, 1, 2, 1}, (int[LEN_FIG]){0, 0, 0, 1}, 16);
	ft_ff(f, (int[LEN_FIG]){0, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 17);
	ft_ff(f, (int[LEN_FIG]){1, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 18);
}

static void	ft_fillfigs(t_figure *f, t_deffig df, int p)
{
	int	i;

	f[p].name = p + 'A';
	f[p].offset = df.x[0];
	i = -1;
	while (++i < LEN_FIG)
	{
		f[p].x[i] = df.x[i];
		f[p].y[i] = df.y[i];
	}
}

int			parse(char *str, t_figure *f)
{
	int			i;
	int			k;
	int			res;
	t_deffig	df[19];

	if (!str)
		return (0);
	ft_filldeffigs(df);
	if (!check_file(str, df))
		return (0);
	i = 0;
	k = -1;
	while (str[i])
	{
		if (str[i] == '#')
		{
			res = check_find_fig(str, i, df);
			ft_fillfigs(f, df[res], ++k);
			i = BLOCK - i % BLOCK + i;
		}
		else
			i++;
	}
	return (1);
}
