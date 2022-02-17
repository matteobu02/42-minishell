/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:55:03 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/20 22:58:32 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**get_path(char *env[])
{
	char	*all_path;
	char	**split_path;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		(*env)++;
	}
	all_path = ft_substr(*env, 5, ft_strlen(*env) - 5);
	split_path = ft_split_pipex(all_path, ':');
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
	write(fd, str, ft_strlen(str));
	write(fd, cmd, ft_strlen(cmd));
	write(fd, "\n", 1);
}

void	ft_end_process(char *cmd_path, char **cmd, char **paths, char **env, t_one_cmd *cmd_struct)
{
	(void)env;
	if (ft_strncmp(cmd_path, cmd[0], ft_strlen(cmd_path)) == 0)
		cmd_path = cmd[0];
	if (!check_builtin(cmd_struct))
		execve(cmd_path, cmd, env);
	if (access(cmd_path, F_OK) != 0)
		perror_cnf("command not found: ", cmd[0], 2);
	free(cmd_path);
	ft_free(paths, cmd);
	exit(127);
}
