/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:28 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:57:29 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/****************************************
*
*	Nom : ft_allisspace
*	Params : La ligne de char que l'on doit parcourir
*	Retour : la position de l'espace ou du tab (-1 si pas trouve)
*	Descritpion:
*		Parcourt toute la liste afin de trouver un tab ou un espace et renvoi la
*			position du premier ou -1 si il n'en a pas trouve
*
****************************************/

int	ft_allisspace(char *str)
{
	int	x;

	x = ft_strlen(str);
	while (--x > -1 && (str[x] == '\t' || str[x] == ' '))
		;
	return (x);
}
