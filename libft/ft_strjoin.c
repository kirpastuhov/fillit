/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:38:48 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 15:00:51 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cursor;
	char	*res_str;

	if (s1 && s2)
	{
		cursor = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!cursor)
			return (NULL);
		res_str = cursor;
		while (*s1)
			*cursor++ = *s1++;
		while (*s2)
			*cursor++ = *s2++;
		return (res_str);
	}
	return (NULL);
}
