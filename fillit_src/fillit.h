#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>

# define LEN_FIG 4
# define FIG_AMT 19
# define BLOCK 21


typedef struct	s_deffig
{
	int		x[LEN_FIG];
	int		y[LEN_FIG];
}				t_deffig;

typedef struct s_figure
{
	char	name;
	int		offset;
	int		x[LEN_FIG];
	int		y[LEN_FIG];
}				t_figure;

int		parse(char *s, t_figure *figure);

#endif
