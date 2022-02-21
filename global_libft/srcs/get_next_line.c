/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:36:24 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:44:57 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *line, char buf)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(line) + 2);
	if (!new)
		return (0);
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		++i;
	}
	if (line)
		free(line);
	new[i++] = buf;
	new[i] = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		ret;
	char	buf[1];

	line = NULL;
	while (buf[0] != '\n')
	{
		ret = read(fd, buf, 1);
		line = ft_strjoin_gnl(line, buf[0]);
		if (ret <= 0)
			break ;
	}
	return (line);
}
