/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:52:18 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/19 22:55:27 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		ft_putstr(" ──> ");
		list = list->next;
	}
	ft_putstr("NULL");
}
