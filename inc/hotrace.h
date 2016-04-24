/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:36:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 20:31:26 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

typedef struct		s_node
{
	char			isleaf;
	char			*v;
	struct s_node	*kids[95];
}					t_node;

char				*search_key(char *key, t_node *root);
t_node				*init_node();
void				insert_node(char *key, char *value, t_node **root);
unsigned int		hash_key(char *key);

#endif
