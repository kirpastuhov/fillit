/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:28:57 by kpastukh          #+#    #+#             */
/*   Updated: 2019/10/08 18:22:34 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_checkline(char **stack, int fd)
{
	int		len;
	char	*tmp;
	char	*new_str;

	len = 0;
	while (stack[fd][len] != '\n' && stack[fd][len] != '\0')
		len++;
	if (stack[fd][len] == '\n')
	{
		new_str = ft_strsub(stack[fd], 0, len);
		tmp = ft_strdup(&stack[fd][len + 1]);
		free(stack[fd]);
		stack[fd] = tmp;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else
	{
		new_str = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (new_str);
}

void		ft_updstack(char **stack, char *buff, int fd)
{
	char *tmp;

	tmp = ft_strjoin(stack[fd], buff);
	free(stack[fd]);
	stack[fd] = tmp;
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*stack[MAX_FD];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strdup(buff);
		else
			ft_updstack(stack, buff, fd);
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && stack[fd] == NULL)
		return (0);
	*line = ft_checkline(stack, fd);
	return (1);
}
