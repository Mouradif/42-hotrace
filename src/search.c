/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:04:25 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 20:28:28 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hotrace.h"

void	*not_found(char *k)
{
	char	*str;

	str = ft_strdup(k);
	str = ft_strjoin(str, ": Not found.");
	return (str);
}

char	*search_key(char *key, t_node *root)
{
	int		i;
	t_node	*tmp;

	tmp = root;
	i = 0;
	while (key[i])
	{
		if (tmp->kids[key[i] % 95] == NULL)
			return (not_found(key));
		tmp = tmp->kids[key[i] % 95];
		i++;
	}
	if (tmp->isleaf)
		return (ft_strdup(tmp->v));
	return (not_found(key));
}
