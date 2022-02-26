/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:35:10 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/26 02:32:51 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_builtin_env(t_one_cmd *cmd)
{
	if (!ft_strncmp("cd", cmd->cmd, 2))
		cd(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else if (!ft_strncmp("export", cmd->cmd, 6))
		ft_export(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else if (!ft_strncmp("unset", cmd->cmd, 5))
		unset(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else
		return (1);
	return (0);
}

int	find_builtin(t_one_cmd *cmd)
{
	if (!ft_strncmp("echo", cmd->cmd, 4))
		echo(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else if (!ft_strncmp("env", cmd->cmd, 3))
		env();
	else if (!ft_strncmp("pwd", cmd->cmd, 3))
		pwd();
	else if (!ft_strncmp("exit", cmd->cmd, 4))
		ft_exit();
	else
		return (1);
	return (0);
}

int	check_builtin(t_one_cmd *cmd)
{
	return ((!ft_strncmp("cd", cmd->cmd, 2))
		|| (!ft_strncmp("echo", cmd->cmd, 4))
		|| (!ft_strncmp("env", cmd->cmd, 3))
		|| (!ft_strncmp("pwd", cmd->cmd, 3))
		|| (!ft_strncmp("export", cmd->cmd, 6))
		|| (!ft_strncmp("unset", cmd->cmd, 5))
		|| (!ft_strncmp("exit", cmd->cmd, 4)));
}

int	ft_exit_all(void)
{
	char	**tmp;
	int		i;

	tmp = g_datas.cmds->cmd_first->all_cmd;
	if (ft_matrixlen(tmp) > 1)
	{
		i = -1;
		while (ft_isdigit(tmp[1][++i]))
			;
		if (!ft_isdigit(tmp[1][i]) && i != (int)ft_strlen(tmp[1]))
		{
			ft_putstr_fd("Minishell: exit: ", 1);
			ft_putstr_fd(tmp[1], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			return (255);
		}
		else if (ft_atoi(tmp[1]) && ft_matrixlen(tmp) > 2)
		{
			ft_putstr_fd("bash: exit: too many arguments\n", 1);
			return (1);
		}
		return (ft_atoi(tmp[1]) % 255);
	}
	return (0);
}

void	ft_exit(void)
{
	int	val_return;

	ft_putstr_fd("exit\n", 1);
	val_return = ft_exit_all();
	ft_free_datas_cmd(g_datas.cmds);
	ft_new_free(g_datas.env_in_struct);
	if (g_datas.out_struct)
		ft_new_free(g_datas.out_struct);
	tcsetattr(0, TCSANOW, &g_datas.new);
	exit (val_return);
}
