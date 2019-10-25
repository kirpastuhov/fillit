/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:32:50 by kpastukh          #+#    #+#             */
/*   Updated: 2019/10/25 12:42:01 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>

# define LEN_FIG 4
# define FIG_AMT 19
# define BLOCK 21
# define COUNT_BLOCK(x) ((x + 1) / BLOCK)
# define START_POS(x) (COUNT_BLOCK(x) * BLOCK)
# define END_POS(x) (START_POS(x) + BLOCK)
# define IS_END_LINE(x) ((x + 1) % (LEN_FIG + 1) - (x / BLOCK) % (LEN_FIG + 1))
# define IS_END_BLOCK(x) (x % BLOCK + 1 - BLOCK)
# define IS_FIG(x) (x >= 'A' && x <= 'Z')

typedef struct	s_deffig
{
	int		x[LEN_FIG];
	int		y[LEN_FIG];
}				t_deffig;

typedef struct	s_figure
{
	char	name;
	int		offset;
	int		x[LEN_FIG];
	int		y[LEN_FIG];
}				t_figure;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

int				parse(char *s, t_figure *figure);
int				solve(int count, t_figure *f);
int				check_file(char *str, t_deffig *def);
int				check_find_fig(const char *str, int offset, t_deffig *def);
int				ft_find_smallest_grid(int count);
void			print(int count, char matrix[count][count]);
void			set_fig(int len, t_figure *f, char matrix[len][len]);
void			clean_fig(int len, t_figure *f, char matrix[len][len]);
int				cmp(int *val, int count);
void			set_matrix(int len, t_figure *f);
#endif
