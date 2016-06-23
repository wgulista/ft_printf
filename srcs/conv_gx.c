/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:06 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:07 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_gx(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBPREC)
		*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

static uintmax_t	set_size_gx(t_env *e)
{
	uintmax_t		nbr;

	if (HH)
		nbr = (unsigned char)va_arg(e->ap, unsigned int);
	else if (H)
		nbr = (unsigned short)va_arg(e->ap, unsigned int);
	else if (L)
		nbr = (unsigned long)va_arg(e->ap, unsigned long);
	else if (LL)
		nbr = (unsigned long long)va_arg(e->ap, unsigned long);
	else if (J)
		nbr = (uintmax_t)va_arg(e->ap, uintmax_t);
	else if (Z)
		nbr = (size_t)va_arg(e->ap, size_t);
	else
		nbr = (unsigned int)va_arg(e->ap, unsigned int);
	return (nbr);
}

void				conv_gx(t_env *e)
{
	char			*p;
	intmax_t		gx;

	p = ft_strdup("");
	gx = set_size_gx(e);
	if (gx < 0)
		p = ft_strjoin_free(p, ft_itoa_base(gx, 16), 0);
	else if (gx == 4294967296 && !LL)
		p = ft_strjoin_free(p, "0", 0);
	else
		p = ft_strjoin_free(p, ft_itoa_base_lu(gx, 16), 0);
	if ((PREC && gx == 0) || (PREC && NBPREC == 0 && gx == 0))
		p = ft_strdup("\0");
	if (SHARP && !PREC && gx > 0)
		p = ft_strjoin_free("0X", p, 1);
	if (PREC)
		p = set_prec_gx(&p, e);
	if (WIDTH)
		p = set_width(&p, e);
	e->len += ft_strlen(p);
	p = ft_strtoupper(p);
	ft_putstr(p);
	free(p);
}
