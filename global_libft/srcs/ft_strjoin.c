/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:43 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:57:44 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Allocate and return a new string, the result of the 			*/
/*				concatenation of s1 and s2.									*/
/*																			*/
/*	Argument :																*/
/*			s1		=>	The prefix character string.						*/
/*			s2		=>	The suffixed character string.						*/
/*																			*/
/*	Return :																*/
/*			The new string of characters. NULL if the allocation fails.		*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		c;

	j = 0;
	if (s1)
	{
		i = ft_strlen((char *)s1);
		if (s2)
			j = i + ft_strlen((char *)s2);
		c = 0;
		dst = malloc(sizeof(char) * (j + 1));
		if (!dst)
			return (NULL);
		ft_memcpy(dst, s1, i);
		while (s1 && s2 && i < j)
			dst[i++] = s2[c++];
		dst[i] = '\0';
		return (dst);
	}
	else
		return (NULL);
}
