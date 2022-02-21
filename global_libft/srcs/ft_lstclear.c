/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:53:56 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:53:58 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Removes and frees the memory of the element passed in parameter	*/
/*				and all the following elements, to using del and free		*/
/*				Finally, the initial pointer must be set to NULL.			*/
/*																			*/
/*	Argument :																*/
/*			lst		=>		The address of the pointer to an item.			*/
/*			del		=>		The address of the function allowing delete 	*/
/*								the content of an item.						*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tl1;
	t_list	*tl2;

	tl1 = *lst;
	while (tl1)
	{
		tl2 = tl1->next;
		ft_lstdelone(tl1, del);
		tl1 = tl2;
	}
	*lst = NULL;
}
