#include "../includes/ft_printf.h"

int			conv_s(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int 			octet;
 
	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 's' || (check_flags(str[*i + 1]) && str[*i + 2] == 's') 
		|| (ft_space(str, i, &env, 's') != -1))
	{
		env.space -= ft_strlen((printf.str = va_arg(*args, char *)));
		if (env.flag == 1 && env.position == 0)
			octet += ft_put_space(&env);
		if (printf.str != 0)
			ft_putstr(printf.str);
		if (env.flag == 1 && env.position == 1)
			octet += ft_put_space(&env);
		if (str[*i + 1] != 's')
			*i = *i + 1;
		return (octet);
	}
	return (-1);
}
 
int			conv_S(const char *str, int *i, va_list *args)
{
	t_printf		printf;
	t_env			env;
	int				octet;

	octet = 0;
	init_env(&env, args, i, str);
	if (str[*i + 1] == 'S' || (check_flags(str[*i + 1]) && str[*i + 2] == 'S') 
		|| (ft_space(str, i, &env, 'S') != -1))
	{
		env.space = env.space - ft_strlen((printf.str = va_arg(*args, char *)));
		if (env.flag == 1 && env.position == 0)
			octet += ft_put_space(&env);
		ft_putstr(printf.str);
		if (env.flag == 1 && env.position == 1)
			octet += ft_put_space(&env);
		if (str[*i + 1] != 'S')
			*i = *i + 1;
		return (octet);
	}
	return (-1);
}