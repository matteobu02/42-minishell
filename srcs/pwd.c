/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:22:12 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/18 13:52:40 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	datas_prompt.last_command_status = 0;
	ft_putstr_fd(path, 1);
	write(1, "\n", 1);
	free(path);
	path = NULL;
}
