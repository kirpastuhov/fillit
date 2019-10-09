/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:41:34 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/20 15:23:53 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res_str;

	res_str = NULL;
	if (s)
	{
		res_str = ft_strnew(len);
		if (!res_str)
			return (NULL);
		ft_strncpy(res_str, s + start, len);
		res_str[len] = '\0';
	}
	return (res_str);
}
