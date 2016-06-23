/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:04:19 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/31 13:43:55 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_len(long long n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int		ft_issign(long long n)
{
	return (n < 0);
}

char			*ft_itoa_l(long long n)
{
	size_t	i;
	size_t	sign;
	char	*new;

	sign = ft_issign(n);
	i = ft_len(n);
	new = ft_strnew(sign + i);
	if (n <= -9223372036854775807)
		return (ft_strcpy(new, "-9223372036854775808"));
	if (sign)
		n *= -1;
	if (new)
	{
		if (n == 0)
			new[0] = '0';
		while (n)
		{
			new[--i + sign] = (n % 10) + 48;
			n /= 10;
		}
		if (sign)
			new[0] = '-';
	}
	return (new);
}
