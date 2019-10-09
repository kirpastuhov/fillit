/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:36 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 15:53:30 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char *uc_dst;
	unsigned char *uc_src;

	if (!dst && !src)
		return (NULL);
	if (size)
	{
		uc_dst = (unsigned char *)dst;
		uc_src = (unsigned char *)src;
		while (size--)
			*uc_dst++ = *uc_src++;
	}
	return (dst);
}
