/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:17:36 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:17:41 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_gd(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBPREC)
		*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

static char			*set_width_gd(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBWIDTH - 1)
	{
		if (MINUS || PLUS)
			*ret = ft_strjoin_free(*ret, (ZERO ? "0" : " "), 0);
		else
			*ret = ft_strjoin_free((ZERO ? "0" : " "), *ret, 1);
	}
	return (*ret);
}

void				conv_gd(t_env *e)
{
	char			*p;
	char			*itoa;
	long			gd;

	gd = va_arg(e->ap, long);
	itoa = ft_strdup(ft_itoa_l(gd));
	itoa = ft_strsub(itoa, 1, ft_strlen(itoa) - 1);
	p = (gd < 0 && WIDTH) ? ft_strdup(itoa) : ft_strdup(ft_itoa_l(gd));
	p = set_flags(&p, gd, e);
	if (PREC)
		p = set_prec_gd(&p, e);
	if (WIDTH)
		p = set_width_gd(&p, e);
	if (gd < 0 && NBWIDTH > 0)
		p[0] = '-';
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
	free(itoa);
}
