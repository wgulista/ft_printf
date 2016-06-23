/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ws.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:13 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:14 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_add_prec_width_wstr(char **ret, t_env *e)
{
	if (PREC)
	{
		if ((NBWIDTH == 0) || (NBPREC < NBWIDTH && NBPREC > 1))
			*ret = ft_strndup(*ret, NBPREC - 1);
		if ((NBWIDTH > 0) || (NBWIDTH > 0 && NBPREC == 1))
			*ret = ft_strndup(*ret, NBPREC);
	}
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

char			*ft_putwstr(wchar_t *s, t_env *e)
{
	int			i;
	int			len;
	char		*tmp;
	char		*str;

	i = 0;
	len = 0;
	str = ft_strnew(0);
	while (s[i] != L'\0')
	{
		tmp = wchar_conv(s[i]);
		len = ft_strlen(tmp);
		if (PREC)
		{
			if (len <= NBPREC)
				str = ft_strjoin_free(str, tmp, 0);
		}
		else
			str = ft_strjoin_free(str, tmp, 0);
		i++;
	}
	free(tmp);
	return (str);
}

void			conv_ws(t_env *e)
{
	wchar_t		*wstr;
	char		*p;
	int			i;

	i = 0;
	p = ft_strdup("");
	if (!(wstr = (wchar_t*)va_arg(e->ap, wchar_t*)))
	{
		ft_putstr("(null)");
		e->len += ft_strlen("(null)");
	}
	else
	{
		p = ft_putwstr(wstr, e);
		p = ft_add_prec_width_wstr(&p, e);
		e->len += ft_strlen(p);
		ft_putstr(p);
		free(p);
	}
}
