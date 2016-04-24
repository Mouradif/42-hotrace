/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:04:25 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 16:03:47 by mkejji           ###   ########.fr       */
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
	int		cmp_h;
	int		cmp_v;
	t_node	*next;

	cmp_h = ft_strlen(key) - ft_strlen(root->key);
	cmp_h = (cmp_h == 0) ? ft_strcmprev(key, root->key) : cmp_h;
	if (cmp_h == 0)
		return (ft_strdup(root->value));
	cmp_v = hash_key(key) - root->hash;
	if (cmp_h < 0)
		next = (cmp_v < 0) ? root->ul : root->dl;
	else
		next = (cmp_v < 0) ? root->ur : root->dr;
	if (next == NULL)
		return (not_found(key));
	else
		return (search_key(key, next));
}
