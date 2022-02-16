/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:37:21 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/05 09:37:24 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The isascii() function tests if a given character can be 		*/
/*				represented as a valid 7–bit US-ASCII character.			*/
/*																			*/
/*	Argument :																*/
/*			Function isalpha() takes a single argument in the form			*/
/*				of an integer value.										*/
/*																			*/
/*	Return :																*/
/*			The isascii() function returns nonzero if can be represented	*/
/*				as a character in the 7–bit US-ASCII character set.			*/
/*			Otherwise, it returns 0.										*/
/* ************************************************************************ */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
