#include "hotrace.h"
#include "libft.h"
#include <stdio.h>

char			*read_input(char *full_line)
{
	int				read_ret;
	char			*tmp_line;
	char			*tmp;

	tmp_line = (char*)malloc(sizeof(char) * 2);
	tmp_line[0] = '\0';
	while (tmp_line[0] != '\n')
	{
		read_ret = read(1, tmp_line, 1);
		if (read_ret == 0)
			return(NULL);
		tmp_line[1] = '\0';
		tmp = full_line;
		full_line = ft_strjoin(full_line, tmp_line);
		free(tmp);
		if (full_line[ft_strlen(full_line)] == '\n')
			break ;
	}
	free(tmp_line);
	return (full_line);
}
