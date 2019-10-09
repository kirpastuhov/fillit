/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:25 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/19 19:02:44 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *uc_s;
	unsigned char uc_c;

	uc_s = (unsigned char *)s;
	uc_c = (unsigned char)c;
	while (n--)
	{
		if (*uc_s == uc_c)
			return (uc_s);
		uc_s++;
	}
	return (NULL);
}
