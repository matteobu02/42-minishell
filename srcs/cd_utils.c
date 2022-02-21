/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:09:52 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/21 14:33:34 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var_env	*ft_find_in_list(char *str, t_var_env *list)
{
	if (!str || !list)
		return (NULL);
	while (list && ft_strncmp(str, list->name_var, ft_strlen(str)))
		list = list->next;
	return (list);
}
