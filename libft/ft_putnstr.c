/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 19:26:05 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/10 19:26:06 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_putnstr(const char *str, size_t n)
{
	size_t			len;
	char			*p;

	if (str != NULL)
	{
		p = ft_strnew(n);
		len = ft_strlen(str);
		len = (len < n) ? len : n;
		ft_strncpy(p, str, len);
		return (p);
	}
	return (NULL);
}
