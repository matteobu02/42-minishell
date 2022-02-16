/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:54:35 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:54:37 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Returns the last item in the list.								*/
/*																			*/
/*	Argument :																*/
/*			lst		=>		The beginning of the list.						*/
/*																			*/
/*	Return :																*/
/*			Last item in the list											*/
/* ************************************************************************ */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
