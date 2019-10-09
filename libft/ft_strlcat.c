/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:38:52 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/21 08:28:10 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = ft_strlen(dst);
	len = ft_strlen(src);
	if (size < i)
		len += size;
	else
		len += i;
	while (*src && i + 1 < size)
		*(dst + i++) = *src++;
	*(dst + i) = '\0';
	return (len);
}
