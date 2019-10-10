#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

# define LEN_FIG 4


typedef struct	s_deffig
{
	int count;
	int		x[LEN_FIG];
	int		y[LEN_FIG];
}				t_deffig;

typedef struct s_figure
{
	char	name;
	int		x[LEN_FIG];
	int		y[LEN_FIG];
}				t_figure;

#endif
