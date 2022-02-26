/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:22:49 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/25 19:06:23 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

	i = -1;
	while (g_datas.envp[++i])
		if (ft_strchr(g_datas.envp[i], '='))
			ft_putendl_fd(g_datas.envp[i], 1);
	g_datas.last_command_status = 0;
}
