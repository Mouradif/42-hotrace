/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:36:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 16:02:16 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

typedef struct		s_node {
	char			*key;
	char			*value;
	unsigned int	hash;
	struct s_node	*ul;
	struct s_node	*ur;
	struct s_node	*dl;
	struct s_node	*dr;
}					t_node;

char				*search_key(char *key, t_node *root);
t_node				*init_node(char *key, char *value);
void				insert_node(t_node *node, t_node **root);
unsigned int		hash_key(char *key);

#endif
