/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:18:40 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/03 14:56:11 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i++] = s2[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

char			*ft_strjoin_free(char const *s1, char const *s2, int num)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i++] = s2[j];
		j++;
	}
	new[i] = '\0';
	(num == 1) ? free((void*)s2) : free((void*)s1);
	return (new);
}
