/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:53:43 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:53:45 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Adds the new element to the start of the list.					*/
/*																			*/
/*	Argument :																*/
/*			alst	=>	The address of the pointer to the first element 	*/
/*							from the list.									*/
/*			new		=>	The address of the pointer to the element to add 	*/
/*							to the list.									*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		new->next = (*alst);
	*alst = new;
}
