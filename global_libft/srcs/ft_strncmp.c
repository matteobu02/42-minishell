/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:58:38 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:58:39 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function compares at most the first n bytes of str1 		*/
/*				and str2.													*/
/*																			*/
/*	Argument :																*/
/*			s1	=>	This is the first string to be compared.				*/
/*																			*/
/*			s2	=>	This is the second string to be compared.				*/
/*																			*/
/*			n		=>	The maximum number of characters to be compared.	*/
/*																			*/
/*	Return :																*/
/*			if Return value < 0 then it indicates s1 is less than s2.		*/
/*																			*/
/*			if Return value > 0 then it indicates s2 is less than s1.		*/
/*																			*/
/*			if Return value = 0 then it indicates s1 is equal to s2.		*/
/* ************************************************************************ */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i < n - 1)
		return (1);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
