/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:58:55 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:58:57 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			 The function searches for the last occurrence of the character */
/*				c in the string pointed to, by the argument s.				*/
/*																			*/
/*	Argument :																*/
/*			s		=>	This is the C string.								*/
/*																			*/
/*			c		=>	This is the character to be located. It is passed 	*/
/*							as its int promotion, but it is internally 		*/
/*							converted back to char.							*/
/*																			*/
/*	Return :																*/
/*			This function returns a pointer to the last occurrence of 		*/
/*				character in s. If the value is not found, the function 	*/
/*				returns a null pointer.										*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i++;
	while (--i >= 0)
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (0);
}
