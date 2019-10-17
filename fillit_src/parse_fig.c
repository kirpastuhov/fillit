/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/16 11:53:25 by mostrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_filldeffig(t_deffig *f, const int *x, const int *y, int p)
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
    ft_filldeffig(f, (int[LEN_FIG]){0, 0, 0, 0}, (int[LEN_FIG]){0, 1, 2, 3}, 0);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 2, 3}, (int[LEN_FIG]){0, 0, 0, 0}, 1);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 2);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 0, 0}, (int[LEN_FIG]){0, 0, 1, 2}, 3);
    ft_filldeffig(f, (int[LEN_FIG]){0, 0, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 4);
    ft_filldeffig(f, (int[LEN_FIG]){1, 1, 0, 1}, (int[LEN_FIG]){0, 1, 2, 2}, 5);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 1, 1}, (int[LEN_FIG]){0, 0, 1, 2}, 6);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 2, 2}, (int[LEN_FIG]){0, 0, 0, 1}, 7);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 2, 0}, (int[LEN_FIG]){0, 0, 0, 1}, 8);
    ft_filldeffig(f, (int[LEN_FIG]){0, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 9);
    ft_filldeffig(f, (int[LEN_FIG]){2, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 10);
    ft_filldeffig(f, (int[LEN_FIG]){1, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 11);
    ft_filldeffig(f, (int[LEN_FIG]){0, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 12);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 1, 2}, (int[LEN_FIG]){0, 0, 1, 1}, 13);
    ft_filldeffig(f, (int[LEN_FIG]){1, 2, 0, 1}, (int[LEN_FIG]){0, 0, 1, 1}, 14);
    ft_filldeffig(f, (int[LEN_FIG]){1, 0, 1, 2}, (int[LEN_FIG]){0, 1, 1, 1}, 15);
    ft_filldeffig(f, (int[LEN_FIG]){0, 1, 2, 1}, (int[LEN_FIG]){0, 0, 0, 1}, 16);
    ft_filldeffig(f, (int[LEN_FIG]){0, 0, 1, 0}, (int[LEN_FIG]){0, 1, 1, 2}, 17);
    ft_filldeffig(f, (int[LEN_FIG]){1, 0, 1, 1}, (int[LEN_FIG]){0, 1, 1, 2}, 18);
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
            //printf("fill k = %d: deffig = %d, name = %c, (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", k-1, res, f[k-1].name, f[k-1].x[0], f[k-1].y[0], f[k-1].x[1], f[k-1].y[1], f[k-1].x[2], f[k-1].y[2], f[k-1].x[3], f[k-1].y[3]);
		}
		else
			i++;
	}
	return (1);
}
