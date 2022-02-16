/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:53:02 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:53:03 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The isprint() function checks whether a character is			*/
/*				a printable character or not.								*/
/*																			*/
/*	Argument :																*/
/*			Function isprint() takes a single argument in the form of 		*/
/*				an integer.													*/
/*																			*/
/*	Return :																*/
/*			If a character passed to isprint() is a printable character		*/
/*				it returns non-zero integer, if not it returns 0.			*/
/* ************************************************************************ */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
