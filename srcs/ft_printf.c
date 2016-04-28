#include "../includes/ft_printf.h"

void	found_function(t_count *cp, const char *str, va_list *args)
{
	int	tmp;

	while (p[cp->func] != 0 && (cp->value = p[cp->func](str, &(cp->i), args)) == -1)
		cp->func++;
	tmp = update_int(str, &(cp->i), args, cp->octet);
	if (p[cp->func] == 0 && tmp == -1)
	{
		if (ft_isdigit(str[cp->i + 1]) || str[cp->i + 1] == '*')
			cp->octet += calc_none_space(str, &(cp->i), args);
		if (str[cp->i] != ' ' && str[cp->i] != '%')
			ft_putchar(str[cp->i]);
		cp->i--;
	}
	else
	{
		cp->octet += cp->value;
		if (tmp != -1)
			cp->octet += tmp;
	}
	cp->i++;
}

int				ft_printf(const char *str, ...)
{
	t_count		cp;
	va_list		args;

	va_start(args, str);
	init_var(&cp);
	init_pointer();
	while (str[cp.i] != '\0')
	{
		if (str[cp.i] != '%')
			ft_putchar(str[cp.i]);
		else
			found_function(&cp, str, &args);
		cp.func = 0;
		cp.i++;
	}
	va_end(args);
	return (0);
}