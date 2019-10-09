/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:16 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/17 14:04:25 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t size)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	unsigned char	uc_c;
	int				i;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	uc_c = (unsigned char)c;
	i = 0;
	while (size--)
	{
		uc_dst[i] = uc_src[i];
		if (uc_c == uc_dst[i])
			return (&uc_dst[i + 1]);
		i++;
	}
	return (NULL);
}
