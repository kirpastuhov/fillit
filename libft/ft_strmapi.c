/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:39:37 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 15:13:42 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (s)
	{
		str = ft_strnew(ft_strlen(s));
		if (!str)
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = f(i, s[i]);
		return (str);
	}
	return (NULL);
}
