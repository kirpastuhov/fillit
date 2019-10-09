/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:40:12 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 15:16:44 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t len)
{
	char			*real_dest;
	unsigned int	counter;

	counter = 0;
	real_dest = dest;
	while (*src && len > counter)
	{
		*dest++ = *src++;
		counter++;
	}
	while (len > counter)
	{
		*dest++ = '\0';
		counter++;
	}
	return (real_dest);
}
