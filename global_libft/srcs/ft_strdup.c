/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:23 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:57:24 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The strdup() function returns a pointer to a new string which 	*/
/*				is a duplicate of the string s. Memory for the new string 	*/
/*				is obtained with malloc.									*/
/*																			*/
/*	Argument :																*/
/*			src		=>	pointer to the null-terminated byte string to 		*/
/*							duplicate.										*/
/*																			*/
/*	Return :																*/
/*			A pointer to the newly allocated string, or a null pointer if 	*/
/*				an error occurred.											*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;

	i = ft_strlen(src);
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (0);
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = 0;
	return (copy);
}
