/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:40:19 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:40:24 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_size_gs(wint_t wint)
{
	if (wint <= 0x0080)
		return (1);
	else if (wint <= 0x800)
		return (2);
	else if (wint <= 0x10000)
		return (3);
	else if (wint <= 0x200000)
		return (4);
	else if (wint <= 0x4000000)
		return (5);
	else if (wint <= 0x7FFFFFFF)
		return (6);
	else
		return (0);
}

static char			*fill_tab_mask(char **tab, char *bin)
{
	char			*mask;
	int				i;
	int				len;

	mask = ft_strdup(*tab);
	i = ft_strlen(mask);
	len = ft_strlen(bin) - 1;
	while (len >= 0)
	{
		if (mask[i] == 'x')
			mask[i] = bin[len--];
		i--;
	}
	while (mask[i])
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i--;
	}
	return (mask);
}

static char			*print_wchar(char *wc)
{
	char			**tab;
	char			*c;
	int				i[2];
	int				mult;

	tab = ft_strsplit(wc, ' ');
	c = ft_strdup("");
	i[0] = 0;
	while (tab[i[0]])
	{
		c[i[0]] = 0;
		mult = 128;
		i[1] = 0;
		while (tab[i[0]][i[1]])
		{
			c[i[0]] += (int)(tab[i[0]][i[1]++] - '0') * mult;
			mult /= 2;
		}
		i[0]++;
	}
	return (c);
}

char				*wchar_conv(unsigned hexa)
{
	char			*wc;
	char			*tab;
	int				size_wc;
	char			*bin;

	tab = ft_strdup("");
	size_wc = ft_size_gs(hexa);
	bin = ft_itoa_base(hexa, 2);
	if (size_wc == 1)
		tab = ft_strjoin(tab, "0xxxxxxx");
	else if (size_wc == 2)
		tab = ft_strjoin(tab, "110xxxxx 10xxxxxx");
	else if (size_wc == 3)
		tab = ft_strjoin(tab, "1110xxxx 10xxxxxx 10xxxxxx");
	else if (size_wc == 4)
		tab = ft_strjoin(tab, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	else if (size_wc == 5)
		tab = ft_strjoin(tab, "111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx");
	else if (size_wc == 6)
		tab = ft_strjoin(tab, \
			"1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx");
	wc = fill_tab_mask(&tab, bin);
	wc = print_wchar(wc);
	free(tab);
	return (wc);
}
