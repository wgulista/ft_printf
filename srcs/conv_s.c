/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:54 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:56 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_add_prec_width_str(char **ret, t_env *e)
{
	if (PREC)
		*ret = ft_strndup(*ret, NBPREC);
	if (WIDTH)
	{
		while ((int)ft_strlen(*ret) < NBWIDTH)
		{
			if ((MINUS && ZERO) || MINUS)
				*ret = ft_strjoin_free(*ret, " ", 0);
			else
				*ret = ft_strjoin_free((ZERO ? "0" : " "), *ret, 1);
		}
	}
	return (*ret);
}

void			conv_s(t_env *e)
{
	char		*p;
	char		*str;

	if (L)
		conv_ws(e);
	else
	{
		if (!(str = (char*)va_arg(e->ap, char*)))
			p = ft_strdup("(null)");
		else
			p = ft_strdup(str);
		p = ft_add_prec_width_str(&p, e);
		e->len += ft_strlen(p);
		ft_putstr(p);
		free(p);
	}
}
