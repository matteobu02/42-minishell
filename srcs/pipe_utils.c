/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:55:03 by lbuccher          #+#    #+#             */
/*   Updated: 2022/02/25 12:14:10 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**get_path(char *env[])
{
	char	*all_path;
	char	**split_path;
	int		i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	if (i == ft_matrixlen(env))
		return (NULL);
	all_path = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	if (!all_path)
		return (NULL);
	split_path = ft_split_pipex(all_path, ':');
	if (!split_path)
	{
		free(all_path);
		return (NULL);
	}
	free(all_path);
	return (split_path);
}

void	close_pipe(int fd[2])
{
	close(fd[1]);
	close(fd[0]);
}

void	ft_free(char **paths, char **cmd)
{
	int	path_len;
	int	cmd_len;

	path_len = ft_matrixlen(paths);
	cmd_len = ft_matrixlen(cmd);
	while (paths && (path_len >= 0))
		free(paths[path_len--]);
	while (cmd && (cmd_len >= 0))
		free(cmd[cmd_len--]);
	if (paths)
		free(paths);
	if (cmd)
		free(cmd);
}

void	perror_cnf(char *str, char *cmd, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd("\n", fd);
}

void	ft_end_process(char *cmd_p, char **cmd, char **path, t_one_cmd *cmd_str)
{
	if (ft_strncmp(cmd_p, cmd[0], ft_strlen(cmd_p)) == 0)
		cmd_p = cmd[0];
	if (!check_builtin(cmd_str))
		execve(cmd_p, cmd, g_datas.envp);
	if (access(cmd_p, F_OK) != 0 && !check_builtin(cmd_str))
	{
		g_datas.last_command_status = 127;
		perror_cnf("command not found: ", cmd[0], 2);
	}
	free(cmd_p);
	ft_free(path, cmd);
	exit(g_datas.last_command_status);
}
