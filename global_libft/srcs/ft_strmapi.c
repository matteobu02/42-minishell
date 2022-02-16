/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:58:29 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:58:30 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Apply the function 'f' to each character of the character 		*/
/*				string passed in argument to create a new string of 		*/
/*				characters resulting from successive applications of "f".	*/
/*																			*/
/*	Argument :																*/
/*			s		=>	The character string to iterate over				*/
/*			f		=>	The function to apply to each character.			*/
/*																			*/
/*	Return :																*/
/*			The character string resulting from the applications successive */
/*				of f. Returns NULL if the allocation failed.				*/
/* ************************************************************************ */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	i = -1;
	if (!s || !f)
		return (0);
	map = ft_strdup(s);
	if (!map)
		return (0);
	while (map[++i])
		map[i] = f(i, map[i]);
	return (map);
}
