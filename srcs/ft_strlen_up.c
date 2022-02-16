/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:53 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:33:55 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : ft_strlen_up
*	Params : - la liste de char a parcourir
*			 - la liste de char qui arrete l'augmentation
*	Retour : la longueur jusqu'a un des char de la seconde liste de char
*	Descritpion:
*		Renvoi la longueur de la liste de char jusqu'a crosier un des caracteres
* 			du second parametre
*
****************************************/

int	ft_strlen_up(char *str, char *search)
{
	int	x;
	int	y;
	int	output;

	y = -1;
	output = ft_strlen(str);
	while (search[++y])
	{
		x = 0;
		while (str[x] && str[x] != search[y])
			x++;
		if (output > x)
			output = x;
	}
	return (output);
}
