/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:59:29 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:59:30 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			 The function converts a given letter to lowercase.				*/
/*																			*/
/*	Argument :																*/
/*			c		=>	This is the letter to be converted to lowercase.	*/
/*																			*/
/*	Return :																*/
/*			This function returns lowercase equivalent to c, if such value 	*/
/*				exists, else c remains unchanged. The value is returned 	*/
/*				as an int value that can be implicitly casted to char.		*/
/* ************************************************************************ */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
