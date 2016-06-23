/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:20:11 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:20:12 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_char(char c, char *check)
{
	int		i;

	i = 0;
	if (check)
	{
		while (check[i])
		{
			if (c == check[i])
				return (1);
			i++;
		}
	}
	return (0);
}
