/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:39:51 by wgulista          #+#    #+#             */
/*   Updated: 2016/04/28 15:39:55 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					conv_p(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'p' || (check_flags(str[*i + 1]) && str[*i + 2] == 'p')
		|| (ft_space(str, i, &env, 'p') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, void *)));
		return (octet);
	}
	return (-1);
}
