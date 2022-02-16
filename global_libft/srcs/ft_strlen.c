/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:58:17 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:58:18 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function computes the length of the string str up to, but 	*/
/*				not including the terminating null character.				*/
/*																			*/
/*	Argument :																*/
/*			str		=>	This is the string whose length is to be found.		*/
/*																			*/
/*	Return :																*/
/*			This function returns the length of string.						*/
/* ************************************************************************ */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
