#include "fillit.h"

void	set_def(char matrix[][LEN_FIG + 1])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (matrix[i][j])
	{
		matrix[i][j] = '.';
		i++;
		j++;
	}
}

//int		check_move(char matrix[][LEN_FIG + 1], t_figure *f)

//void	print(char matrix[][LEN_FIG + 1])

int		solve(int count, t_figure *f) // Backtracking
{
	char	matrix[count][LEN_FIG + 1];

	if (!f)
		return (0);
	set_def(matrix);
	return (1);
}
