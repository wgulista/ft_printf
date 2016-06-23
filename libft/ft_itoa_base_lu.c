/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:18:31 by wgulista          #+#    #+#             */
/*   Updated: 2015/11/30 17:16:15 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long	base_x(unsigned long nbr)
{
	unsigned long		temp;

	temp = 0;
	if (10 <= nbr && nbr <= 16)
		temp = nbr + ('a' - 10);
	else if (nbr <= 9)
		temp = nbr + 48;
	return (temp);
}

static int				ft_len(unsigned long int n, int base)
{
	int					i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char					*ft_itoa_base_lu(unsigned long int nbr, int base)
{
	unsigned long int	i;
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
