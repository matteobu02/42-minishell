/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:47:08 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:47:10 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/****************************************
*
*	Nom : ft_strchr_up
*	Params : - La ligne de char a fouiller
*			 - Char a chercher
*	Retour : La position du char a chercher
*	Descritpion:
*		Fonctionne comme strchr mais retourne la valeur de l'index du premier
*			char recherche
*
****************************************/

int	ft_strchr_up(const char *str, int to_find)
{
	int	x;

	x = 0;
	while (*str != (char)to_find && *str)
	{
		x++;
		str++;
	}
	if (*str == (char)to_find)
		return (x);
	return (0);
}
