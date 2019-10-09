/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:39:25 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 15:12:42 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	str = NULL;
	if (s)
	{
		str = ft_strnew(ft_strlen(s));
		if (!str)
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = f(s[i]);
		return (str);
	}
	return (NULL);
}
