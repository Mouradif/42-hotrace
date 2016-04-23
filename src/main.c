/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:10:46 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/23 17:35:07 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "hotrace.h"

void			make_tree(char **key_val, char **s, t_node **tree)
{
	static int	line_nb = 0;
	t_node		*node;

	if (line_nb % 2 == 0)
		key_val[0] = ft_strdup(*s);
	else
	{
		key_val[1] = ft_strdup(*s);
		node = init_node(key_val[0], key_val[1]);
		free(key_val[0]);
		free(key_val[1]);
		insert_node(node, tree);
	}
	line_nb++;
}

int				main(void)
{
	int			gnl;
	char		**key_val;
	char		*search;
	t_node		*tree;
	char		*s;

	key_val = (char**)malloc(sizeof(char*) * 2);
	get_next_line(0, key_val);
	get_next_line(0, key_val + 1);
	tree = init_node(key_val[0], key_val[1]);
	while ((gnl = get_next_line(0, &s)))
		make_tree(key_val, &s, &tree);
	while ((gnl = get_next_line(0, &search)))
	{
		key_val[1] = search_key(search, tree);
		if (key_val[1] != NULL)
			puts(key_val[1]);
	}
}
