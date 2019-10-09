/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:41:39 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/18 22:54:15 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*res_str;

	start = 0;
	end = 0;
	res_str = NULL;
	if (s)
	{
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		if (s[start] == '\0')
			return (ft_strnew(1));
		end = (unsigned int)ft_strlen(s) - 1;
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		if (!(res_str = ft_strsub(s, start, (end - start + 1))))
			return (NULL);
	}
	return (res_str);
}
