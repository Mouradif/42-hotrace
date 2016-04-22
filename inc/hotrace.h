/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:36:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/22 22:38:57 by mkejji           ###   ########.fr       */
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

#endif
