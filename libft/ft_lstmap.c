/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:58:53 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/19 22:50:51 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *lststart;

	tmp = f(lst);
	lststart = tmp;
	if (!lststart)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (lststart);
}
