/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:32:05 by mostrovs          #+#    #+#             */
/*   Updated: 2019/10/16 11:53:25 by mostrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  check_nl(const char *s, int i)
{
    if (!IS_END_LINE(i) || !IS_END_BLOCK(i))
    {
        if (s[i] != '\n') {
            printf("check_nl %d\n", i);
            return (0);
        }
    }
    return (1);
}

static int	check_cells(const char *str)
{
    int	i;
    int count_hash;
    int count_point;

    i = 0;
    count_hash = 0;
    count_point = 0;
    while (str[i] && i < BLOCK)
    {
        if (str[i] == '#')
            count_hash++;
        if (str[i] == '.')
            count_point++;
        i++;
    }
    if (count_hash == 4 && count_point == 12)
        return (1);
    printf("check_cells %d-%d\n", count_hash, count_point);
    return (0);
}

int     check_find_fig(const char *str, int offset, t_deffig *def)
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
            if (pos >= END_POS(offset) || str[pos] != '#')
                break ;
            i++;
        }
        if (i == LEN_FIG)
            return (j);
        j++;
    }
    printf("check_fig\n");
    return (-1);
}

int		check_file(char *str, t_deffig *def)
{
	int	i;

	i = 0;
    while (str[i])
    {
        if (!check_nl(str, i))
            return (0);
        if (!check_cells(&str[START_POS(i)]))
            return (0);
        if (str[i] == '#')
        {
            if (check_find_fig(str, i, def) == -1)
                return (0);
            i = BLOCK - i % BLOCK + i;
        }
        else
            i++;
    }
	return (1);
}