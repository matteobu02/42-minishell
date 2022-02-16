/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:22:49 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/15 12:51:16 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

char	*ft_getenv(char *var_name, t_var_env *list)
{
	char	*val;

	while (list && ft_strncmp(list->name_var, var_name, ft_strlen(var_name)))
		list = list->next;
	if (!list)
		val = NULL;
	else
		val = list->var_txt;
	return (val);
}

void	env(t_var_env *list)
{
	while (list)
	{
		printf("%s=%s\n", list->name_var, list->var_txt);
		list = list->next;
	}
}
