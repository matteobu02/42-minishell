/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:55 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:57:56 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			strlcat() appends string src to the end of dst. It will append	*/
/*				at most dstsize - strlen(dst) - 1 characters. It will then	*/
/*				NUL-terminate, unless dstsize is 0 or the original dst		*/
/*				string was longer than dstsize.								*/
/*																			*/
/*	Argument :																*/
/*			dst		=>	String where 'src' will be added.					*/
/*			src		=>	String which will be added to 'dst'.				*/
/*			siz		=>	Number of byts to add to 'dst'.						*/
/*																			*/
/*	Return :																*/
/*			The initial length of dst and the length of src. If the return 	*/
/*				value is >= dstsize, the output string has been truncated. 	*/
/*				It is the caller's responsibility to handle this.			*/
/* ************************************************************************ */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	src_long;
	size_t	dst_long;
	size_t	i;

	src_long = -1;
	dst_long = 0;
	i = 0;
	while (dst[dst_long] && dst_long < siz)
		dst_long++;
	while (src[++src_long])
		if (dst_long + src_long < siz - 1 && siz)
			dst[dst_long + (i++)] = src[src_long];
	if (siz && dst_long < siz)
		dst[dst_long + i] = '\0';
	return (dst_long + src_long);
}
