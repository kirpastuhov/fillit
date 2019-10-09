/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:14:24 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/21 11:17:24 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		if ((*cmp)(list_ptr->content, data_ref) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (0);
}
