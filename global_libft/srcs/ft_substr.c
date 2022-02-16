/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:59:20 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:59:21 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			 Allocates and returns a string from the string "s. This new 	*/
/*				string begins at the index" start "and has a maximum 		*/
/*				size of" len "												*/
/*																			*/
/*	Argument :																*/
/*			s		=>	The channel from which to extract the news			*/
/*																			*/
/*			start	=>	The start index of the new string in the			*/
/*																			*/
/*			len		=>	The maximum size of the new string.					*/
/*																			*/
/*	Return :																*/
/*			The new character chain. NULL if the allocation fails.			*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start - 1))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && j < len)
			str[j++] = s[i];
	str[j] = 0;
	return (str);
}
