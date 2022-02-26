/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:22:12 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/22 11:25:29 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	g_datas.last_command_status = 0;
	ft_putendl_fd(path, 1);
	free(path);
	path = NULL;
}
