/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:41:07 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/22 23:04:20 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

t_node	*init_node(char *key, char *value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	insert_node(t_node *node, t_node **root)
{
	int		cmp;
	t_node	**next;
	
	cmp = ft_strlen(node->key) - ft_strlen(tmp->key);
	cmp = (cmp == 0) ? ft_strcmp(node->key, tmp->key) : cmp;
	next = (cmp < 0) ? &((*root)->left) : &((*root)->right);
	if (*next == NULL)
		*next = node;
	else
		insert_node(node, next);
}
