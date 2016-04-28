#include "../includes/ft_printf.h"

int			check_flags(int c)
{
	return (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0');
}