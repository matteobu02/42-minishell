/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:54:57 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 09:55:00 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_one_cmd	*ft_lstnb(t_one_cmd *cmd_first, int nb)
{
	t_one_cmd	*tmp;

	tmp = cmd_first;
	while (--nb > 0)
		tmp = tmp->next;
	return (tmp);
}
