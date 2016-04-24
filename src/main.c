/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:10:46 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 17:55:10 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "hotrace.h"

void	make_tree(char **s, t_node **tree)
{
	static char	*key;
	t_node		*node;

	if (key == NULL)
		key = ft_strdup(*s);
	else
	{
		node = init_node(key, *s);
		free(key);
		key = NULL;
		insert_node(node, tree);
	}
	free(*s);
}

void	free_tree(t_node **tree)
{
	if ((*tree)->ul != NULL)
		free_tree(&((*tree)->ul));
	if ((*tree)->ur != NULL)
		free_tree(&((*tree)->ur));
	if ((*tree)->dl != NULL)
		free_tree(&((*tree)->dl));
	if ((*tree)->dr != NULL)
		free_tree(&((*tree)->dr));
	free(*tree);
}

int		main(void)
{
	int			gnl;
	char		*search;
	t_node		*tree;
	char		*s;

	tree = NULL;
	while ((gnl = get_next_line(0, &s)))
		make_tree(&s, &tree);
	while ((gnl = get_next_line(0, &search)))
		ft_putendl(search_key(search, tree));
	free_tree(&tree);
	return (0);
}
