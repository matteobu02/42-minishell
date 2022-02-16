/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:51:25 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/05 10:11:12 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Allocates memory for an array of num objects of size			*/
/*				and initializes all bytes in the allocated storage to zero.	*/
/*																			*/
/*	Argument :																*/
/*			count	=>	number of objects									*/
/*			size	=>	size of each object									*/
/*																			*/
/*	Return :																*/
/*			On success, returns the pointer to the beginning of newly		*/
/*				allocated memory. To avoid a memory leak, 					*/
/*				the returned pointer must be deallocated with free() 		*/
/*				or realloc().												*/
/*			On failure, returns a null pointer.								*/
/* ************************************************************************ */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = (void *)malloc(size * count);
	if (!rtn)
		return (0);
	ft_bzero(rtn, count * size);
	return (rtn);
}
