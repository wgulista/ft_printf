/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:39:23 by wgulista          #+#    #+#             */
/*   Updated: 2016/04/28 15:39:31 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					conv_c(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'c' || (check_flags(str[*i + 1]) && str[*i + 2] == 'c')
		|| (ft_space(str, i, &env, 'c') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, char)));
		if (env.flag == 1 && env.position == 0)
			octet += ft_put_space(&env);
		if (printf.str != 0)
			ft_putchar(printf.str);
		if (env.flag == 1 && env.position == 1)
			octet += ft_put_space(&env);
		if (str[*i + 1] != 'c')
			*i = *i + 1;
		return (octet);
	}
	return (-1);
}

int					conv_cc(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'c' || (check_flags(str[*i + 1]) && str[*i + 2] == 'c')
		|| (ft_space(str, i, &env, 'c') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, char)));
		if (env.flag == 1 && env.position == 0)
			octet += ft_put_space(&env);
		if (printf.str != 0)
			ft_putchar(printf.str);
		if (env.flag == 1 && env.position == 1)
			octet += ft_put_space(&env);
		if (str[*i + 1] != 'c')
			*i = *i + 1;
		return (octet);
	}
	return (-1);
}
