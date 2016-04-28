#include "includes/libft.h"

int	ft_putnbr_base(int n, char *base)
{
	int	deb;
	int	fin;
	int	len;
	int	octet;

	octet = 0;
	len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		octet++;
		ft_putnbr_base(-n, base);
	}
	else
	{
		fin = n % len;
		deb = (n - fin) / len;
		if (deb != 0)
			octet += ft_putnbr_base(deb, base);
		ft_putchar(base[fin]);
		octet++;
	}
	return (octet);
}
