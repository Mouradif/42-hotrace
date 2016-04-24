/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:10:46 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 20:40:29 by mkejji           ###   ########.fr       */
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
	free(*s);
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
	free(*tree);
}

int		main(void)
{
	int			gnl;
	char		*search;
	t_node		*tree;
	char		*s;

	tree = init_node();
	while ((gnl = get_next_line(0, &s)))
		make_tree(&s, &tree);
	while ((gnl = get_next_line(0, &search)))
		ft_putendl(search_key(search, tree));
	free_tree(&tree);
	return (0);
}
