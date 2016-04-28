/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:40:55 by wgulista          #+#    #+#             */
/*   Updated: 2016/04/28 15:40:58 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_pointer()
{
	p[0] = &conv_s;
	p[1] = &conv_ss;
	p[2] = &conv_p;
	p[3] = &conv_d;
	p[4] = &conv_dd;
	p[5] = &conv_i;
	p[6] = &conv_o;
	p[7] = &conv_oo;
	p[8] = &conv_u;
	p[9] = &conv_uu;
	p[10] = &conv_x;
	p[11] = &conv_xx;
	p[12] = &conv_c;
	p[13] = &conv_cc;
}

void		init_var(t_count *cp)
{
	cp->i = 0;
	cp->octet = 0;
	cp->func = 0;
	cp->value = 0;
}

void		find_plus(t_env *env, int *i, const char *str)
{
	(void)env;
	(void)*i;
	(void)str;
}

void		init_env(t_env *env, va_list *args, int *i, const char *str)
{
	env->space = 0;
	env->star = 0;
	env->position = 0;
	env->flag = 0;
	env->flag_space = 1;
	env->plus = 0;
	env->diese = 0;
	env->type = 0;
	env->args = args;
	find_plus(env, i, str);
}
