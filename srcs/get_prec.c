/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:19:53 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:19:54 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_prec(t_env *e)
{
	if (*(e->s) == '.')
	{
		e->s++;
		PREC = 1;
		while (ft_isdigit(*(e->s)))
			NBPREC = NBPREC * 10 + (*(e->s++) - 48);
	}
}