/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:22:49 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/18 15:54:03 by mbucci           ###   ########.fr       */
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

void	env(void)
{
	t_var_env	*ptr;

	ptr = datas_prompt.env_in_struct;
	if (!ptr)
		return ;
	while (ptr)
	{
		ft_putstr_fd(ptr->name_var, 1);
		write(1, "=", 1);
		ft_putstr_fd(ptr->var_txt, 1);
		write(1, "\n", 1);
		ptr = ptr->next;
	}
}
