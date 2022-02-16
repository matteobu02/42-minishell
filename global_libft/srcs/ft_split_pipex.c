/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:44:55 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/21 13:45:17 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (s[i] != c)
		nb++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			nb++;
		i++;
	}
	return (nb);
}

char	**null_return(int i, char **t)
{
	while (i--)
		free(t[i]);
	return (NULL);
}

char	**alloc_memory(int len, char **t, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	while (*s)
	{
		j = 0;
		len = 0;
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		while (*(s + len) != c && *(s + len))
			len++;
		t[i] = ft_calloc ((len + 1), sizeof(char));
		if (!t[i])
			return (null_return(i, t));
		while (*s && *s != c)
		{
			t[i][j++] = *(s++);
			if (*s == c)
				t[i++][j] = '\0';
		}
	}
	return (t);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**t;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	t = (char **)ft_calloc(count(s, c) + 1, sizeof(char *));
	if (!t)
		return (NULL);
	t = alloc_memory(len, t, s, c);
	if (!t)
	{
		free(t);
		return (NULL);
	}
	t[count(s, c)] = NULL;
	return (t);
}
