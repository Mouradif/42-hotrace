/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:10:46 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 21:47:19 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "hotrace.h"

void	make_tree(char **s, t_node **tree)
{
	static char	*key;

	if (key == NULL)
		key = ft_strdup(*s);
	else
	{
		insert_node(key, *s, tree);
		free(key);
		key = NULL;
	}
}

void	free_tree(t_node **tree)
{
	int i;

	i = 0;
	if (*tree == NULL)
		return ;
	while (i < 95)
	{
		if ((*tree)->kids[i] != NULL)
			free_tree(&((*tree)->kids[i]));
		i++;
	}
	if ((*tree)->isleaf)
		free((*tree)->v);
	free(*tree);
}

void	build_index(t_node **tree)
{
	char	*s;
	char	*tmp;
	int		gnl;

	s = NULL;
	tmp = s;
	gnl = get_next_line(0, &s);
	while (gnl)
	{
		make_tree(&s, tree);
		free(tmp);
		tmp = s;
		gnl = get_next_line(0, &s);
	}
	free(s);
	free(tmp);
}

void	search_index(t_node *tree)
{
	char	*search;
	char	*tmp;
	char	*s;
	int		gnl;

	s = NULL;
	search = NULL;
	tmp = search;
	gnl = get_next_line(0, &search);
	while (gnl)
	{
		s = search_key(search, tree);
		ft_putendl(s);
		free(s);
		free(tmp);
		tmp = search;
		gnl = get_next_line(0, &search);
	}
	free(tmp);
}

int		main(void)
{
	t_node		*tree;

	tree = init_node();
	build_index(&tree);
	search_index(tree);
	free_tree(&tree);
	return (0);
}
