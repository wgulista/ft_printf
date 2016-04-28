#include "includes/libft.h"

int		ft_putnbr_base_u_count(unsigned int n, char *base)
{
	unsigned int	deb;
	unsigned int	fin;
	unsigned int	len;
	int		octet;

	octet = 0;
	len = ft_strlen(base);
	fin = n % len;
	deb = (n - fin) / len;
	if (deb != 0)
		octet += ft_putnbr_base_u_count(deb, base);
	octet++;
	return (octet);
}
