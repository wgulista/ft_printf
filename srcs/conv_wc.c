/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:10 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:11 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			space_wc(t_env *e)
{
	if (SPACE)
	{
		e->s++;
		e->len += 1;
	}
}

void				conv_wc(t_env *e)
{
	wchar_t			wc;
	char			*p;

	wc = (wchar_t)va_arg(e->ap, wint_t);
	(HH && wc == 0) ? ft_putchar('\0') : 0;
	if ((wc == 0 && (PREC || PLUS || SHARP || SPACE || HH)) || (wc == 0))
	{
		space_wc(e);
		e->len += 1;
		return ;
	}
	p = ft_strnew(ft_size_gs(wc));
	p = ft_strjoin_free(p, wchar_conv(wc), 0);
	while ((int)ft_strlen(p) < NBWIDTH)
	{
		if (MINUS)
			p = ft_strjoin_free(p, (ZERO ? "0" : " "), 0);
		else
			p = ft_strjoin_free((ZERO ? "0" : " "), p, 1);
	}
	(ft_size_gs(wc) > 1) ? (e->len += ft_strlen(p)) : (e->len += 1);
	(!HH) ? ft_putstr(p) : 0;
	free(p);
}
