/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:20:04 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:20:05 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*set_width(char **ret, t_env *e)
{
	int			len;

	len = 0;
	if (WIDTH && (int)ft_strlen(*ret) < NBWIDTH)
	{
		len = NBWIDTH - (int)ft_strlen(*ret);
		if (PLUS && ZERO && NBWIDTH > 0)
			*ret = ft_strjoin_free(*ret, ft_putnchar('0', len - 1), 0);
		else if (SPACE && ZERO && NBWIDTH > 0)
			*ret = ft_strjoin_free(*ret, ft_putnchar('0', len), 0);
		else if (PREC && ZERO && NBWIDTH > 0)
			*ret = ft_strjoin_free(ft_putnchar(' ', NBWIDTH - NBPREC), *ret, 1);
		else if (MINUS && ZERO && NBWIDTH > 0)
			*ret = ft_strjoin_free(*ret, ft_putnchar(' ', len), 0);
		else
		{
			while ((int)ft_strlen(*ret) < NBWIDTH)
				if (MINUS)
					*ret = ft_strjoin_free(*ret, (ZERO ? "0" : " "), 0);
				else
					*ret = ft_strjoin_free((ZERO ? "0" : " "), *ret, 1);
		}
	}
	return (*ret);
}

void			get_width(t_env *e)
{
	if (ft_isdigit(*(e->s)))
	{
		WIDTH = 1;
		while (ft_isdigit(*(e->s)))
		{
			WIDTH = 1;
			NBWIDTH = NBWIDTH * 10 + (*(e->s++) - 48);
		}
	}
}
