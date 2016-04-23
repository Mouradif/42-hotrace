/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:10:46 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/23 12:21:17 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "hotrace.h"

int	main(void)
{
	int		line_nb;
	int		gnl;
	char	*key;
	char	*val;
	char	*search;
	t_node	*node;
	t_node	*tree;
	char	*s;

	line_nb = 0;
	get_next_line(0, &key);
	get_next_line(0, &val);
	tree = init_node(key, val);
	while ((gnl = get_next_line(0, &s)))
	{
		if (line_nb % 2 == 0)
			key = ft_strdup(s);
		else
		{
			val = ft_strdup(s);
			node = init_node(key, val);
			free(key);
			free(val);
			insert_node(node, &tree);
		}
		line_nb++;
	}
	while ((gnl = get_next_line(0, &search)))
	{
		val = search_key(search, tree);
		if (val != NULL)
			puts(val);
	}
}
