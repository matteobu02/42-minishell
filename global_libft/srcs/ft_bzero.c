/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:51:13 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/05 10:11:21 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The bzero() function erases the data in the n bytes				*/
/*				of the memory starting at the location pointed,				*/
/*				by writing zeros ('\0') to that area.						*/
/*																			*/
/*	Argument :																*/
/*			pointer		=>	Points to a buffer that zeros are copied into.	*/
/*																			*/
/*			count		=>	Is the number of zeros to be copied into 		*/
/*								the buffer.									*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "libft.h"

void	ft_bzero(void *pointer, size_t count)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)pointer;
	i = -1;
	while (++i < count)
		str[i] = 0;
}
