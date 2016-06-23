/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:28:14 by wgulista          #+#    #+#             */
/*   Updated: 2016/05/17 12:30:32 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_putnchar(char c, int nb)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_strnew(nb);
	while (i < nb)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
