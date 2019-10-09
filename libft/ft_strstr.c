/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:41:19 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/18 15:57:07 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int j;

	j = 0;
	if (!*to_find)
		return ((char *)str);
	while (*str)
	{
		j = 0;
		while (*(to_find + j))
		{
			if (*(str + j) != to_find[j])
				break ;
			j++;
		}
		if (!*(to_find + j))
			return ((char *)str);
		str++;
	}
	return (0);
}
