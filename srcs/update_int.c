/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:40:59 by wgulista          #+#    #+#             */
/*   Updated: 2016/04/28 15:41:05 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			find_n(t_env *env, int end, const char *str)
{
	while (str[end] != 'n' &&
		(str[end] == '+' || str[end] == '-' || str[end] == '#') &&
		str[end] != '\0')
		end++;
	if (str[end] == 'n')
		env->plus = 1;
}

int				update_int(const char *str, int *i, va_list *args, int p_octet)
{
	t_env		env;

	init_env(&env, args, i, str);
	find_n(&env, *i, str);
	if (str[*i + 1] == 'n' || (check_flags(str[*i + 1]) && str[*i + 2] == 'n')
		|| ft_space(str, i, &env, 'n') != -1 || env.plus == 1)
	{
		*(va_arg(*args, int *)) = p_octet;
		if (str[*i + 1] != 'n')
			*i = *i + 1;
		return (1);
	}
	return (-1);
}
