/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:48:28 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 16:22:29 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	hash_key(char *key)
{
	int	hash;
	int	i;

	i = 0;
	hash = 0;
	while (key[i])
	{
		hash += key[i];
		i++;
	}
	return ((hash / i) + hash % i);
}