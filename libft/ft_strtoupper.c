/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:42:00 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/03 17:31:14 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strtoupper(char *str)
{
	char			*s;
	int				i;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		s[i] = ft_toupper(str[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
