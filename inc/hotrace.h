/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:36:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/23 00:28:15 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

typedef struct		s_node {
	char			*key;
	char			*value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

char	*search_key(char *key, t_node *root);
t_node	*init_node(char *key, char *value);
void	insert_node(t_node *node, t_node **root);

#endif
