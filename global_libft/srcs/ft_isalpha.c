/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:51:51 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:57:40 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The isalpha() function checks whether a character 				*/
/*				is an alphabet or not.										*/
/*																			*/
/*	Argument :																*/
/*			Function isalpha() takes a single argument in the form 			*/
/*				of an integer value.										*/
/*																			*/
/*	Return :																*/
/*			If a character passed to isalpha() is an alphabet, 				*/
/*				it returns a non-zero integer								*/
/*			If not it returns 0.											*/
/* ************************************************************************ */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
