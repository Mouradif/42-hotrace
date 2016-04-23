/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:41:07 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/23 18:43:12 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "libft.h"

t_node	*init_node(char *key, char *value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (node != NULL)
	{
		node->key = ft_strdup(key);
		node->value = ft_strdup(value);
		node->ul = NULL;
		node->ur = NULL;
		node->dl = NULL;
		node->dr = NULL;
	}
	return (node);
}

void	insert_node(t_node *node, t_node **root)
{
	int		cmp_h;
	int		cmp_v;
	t_node	**next;

	cmp_h = ft_strlen(node->key) - ft_strlen((*root)->key);
	cmp_h = (cmp_h == 0) ? ft_strcmprev(node->key, (*root)->key) : cmp_h;
	cmp_v = ft_strcmp(node->key, (*root)->key);
	if (cmp_h < 0)
		next = (cmp_v < 0) ? &((*root)->ul) : &((*root)->dl);
	else
		next = (cmp_v < 0) ? &((*root)->ur) : &((*root)->dr);
	if (*next == NULL)
		*next = node;
	else
		insert_node(node, next);
}
