/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:49 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 14:37:57 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (!dst && !src)
		return (NULL);
	i = -1;
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (uc_src < uc_dst)
		while (len--)
			uc_dst[len] = uc_src[len];
	else
		while (++i < len)
			uc_dst[i] = uc_src[i];
	return (uc_dst);
}
