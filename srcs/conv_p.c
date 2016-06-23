/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:38 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:40 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*set_prec_p(char **ret, t_env *e)
{
	if (PREC)
		while ((int)ft_strlen(*ret) < NBPREC)
			*ret = ft_strjoin_free("0", *ret, 1);
	return (*ret);
}

static char			*set_width_p(char **ret, intmax_t ul, t_env *e)
{
	while ((int)ft_strlen(*ret) < NBWIDTH)
	{
		if ((ul < 0 && !MINUS) || (ZERO && WIDTH && ul == 0))
			*ret = ft_strjoin_free(*ret, (ZERO ? "0" : " "), 0);
		else if (MINUS)
			*ret = ft_strjoin_free(*ret, (ZERO ? "0" : " "), 0);
		else
			*ret = ft_strjoin_free((ZERO ? "0" : " "), *ret, 1);
	}
	return (*ret);
}

void				conv_p(t_env *e)
{
	char			*p;
	void			*ul;

	ul = va_arg(e->ap, void *);
	p = ft_strdup("");
	if (MINUS || ((uintmax_t)ul == 0 && !PREC))
		p = ft_strjoin_free("0x", p, 1);
	if (PREC && (uintmax_t)ul == 0)
		p = ft_strjoin_free(p, "", 0);
	else
		p = ft_strjoin_free(p, ft_itoa_base_l((uintmax_t)ul, 16), 0);
	p = set_prec_p(&p, e);
	if (!MINUS && ((uintmax_t)ul > 0 || PREC))
		p = ft_strjoin_free("0x", p, 1);
	p = set_width_p(&p, (intmax_t)ul, e);
	ft_putstr(p);
	e->len += ft_strlen(p);
	free(p);
}
