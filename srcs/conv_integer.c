/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:39:35 by wgulista          #+#    #+#             */
/*   Updated: 2016/04/28 15:39:46 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			conv_i(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'i' || (check_flags(str[*i + 1]) && str[*i + 2] == 'i')
		|| (ft_space(str, i, &env, 'i') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, int)));
		return (octet);
	}
	return (-1);
}

int			conv_d(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'd' || (check_flags(str[*i + 1]) && str[*i + 2] == 'd')
		|| (ft_space(str, i, &env, 'd') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, int)));
		return (octet);
	}
	return (-1);
}

int			conv_dd(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'D' || (check_flags(str[*i + 1]) && str[*i + 2] == 'D')
		|| (ft_space(str, i, &env, 'D') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, int)));
		return (octet);
	}
	return (-1);
}
