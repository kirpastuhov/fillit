/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:40:58 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/21 11:18:33 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char *end;
	char c;

	end = str + ft_strlen(str) - 1;
	while (str < end)
	{
		c = *str;
		*str++ = *end;
		*end-- = c;
	}
}