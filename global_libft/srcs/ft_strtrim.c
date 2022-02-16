/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:59:06 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:59:07 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			 Allocates and returns a copy of the string "s1", without the 	*/
/*				characters specified in "set" at the start and end of 		*/
/*				the string.													*/
/*																			*/
/*	Argument :																*/
/*			s1		=>	The string to trim.									*/
/*			set		=>	The reference set of characters to trim.			*/
/*																			*/
/*	Return :																*/
/*			The trimmed string. NULL if the allocation fails.				*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
