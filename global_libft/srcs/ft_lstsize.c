/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:55:04 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:55:06 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Count the number of items in the list.							*/
/*																			*/
/*	Argument :																*/
/*			lst		=>		The beginning of the list.						*/
/*																			*/
/*	Return :																*/
/*			List size.														*/
/* ************************************************************************ */

#include "libft.h"

int	ft_lstsize(t_one_cmd *lst)
{
	if (!lst)
		return (0);
	if (lst->next == 0)
		return (1);
	return (1 + ft_lstsize(lst->next));
}
