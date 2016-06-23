/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:26 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:27 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		set_flag_env(t_env *e)
{
	t_flag		flag;

	flag.sharp = 0;
	flag.zero = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	e->f = flag;
}

static void		set_mdf_env(t_env *e)
{
	t_mdf		mdf;

	mdf.size = 0;
	mdf.h = 0;
	mdf.hh = 0;
	mdf.l = 0;
	mdf.ll = 0;
	mdf.j = 0;
	mdf.z = 0;
	e->m = mdf;
}

void			new_env(t_env *e)
{
	e->s = NULL;
	e->len = 0;
	WIDTH = 0;
	NBWIDTH = 0;
	PREC = 0;
	NBPREC = 0;
	set_flag_env(e);
	set_mdf_env(e);
	SPEC = 0;
}

void			delete_env(t_env *e)
{
	WIDTH = 0;
	NBWIDTH = 0;
	PREC = 0;
	NBPREC = 0;
	set_flag_env(e);
	set_mdf_env(e);
	SPEC = 0;
}
