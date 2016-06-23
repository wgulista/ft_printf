/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:18:40 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/03 14:56:11 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strcase(char *str, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (str == NULL || c == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}
