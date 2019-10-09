/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:40:45 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/18 16:36:09 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	int		j;
	size_t	n;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (*(str + i) && len)
	{
		j = 0;
		n = len;
		while (*(str + i + j) && *(str + i + j) == *(to_find + j))
		{
			if (!n)
				break ;
			if (!*(to_find + j + 1))
				return ((char *)(str + i));
			j++;
			n--;
		}
		i++;
		len--;
	}
	return (0);
}
