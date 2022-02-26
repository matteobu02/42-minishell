/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:13:45 by lbuccher          #+#    #+#             */
/*   Updated: 2022/02/26 02:10:27 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	no_path(char **paths, char **cmd, t_one_cmd *c_stru, int to_ex)
{
	if (!paths && to_ex)
	{
		if (access(c_stru->cmd, F_OK) == 0)
		{
			ft_clean_mat(paths);
			execve(c_stru->cmd, cmd, g_datas.envp);
		}
		else if (!check_builtin(c_stru))
		{
			perror_cnf("command not found: ", cmd[0], 2);
			g_datas.last_command_status = 127;
			exit (127);
		}
		return (1);
	}
	else if (!paths && !to_ex)
		return (1);
	return (0);
}

char	*find_cmd_path(char **paths, t_one_cmd *c_stru, char **cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = -1;
	while (c_stru->cmd && paths && paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		if (!cmd_path)
			clean_mat_and_exit(paths);
		if (ft_strncmp(cmd_path, cmd[0], ft_strlen(cmd_path)) == 0)
			break ;
		tmp = ft_strjoin(cmd_path, cmd[0]);
		free(cmd_path);
		if (!tmp)
			clean_mat_and_exit(paths);
		cmd_path = tmp;
		if (!access(cmd_path, F_OK))
			break ;
		if (paths[i + 1])
			free(cmd_path);
	}
	return (cmd_path);
}

void	ft_redirection(int fd_in, int fd_out, int simple, int first)
{
	if (simple == 1 && first == 1)
	{
		close(fd_in);
		if (dup2(fd_out, 1) < 0)
			return (perror("fd"));
		close(fd_out);
	}
	else if (simple == 1 && first == 0)
	{
		close(fd_out);
		if (dup2(fd_in, 0) < 0)
			return (perror("fd"));
		close(fd_in);
	}
	else
	{
		if (dup2(fd_out, 1) < 0 || dup2(fd_in, 0) < 0)
		{
			ft_putnbr_fd(fd_out, 1);
			ft_putnbr_fd(fd_in, 1);
			return (perror("fd"));
		}
		close(fd_out);
		close(fd_in);
	}
}

void	multi_pipe(t_datas_cmd *cmds, int n_fd[2], int pr_fd[2], t_one_cmd *cmd)
{
	if (cmd->type_next == 2)
	{
		if (cmd->infile == 0)
			ft_redirection(n_fd[0], n_fd[1], 1, 1);
		else
			ft_redirection(cmd->infile, n_fd[1], 0, 1);
	}
	else if (cmds->nb_cmds > 1 && cmd->type_next != 0)
	{
		close(pr_fd[1]);
		close(n_fd[0]);
		ft_redirection(pr_fd[0], n_fd[1], 0, 0);
	}
	else if (cmds->nb_cmds > 1 && cmd->type_next == 0)
	{
		if (cmd->outfile == 1)
			ft_redirection(pr_fd[0], pr_fd[1], 1, 0);
		else
		{
			close(pr_fd[1]);
			ft_redirection(pr_fd[0], cmd->outfile, 0, 0);
		}
	}
}

void	clean_mat_and_exit(char **paths)
{
	ft_clean_mat(paths);
	exit (1);
}
