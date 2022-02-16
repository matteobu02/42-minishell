/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:59:38 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:59:39 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			 The function converts lowercase letter to uppercase.			*/
/*																			*/
/*	Argument :																*/
/*			c		=>	This is the letter to be converted to uppercase.	*/
/*																			*/
/*	Return :																*/
/*			This function returns uppercase equivalent to c, if such value 	*/
/*				exists, else c remains unchanged. The value is returned 	*/
/*				as an int value that can be implicitly casted to char.		*/
/* ************************************************************************ */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
