/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:55:48 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:55:50 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function copies size characters from source to destination.	*/
/*																			*/
/*	Argument :																*/
/*			destination		=>	This is a pointer to the destination array 	*/
/*									where the content is to be copied, 		*/
/*									type-casted to a pointer of type void*.	*/
/*																			*/
/*			source			=>	This is a pointer to the source of data to 	*/
/*									be copied, type-casted to a pointer of 	*/
/*									type void*.								*/
/*																			*/
/*			size			=>	This is the number of bytes to be copied.	*/
/*																			*/
/*	Return :																*/
/*			This function returns a pointer to the destination.				*/
/* ************************************************************************ */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char	*str1;
	char	*str2;

	str1 = (char *)destination;
	str2 = (char *)source;
	if (str1 == str2)
		return (str1);
	if (str2 < str1)
	{
		while (size--)
			*(str1 + size) = *(str2 + size);
		return (destination);
	}
	while (size--)
		*str1++ = *str2++;
	return (destination);
}
