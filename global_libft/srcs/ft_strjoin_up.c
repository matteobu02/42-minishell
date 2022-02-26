/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:19:25 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 07:19:35 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_join(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*ft_strjoin_up(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	join = ft_calloc((len + 1), sizeof(char));
	if (!join)
		return (ft_free_join(s1));
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}
