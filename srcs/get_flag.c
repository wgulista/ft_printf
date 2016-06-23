/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:49 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:49 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*set_flags(char **ret, intmax_t i, t_env *e)
{
	if (SPACE && !PLUS && i < 0)
		return (*ret);
	else if (((!SPACE && PLUS) || (SPACE && PLUS)) &&
		i > 0 && check_char(SPEC, "idD"))
		return (ft_strjoin_free("+", *ret, 1));
	else if ((SHARP && PREC && NBPREC > 0 && !check_char(SPEC, "xX"))
		|| (SHARP && check_char(SPEC, "oO") && i > 0))
		return (ft_strjoin_free("0", *ret, 1));
	else if (PLUS && ZERO && NBWIDTH > 0)
		return (ft_strjoin_free("", *ret, 1));
	else if ((ZERO && SPACE) ||
		(SPACE && !PLUS && check_char(SPEC, "id") && i > 0))
		return (ft_strjoin_free(" ", *ret, 1));
	else if (SHARP && !PREC && check_char(SPEC, "xX") && i > 0)
		return (ft_strjoin_free("0x", *ret, 1));
	return (*ret);
}

void		get_flags(t_env *e)
{
	while (check_char(*(e->s), "#0-+ "))
	{
		SHARP = (*(e->s) == '#') ? 1 : SHARP;
		MINUS = (*(e->s) == '-') ? 1 : MINUS;
		PLUS = (*(e->s) == '+') ? 1 : PLUS;
		ZERO = (*(e->s) == '0') ? 1 : ZERO;
		SPACE = (*(e->s) == ' ') ? 1 : SPACE;
		e->s++;
	}
}
