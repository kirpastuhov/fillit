/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:54 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/17 14:05:08 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *unsigned_b;

	unsigned_b = (unsigned char *)b;
	while (len--)
		*unsigned_b++ = (unsigned char)c;
	return (b);
}
