/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:55:16 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:55:18 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function searches for the first occurrence of the character */
/*				c in the first n bytes of the string pointed to by 			*/
/*				the argument s.												*/
/*																			*/
/*	Argument :																*/
/*			s	=>		This is the pointer to the block of memory where 	*/
/*							the search is performed.						*/
/*																			*/
/*			c	=>		This is the value to be passed as an int, 			*/
/*							but the function performs a byte per byte 		*/
/*							search using the unsigned char conversion 		*/
/*							of this value.									*/
/*																			*/
/*			n	=>		This is the number of bytes to be analyzed.			*/
/*																			*/
/*	Return :																*/
/*			This function returns a pointer to the matching byte or NULL 	*/
/*				if the character does not occur in the given memory area.	*/
/* ************************************************************************ */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	cc;
	char	*str;

	i = 0;
	str = (char *)s;
	cc = (char)c;
	while (i < n && str[i] != cc)
		i++;
	if (i < n && str[i] == cc)
		return (&str[i]);
	return (0);
}
