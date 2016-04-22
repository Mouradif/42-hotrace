/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:04:25 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/22 23:10:31 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*search_key(char *key, t_node *root)
{
	int		cmp;
	t_node	*next;
	
	cmp = ft_strlen(key) - ft_strlen(root->key);
	cmp = (cmp == 0) ? ft_strcmp(key, root->key) : cmp;
	if (cmp == 0)
		return (ft_strdup(root->value));
	next = (cmp < 0) ? root->left : root->right;
	if (*next == NULL)
		return (not_found(key));
	else
		return (search_key(key, next));
}
