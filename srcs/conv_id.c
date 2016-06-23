/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:19 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:20 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t		set_size_id(t_env *e)
{
	long long int	nbr;

	if (HH)
		nbr = (char)va_arg(e->ap, int);
	else if (H)
		nbr = (short)va_arg(e->ap, int);
	else if (L)
		nbr = va_arg(e->ap, long);
	else if (LL)
		nbr = va_arg(e->ap, long long);
	else if (J)
		nbr = va_arg(e->ap, intmax_t);
	else if (Z)
		nbr = va_arg(e->ap, size_t);
	else
		nbr = va_arg(e->ap, int);
	return (nbr);
}

static char			*set_prec_id(char **r, intmax_t i, t_env *e)
{
	if (i < 0)
		*r = ft_strsub(*r, 1, (int)ft_strlen(*r) - 1);
	while ((int)ft_strlen(*r) < NBPREC)
		*r = ft_strjoin_free("0", *r, 1);
	if (i < 0)
		*r = ft_strjoin_free("-", *r, 1);
	return (*r);
}

static char			*set_width_id2(char **r, intmax_t i, t_env *e)
{
	if (MINUS && PLUS && NBWIDTH > 0 && NBPREC > 0 && i > 0)
	{
		NBWIDTH = NBWIDTH - (int)ft_strlen(*r);
		return (ft_strjoin_free(*r, ft_putnchar(' ', NBWIDTH - 1), 0));
	}
	if (i == 0 && PREC && NBWIDTH > 0 && NBPREC == 0)
		return (ft_strjoin_free(*r, ft_putnchar(' ', NBWIDTH - 1), 0));
	if (!MINUS && PLUS && PREC && WIDTH)
	{
		NBWIDTH = NBWIDTH - (int)ft_strlen(*r);
		*r = (PLUS) ? ft_strjoin_free("+", *r, 1) : *r;
		return (ft_strjoin_free(ft_putnchar(' ', NBWIDTH - 1), *r, 1));
	}
	while ((int)ft_strlen(*r) < NBWIDTH)
	{
		if (ZERO && MINUS)
			*r = ft_strjoin_free(*r, " ", 0);
		else if (MINUS && !SPACE)
			*r = ft_strjoin_free(*r, (ZERO ? "0" : " "), 0);
		else
			*r = ft_strjoin_free((ZERO ? "0" : " "), *r, 1);
	}
	return (*r);
}

static char			*set_width_id(char **r, intmax_t i, t_env *e)
{
	if (i < 0 && ZERO)
		*r = ft_strsub(*r, 1, (int)ft_strlen(*r) - 1);
	if (MINUS && ZERO && NBWIDTH != 0)
	{
		NBWIDTH = NBWIDTH - (int)ft_strlen(*r);
		if (i < 0)
			return (ft_strjoin_free(*r, ft_putnchar(' ', NBWIDTH - 1), 0));
		return (ft_strjoin_free(*r, ft_putnchar(' ', NBWIDTH), 0));
	}
	*r = set_width_id2(r, i, e);
	if (ZERO && PLUS && !SPACE && NBWIDTH < (int)ft_strlen(*r) && i > 0)
		*r = ft_strjoin_free("+", *r, 1);
	*r[0] = (ZERO && !MINUS && PLUS && NBWIDTH > 0 && i > 0) ? '+' : *r[0];
	*r[0] = (ZERO && PLUS && !SPACE && NBWIDTH > 0 && i >= 0) ? '+' : *r[0];
	if (MINUS && ZERO && NBWIDTH != 0 && i < 0)
		*r = ft_strjoin_free("-", *r, 1);
	*r[0] = (ZERO && NBWIDTH != 0 && i < 0) ? '-' : *r[0];
	*r[0] = (ZERO && NBPREC > 0 && NBWIDTH > 0 && i < 0) ? '-' : *r[0];
	*r[0] = (ZERO && NBPREC > 0 && NBWIDTH > 0 && i >= 0) ? ' ' : *r[0];
	*r[0] = (ZERO && !PLUS && !SPACE && PREC && i == 0) ? ' ' : *r[0];
	*r[0] = (!ZERO && NBPREC < NBWIDTH && i == 0) ? ' ' : *r[0];
	*r[0] = (ZERO && SPACE && NBWIDTH > 0 && i == 0) ? ' ' : *r[0];
	return (*r);
}

void				conv_id(t_env *e)
{
	char			*p;
	intmax_t		id;

	id = set_size_id(e);
	if (PREC && NBWIDTH == 0 && NBPREC == 0 && id == 0)
		p = ft_strdup("\0");
	else
	{
		p = ft_strdup(ft_itoa_l(id));
		if (id >= 0 && (PLUS || SPACE) && !WIDTH)
			p = (ft_strjoin_free((PLUS) ? "+" : " ", p, 1));
		p = set_prec_id(&p, id, e);
		if (WIDTH)
			p = set_width_id(&p, id, e);
		if (PREC && NBWIDTH > 0 && NBPREC == 0 && id == 0)
			p[0] = ' ';
		if (MINUS && PLUS && NBWIDTH > 0 && NBPREC > 0 && id > 0)
			p = ft_strjoin_free("+", p, 1);
		if (id < 0 && ZERO && MINUS && NBWIDTH > 0)
			p = ft_strjoin_free("-", p, 1);
		e->len += ft_strlen(p);
	}
	ft_putstr(p);
	free(p);
}
