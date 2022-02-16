/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:33 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:57:35 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Apply the function f to each character of the character string 	*/
/*				transmitted as an argument, and passing its index as the 	*/
/*				first argument. Each character is transmitted by address 	*/
/*				to f to be modified if necessary.							*/
/*																			*/
/*	Argument :																*/
/*			s	=>		The character string on which to iterate.			*/
/* 			f	=>		The function to apply to each character.			*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
