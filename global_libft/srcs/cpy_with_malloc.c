/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_with_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:23:43 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 07:23:46 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/****************************************
*
*	Nom : cpy_with_malloc
*	Params : La liste de char a copier
*	Retour : La liste de char copiee
*	Descritpion:
*		Copie une chaine avant de la retourner
*
****************************************/

char	*cpy_with_malloc(char *tmp)
{
	char	*out;

	out = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, tmp, ft_strlen(tmp));
	return (out);
}
