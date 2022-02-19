/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:09:52 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/19 14:29:15 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_list_to_index(char *str, t_var_env *list)
{
	int	index;

	index = 0;
	while (list && ft_strncmp(str, list->name_var, ft_strlen(str)))
	{
		index++;
		list = list->next;
	}
	if (!list)
		return (-1);
	return (index);
}
