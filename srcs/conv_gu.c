/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:02 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:04 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_gu(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBPREC)
		*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

void				conv_gu(t_env *e)
{
	char			*p;
	uintmax_t		gu;

	p = ft_strdup("");
	gu = (uintmax_t)va_arg(e->ap, unsigned long);
	p = set_flags(&p, gu, e);
	p = ft_strjoin_free(p, ft_itoa_base_lu(gu, 10), 0);
	if ((PREC && gu == 0) || (PREC && NBPREC == 0 && gu == 0))
		p = ft_strdup("\0");
	if (PREC)
		p = set_prec_gu(&p, e);
	if (WIDTH)
		p = set_width(&p, e);
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
}
