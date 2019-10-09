/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:35:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/18 22:44:40 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		new_node->content = malloc(content_size);
		if (new_node->content == NULL)
			return (NULL);
		ft_memcpy(new_node->content, content, content_size);
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	return (new_node);
}
