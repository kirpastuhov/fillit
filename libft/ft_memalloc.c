/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/19 15:24:37 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *ptr;

	ptr = NULL;
	if (size)
	{
		ptr = (unsigned char *)malloc(size);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, size);
	}
	return ((void *)ptr);
}
