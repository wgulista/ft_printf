/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:20:19 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:20:21 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		non_conv(t_env *e)
{
	char		*p;

	p = ft_strnew(1);
	p[0] = *(e->s);
	if (p == 0)
		p = ft_strdup("\0");
	if (PREC && NBPREC != 0)
		p = ft_strndup(p, NBPREC);
	if (WIDTH)
	{
		while ((int)ft_strlen(p) < NBWIDTH)
		{
			if (MINUS && ZERO)
				p = ft_strjoin_free(p, " ", 0);
			else if (MINUS)
				p = ft_strjoin_free(p, " ", 0);
			else
				p = ft_strjoin_free((ZERO ? "0" : " "), p, 1);
		}
	}
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
}
