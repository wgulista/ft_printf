/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:19 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:20 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_x(char **ret, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBPREC)
		*ret = ft_strjoin_free("0", *ret, 1);
	if (SHARP && PREC && NBPREC != 0)
		*ret = ft_strjoin_free("0x", *ret, 1);
	return (*ret);
}

static char			*set_width_x2(char **ret, t_env *e)
{
	if (MINUS && ZERO)
	{
		NBWIDTH = NBWIDTH - (int)ft_strlen(*ret);
		while ((int)ft_strlen(*ret) < NBWIDTH)
			*ret = ft_strjoin_free(*ret, " ", 0);
	}
	if (MINUS && !WIDTH && !SHARP)
		*ret = ft_strjoin_free("0x", *ret, 1);
	if (MINUS && ZERO && WIDTH)
		*ret = ft_strjoin_free("0x", *ret, 1);
	return (*ret);
}

static char			*set_width_x(char **ret, t_env *e)
{
	if (SHARP && !MINUS && ZERO && WIDTH)
	{
		NBWIDTH = NBWIDTH - (int)ft_strlen(*ret) - 2;
		*ret = ft_strjoin_free(ft_putnchar('0', NBWIDTH), *ret, 1);
		*ret = ft_strjoin_free("0x", *ret, 1);
	}
	if (!MINUS)
		while ((int)ft_strlen(*ret) < NBWIDTH)
			*ret = ft_strjoin_free((ZERO ? "0" : " "), *ret, 1);
	if (MINUS && !ZERO)
		while ((int)ft_strlen(*ret) < NBWIDTH)
			*ret = ft_strjoin_free(*ret, " ", 0);
	*ret = set_width_x2(ret, e);
	return (*ret);
}

static uintmax_t	set_size_x(t_env *e)
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

void				conv_x(t_env *e)
{
	char			*p;
	intmax_t		x;

	p = ft_strdup("");
	x = set_size_x(e);
	if (x > 0 && !L && !LL && !Z && !J)
		p = ft_strjoin_free(p, ft_itoa_base_u(x, 16), 0);
	else
		p = ft_strjoin_free(p, ft_itoa_base_l(x, 16), 0);
	if ((PREC && x == 0) || (PREC && NBPREC == 0 && x == 0))
		p = ft_strdup("\0");
	if (SHARP && !ZERO && !PREC && x > 0)
		p = ft_strjoin_free("0x", p, 1);
	if (PREC)
		p = set_prec_x(&p, e);
	if (WIDTH)
		p = set_width_x(&p, e);
	if (SHARP && ZERO && PREC && NBPREC > 0)
		p = ft_strjoin_free("0x", p, 1);
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
}
