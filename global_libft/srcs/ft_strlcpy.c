/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:58:07 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:58:08 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			strlcpy() copies up to dstsize - 1 characters from the string 	*/
/*				src to dst, NUL-terminating the result if dstsize is not 0.	*/
/*																			*/
/*	Argument :																*/
/*			dst		=>	String where 'src' will be added.					*/
/*			src		=>	String which will be added to 'dst'.				*/
/*			siz		=>	Number of byts to add to 'dst'.						*/
/*																			*/
/*	Return :																*/
/*			The length of src. If the return value is >= dstsize, the 		*/
/*				output string has been truncated. It is the caller's		*/
/*				responsibility to handle this.								*/
/* ************************************************************************ */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len_src;

	i = -1;
	len_src = ft_strlen(src);
	if (!siz)
		return (len_src);
	while (++i < siz)
		dst[i] = src[i];
	dst[i] = '\0';
	return (len_src);
}
