/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:34:45 by akopera           #+#    #+#             */
/*   Updated: 2016/04/23 12:04:39 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hotrace.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		lens1;
	int		lens2;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!res)
		return (res);
	while (i < lens1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		res[(lens1 + i)] = s2[i];
		i++;
	}
	res[lens1 + lens2] = '\0';
	return (res);
}
