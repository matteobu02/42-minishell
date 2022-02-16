/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:56:01 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:56:02 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function copies the character value to the first count 		*/
/*				characters of the string pointed to, by the argument 		*/
/*				pointer.													*/
/*																			*/
/*	Argument :																*/
/*			pointer		=>	This is a pointer to the block of memory to fill*/
/*																			*/
/*			value		=>	This is the value to be set. The value is passed*/
/*			 					as an int, but the function fills the block */
/*								of memory using the unsigned char conversion*/
/*								of this value.								*/
/*																			*/
/*			count		=>	This is the number of bytes to be set to the 	*/
/*								value.										*/
/*																			*/
/*	Return :																*/
/*			This function returns a pointer to the memory area pointer.		*/
/* ************************************************************************ */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		*(unsigned char *)(pointer + i) = (unsigned char)value;
	return (pointer);
}
