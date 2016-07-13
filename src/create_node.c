/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:41:07 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 22:49:13 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "libft.h"

t_node	*init_node(void)
{
	t_node	*node;
	int		i;

	i = 0;
	node = (t_node*)malloc(sizeof(t_node));
	if (node != NULL)
	{
		node->isleaf = 0;
		node->v = NULL;
		while (i < 95)
		{
			node->kids[i] = NULL;
			i++;
		}
	}
	return (node);
}

void	insert_node(char *key, char *value, t_node **root)
{
	if (*root == NULL)
		*root = init_node();
	if (*key == '\0')
	{
		if ((*root)->isleaf)
			free((*root)->v);
		else
			(*root)->isleaf = 1;
		(*root)->v = ft_strdup(value);
	}
	else
		insert_node(key + 1, value, &((*root)->kids[*key % 95]));
}
