/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:17:59 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:01 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_go(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBPREC)
		*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

static char			*set_flags_go(char **ret, intmax_t i, t_env *e)
{
	if (SPACE && !PLUS && i < 0)
		return (*ret);
	else if (!SHARP && ((PREC && i == 0) || (PREC && NBPREC == 0 && i == 0)))
		return (ft_strdup("\0"));
	else if (SHARP && i > 0)
		return (ft_strjoin_free("0", *ret, 1));
	else if (PLUS && ZERO && NBWIDTH > 0)
		return (ft_strjoin_free("", *ret, 1));
	else if (ZERO && SPACE)
		return (ft_strjoin_free(" ", *ret, 1));
	return (*ret);
}

void				conv_go(t_env *e)
{
	char			*p;
	uintmax_t		go;

	p = ft_strdup("");
	go = (uintmax_t)va_arg(e->ap, unsigned long);
	p = ft_strjoin_free(p, ft_itoa_base_lu(go, 8), 0);
	p = set_flags_go(&p, go, e);
	if (PREC)
		p = set_prec_go(&p, e);
	if (WIDTH)
		p = set_width(&p, e);
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
}
