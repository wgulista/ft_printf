/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:28 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:30 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_o(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBPREC)
		*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

static char			*set_flags_o(char **ret, intmax_t i, t_env *e)
{
	if (SPACE && !PLUS && i < 0)
		return (*ret);
	else if ((!SHARP && PREC && i == 0) ||
		(!SHARP && PREC && NBPREC == 0 && i == 0))
		return (ft_strdup("\0"));
	else if (SHARP && i > 0)
		return (ft_strjoin_free("0", *ret, 1));
	else if (PLUS && ZERO && NBWIDTH > 0)
		return (ft_strjoin_free("", *ret, 1));
	else if (ZERO && SPACE)
		return (ft_strjoin_free(" ", *ret, 1));
	return (*ret);
}

static uintmax_t	set_size_o(t_env *e)
{
	uintmax_t		nbr;

	if (HH)
		nbr = (unsigned char)va_arg(e->ap, int);
	else if (H)
		nbr = (unsigned short)va_arg(e->ap, int);
	else if (L)
		nbr = (unsigned long)va_arg(e->ap, unsigned long);
	else if (LL)
		nbr = (unsigned long long)va_arg(e->ap, unsigned long);
	else if (J)
		nbr = (intmax_t)va_arg(e->ap, intmax_t);
	else if (Z)
		nbr = (size_t)va_arg(e->ap, size_t);
	else
		nbr = (unsigned long int)va_arg(e->ap, unsigned long int);
	return (nbr);
}

void				conv_o(t_env *e)
{
	char			*p;
	intmax_t		o;

	p = ft_strdup("");
	o = set_size_o(e);
	if (o > 0 && !L && !LL && !Z && !J)
		p = ft_strjoin_free(p, ft_itoa_base_u(o, 8), 0);
	else
		p = ft_strjoin_free(p, ft_itoa_base_l(o, 8), 0);
	p = set_flags_o(&p, o, e);
	if (PREC)
		p = set_prec_o(&p, e);
	if (WIDTH)
		p = set_width(&p, e);
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
}
