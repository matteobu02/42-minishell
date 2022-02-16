/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:55:36 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:55:38 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function copies size characters from memory area source to 	*/
/*				memory area destination.									*/
/*																			*/
/*	Argument :																*/
/*			destination		=>	This is pointer to the destination array 	*/
/*									where the content is to be copied, 		*/
/*									type-casted to a pointer of type void*.	*/
/*																			*/
/*			source			=>	This is pointer to the source of data to be */
/*									copied, type-casted to a pointer of 	*/
/*									type void*.								*/
/*																			*/
/*			size			=>	This is the number of bytes to be copied.	*/
/*																			*/
/*	Return :																*/
/*			This function returns a pointer to destination.					*/
/* ************************************************************************ */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)destination;
	str2 = (char *)source;
	if (!size || destination == source)
		return (destination);
	i = -1;
	while (++i < size)
		str1[i] = str2[i];
	return ((void *)destination);
}
