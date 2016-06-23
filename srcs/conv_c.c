/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:15:57 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:16:02 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*set_width_c(char **ret, t_env *e)
{
	NBWIDTH--;
	if (WIDTH)
	{
		while ((int)ft_strlen(*ret) < NBWIDTH)
		{
			if (MINUS)
				*ret = ft_strjoin_free(*ret, (ZERO ? "0" : " "), 0);
			else
				*ret = ft_strjoin_free((ZERO ? "0" : " "), *ret, 1);
		}
	}
	return (*ret);
}

static void		print_c(char c, char *p, t_env *e)
{
	if (MINUS)
		ft_putchar(c);
	ft_putstr(p);
	if (!MINUS)
		ft_putchar(c);
}

void			conv_c(t_env *e)
{
	char		c;
	char		*p;

	if (L)
		conv_wc(e);
	else
	{
		c = (char)va_arg(e->ap, int);
		p = ft_strdup("");
		if (!WIDTH)
		{
			ft_putchar(c);
			e->len += 1;
		}
		else
		{
			p = set_width_c(&p, e);
			print_c(c, p, e);
			e->len += (ft_strlen(p) + 1);
			free(p);
		}
	}
}
