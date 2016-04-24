/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:10:46 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 15:41:04 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "hotrace.h"

void			make_tree(char **s, t_node **tree)
{
	static int	line_nb = 0;
	static char	*key;
	t_node		*node;

	if (key == NULL)
		key = ft_strdup(*s);
	else
	{
		node = init_node(key, ft_strdup(*s));
		free(key);
		key = NULL;
		insert_node(node, tree);
	}
	line_nb++;
}

int				main(void)
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
}
