/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:04:19 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/31 13:43:55 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long	base_x(uintptr_t nbr)
{
	unsigned long				temp;

	temp = 0;
	if (10 <= nbr && nbr <= 16)
		temp = nbr + ('a' - 10);
	else if (nbr <= 9)
		temp = nbr + 48;
	return (temp);
}

static int				ft_len(uintptr_t n, int base)
{
	int					i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char					*ft_itoa_base(uintptr_t nbr, int base)
{
	uintptr_t			i;
	char				*new;

	i = ft_len(nbr, base);
	new = ft_strnew(i);
	if (new)
	{
		if (nbr == 0)
			new[0] = '0';
		while (nbr)
		{
			new[--i] = base_x(nbr % base);
			nbr /= base;
		}
	}
	return (new);
}
