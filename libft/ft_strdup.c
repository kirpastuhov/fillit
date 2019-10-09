/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:37:56 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/19 19:08:18 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (0);
	return (ft_strcpy(dest, s1));
}
