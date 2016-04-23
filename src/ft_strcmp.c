/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:38:26 by apellicc          #+#    #+#             */
/*   Updated: 2016/04/23 14:40:22 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
			s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strcmprev(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (i == j)
	{
		while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
				i > 0 && j > 0)
			i--;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return ((j > i) ? (int)(0 - (unsigned char)s2[j - 1]) :
				(int)((unsigned char)s1[i - 1]));
}
