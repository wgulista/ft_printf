#include "../includes/ft_printf.h"

void	if_star(t_env *env, int *i, const char *str)
{
	while (str[*i] == '*')
		*i += 1;
	env->space = va_arg(*(env->args), int) - 1;
}

void	if_nb(t_env *env, int *i, const char *str)
{
	if (str[*i] == '0')
	{
		env->type = '0';
		*i += 1;
	}
	while (ft_isdigit(str[*i]))
	{
		env->space *= 10;
		env->space += (str[*i] - '0');
		*i += 1;
	}
	env->space--;
}

int		calc_none_space(const char *str, int *i, va_list *args)
{
	t_env	env;
	int		octet;

	octet = 0;
	*i += 1;
	init_env(&env, args, i, str);
	env.type = ' ';
	if (str[*i] == '*')
		if_star(&env, i, str);
	else
		if_nb(&env, i, str);
	octet += ft_put_space(&env);
	return (octet);
}