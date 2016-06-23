/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:33 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:34 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			analyser(t_env *e)
{
	get_flags(e);
	if (!WIDTH)
		get_width(e);
	get_prec(e);
	get_size(e);
	if (check_char(*(e->s), "sSpdDioOuUxXcC"))
		conv_parser(e);
	else
		non_conv(e);
	delete_env(e);
}

int				ft_printf(const char *format, ...)
{
	t_env		e;

	new_env(&e);
	e.s = (char *)format;
	va_start(e.ap, format);
	while (*(e.s) != '\0')
	{
		if (*(e.s) == '%')
		{
			e.s++;
			if (*(e.s) == '\0')
				break ;
			else
				analyser(&e);
		}
		else
			e.len += write(1, &(*(e.s)), 1);
		e.s++;
	}
	va_end(e.ap);
	return (e.len);
}
