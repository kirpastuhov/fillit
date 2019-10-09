/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 08:42:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/21 11:15:21 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **begin_list, t_list *new_node)
{
	t_list *cursor;

	cursor = *begin_list;
	if (!begin_list)
	{
		*begin_list = new_node;
		return ;
	}
	else
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new_node;
	}
}
