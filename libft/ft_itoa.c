/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:04 by kpastukh          #+#    #+#             */
/*   Updated: 2019/09/29 20:31:32 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int len;

	len = 0;
	if (len < 0)
		len++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_isnegative(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char		*ft_itoa(int n)
{
	char	*res_str;
	int		sign;
	int		i;

	i = 0;
	res_str = ft_strnew(ft_numlen(n));
	if (!res_str)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_isnegative(n);
	n *= sign;
	while (n > 0)
	{
		*(res_str + i++) = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		*(res_str + i++) = '-';
	*(res_str + i) = '\0';
	ft_strrev(res_str);
	return (res_str);
}
