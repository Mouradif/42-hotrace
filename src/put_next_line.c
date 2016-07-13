/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:46:30 by mkejji            #+#    #+#             */
/*   Updated: 2016/04/24 23:36:41 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "libft.h"
#include <unistd.h>

void	put_next_line(char *line, int last)
{
	static char stock[100000] = "";
	static int	len = 0;
	int			slen;

	if (last)
	{
		write(1, stock, len);
		return ;
	}
	slen = ft_strlen(line);
	if (len + slen + 1>= 100000)
	{
		write(1, stock, len);
		len = 0;
	}
	ft_memcpy(stock + len, line, slen);
	stock[len + slen] = '\n';
	len += slen + 1;
}
