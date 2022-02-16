/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:55:27 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:55:28 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function compares the first n bytes of memory area string1	*/
/*				and memory area string2.									*/
/*																			*/
/*	Argument :																*/
/*			string1		=>	This is the pointer to a block of memory.		*/
/*																			*/
/*			string2		=>	This is the pointer to a block of memory.		*/
/*																			*/
/*			size		=>	This is the number of bytes to be compared.		*/
/*																			*/
/*	Return :																*/
/*			If Return value < 0 then it indicates str1 is less than str2.	*/
/*																			*/
/*			If Return value > 0 then it indicates str2 is less than str1.	*/
/*																			*/
/*			If Return value = 0 then it indicates str1 is equal to str2.	*/
/* ************************************************************************ */

#include "libft.h"

int	ft_memcmp(const void *string1, const void *string2, size_t size)
{
	char	*str1;
	char	*str2;
	size_t	i;

	if (!size)
		return (0);
	i = 0;
	str1 = (char *)string1;
	str2 = (char *)string2;
	while (i < size - 1 && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
