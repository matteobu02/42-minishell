/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:13 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:57:14 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function searches for the first occurrence of the character */
/*				to_find in the string pointed to by the argument str.		*/
/*																			*/
/*	Argument :																*/
/*			str			=>	This is the C string to be scanned.				*/
/*																			*/
/*			to_find		=>	This is the character to be searched in str.	*/
/*																			*/
/*	Return :																*/
/*			This returns a pointer to the first occurrence of the character */
/*				to_find in the string str, or NULL if the character is not 	*/
/*				found.														*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	while (*str != (char)to_find && *str)
		str++;
	if (*str == (char)to_find)
		return ((char *)str);
	return (0);
}
