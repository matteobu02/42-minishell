/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:59:11 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:59:12 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/****************************************
*
*	Nom : ft_lstsize_up
*	Params : Pointeur vers la premiere struct de var env de la liste chainee
*	Retour : Nombre d'elements dans la liste chainee
*	Descritpion:
*		Compte le nombre de strcut dans la liste chainee
*
****************************************/

int	ft_lstsize_up(t_var_env *lst)
{
	if (!lst)
		return (0);
	if (lst->next == 0)
		return (1);
	return (1 + ft_lstsize_up(lst->next));
}
