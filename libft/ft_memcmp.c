/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:31 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/21 20:33:27 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *uc_s1;
	unsigned char *uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	while ((n > 0) && (*uc_s1 == *uc_s2))
	{
		uc_s1++;
		uc_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*uc_s1 - *uc_s2);
}
