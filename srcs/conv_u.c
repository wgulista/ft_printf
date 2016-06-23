/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:02 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:03 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_u(char **ret, t_env *e)
{
	if (PREC)
		while ((int)ft_strlen(*ret) < NBPREC)
			*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

static intmax_t		set_size_u(t_env *e)
{
	intmax_t		nbr;

	if (HH)
		nbr = (unsigned char)va_arg(e->ap, unsigned int);
	else if (H)
		nbr = (unsigned short)va_arg(e->ap, unsigned int);
	else if (L)
		nbr = (unsigned long)va_arg(e->ap, unsigned long);
	else if (LL)
		nbr = (unsigned long long)va_arg(e->ap, unsigned long);
	else if (J)
		nbr = (intmax_t)va_arg(e->ap, uintmax_t);
	else if (Z)
		nbr = (size_t)va_arg(e->ap, size_t);
	else
		nbr = (unsigned int)va_arg(e->ap, unsigned int);
	return (nbr);
}

void				conv_u(t_env *e)
{
	char			*p;
	intmax_t		u;

	p = ft_strdup("");
	u = set_size_u(e);
	if (u > 0 && !L && !LL && !Z && !J)
		p = ft_strjoin_free(p, ft_itoa_base_u(u, 10), 0);
	else
		p = ft_strjoin_free(p, ft_itoa_base_l(u, 10), 0);
	if ((PREC && u == 0) || (PREC && NBPREC == 0 && u == 0))
		p = ft_strdup("\0");
	p = set_prec_u(&p, e);
	p = set_width(&p, e);
	e->len += ft_strlen(p);
	ft_putstr(p);
	free(p);
}
