/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:09:18 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/06 14:10:16 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			 Iterates over the list lst and applies the function f to the 	*/
/*			 	content of each item. Creates a new list resulting from 	*/
/*			 	successive applications of f. The function del is there to 	*/
/*			 	destroy the content of an element if necessary				*/
/*																			*/
/*	Argument :																*/
/*				lst		=>	L’adresse du pointeur vers un élément.
				f		=>	L’adresse de la fonction à appliquer.			*/
/*																			*/
/*	Return :																*/
/*			The new list. NULL if the allocation fails.						*/
/* ************************************************************************ */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	if (!new_elem)
		return (NULL);
	new_lst = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}
