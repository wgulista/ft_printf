/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:18:46 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:18:47 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	conv_string(t_env *e)
{
	if (SPEC == 'C')
		conv_wc(e);
	if (SPEC == 'c')
		conv_c(e);
	if (SPEC == 'S')
		conv_ws(e);
	if (SPEC == 's')
		conv_s(e);
}

static void	conv_decimal(t_env *e)
{
	if (SPEC == 'D')
		conv_gd(e);
	if (SPEC == 'i' || SPEC == 'd')
		conv_id(e);
	if (SPEC == 'u')
		conv_u(e);
	if (SPEC == 'U')
		conv_gu(e);
}

static void	conv_hexa(t_env *e)
{
	if (SPEC == 'x')
		conv_x(e);
	if (SPEC == 'X')
		conv_gx(e);
	if (SPEC == 'p')
		conv_p(e);
}

static void	conv_octal(t_env *e)
{
	if (SPEC == 'o')
		conv_o(e);
	if (SPEC == 'O')
		conv_go(e);
}

void		conv_parser(t_env *e)
{
	SPEC = *(e->s);
	if (check_char(SPEC, "sScC"))
		conv_string(e);
	if (check_char(SPEC, "idDuU"))
		conv_decimal(e);
	if (check_char(SPEC, "xXp"))
		conv_hexa(e);
	if (check_char(SPEC, "oO"))
		conv_octal(e);
}
