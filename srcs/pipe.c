/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:51:00 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/12 17:08:52 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	process(char *env[], char **cmd, t_one_cmd *cmd_struct)
{
	int		i;
	char	*tmp;
	char	**paths;
	char	*cmd_path;

	i = -1;
	paths = get_path(env);
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		if (ft_strncmp(cmd_path, cmd[0], ft_strlen(cmd_path)) == 0)
			break ;
		tmp = ft_strjoin(cmd_path, cmd[0]);
		free(cmd_path);
		cmd_path = tmp;
		if (!access(cmd_path, F_OK))
			break ;
		if (paths[i + 1])
			free(cmd_path);
	}
	ft_end_process(cmd_path, cmd, paths, env, cmd_struct);
}

void	ft_redirection(int fd_in, int fd_out, int simple, int first)
{
	if (simple == 1 && first == 1)
	{
		close(fd_in);
		if (dup2(fd_out, 1) < 0)
			return (perror("first: fd"));
		close(fd_out);
	}
	else if (simple == 1 && first == 0)
	{
		close(fd_out);
		if (dup2(fd_in, 0) < 0)
			return (perror("last: fd"));
		close(fd_in);
	}
	else
	{
		if (dup2(fd_out, 1) < 0 || dup2(fd_in, 0) < 0)
			return (perror("middle: fd"));
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

// fonction pour norme pipe rec

void	pipe_rec(t_datas_cmd *cmds, char *env[], int pre_fd[2], t_one_cmd *cmd)
{
	int		next_fd[2];
	pid_t	pid;

	if (!ft_strlen(cmd->cmd) || ft_strncmp("exit", cmd->cmd, \
		ft_strlen(cmd->cmd)))
	{
		if (pipe(next_fd) == -1)
			return (perror("pipe"));
		pid = fork();
		if (pid < 0)
			return (perror("fork"));
		if (pid == 0)
		{
			if (cmds->nb_cmds == 1)
			{
				if (dup2(cmd->outfile, 1) < 0 || dup2(cmd->infile, 0) < 0)
					return (perror("one cmd: fd"));
			}
			else
				multi_pipe(cmds, next_fd, pre_fd, cmd);
			process(env, cmd->all_cmd, cmd);
		}
		else
		{
			close_pipe(pre_fd);
			waitpid(pid, NULL, 0);
			if (cmd->next)
				pipe_rec(cmds, env, next_fd, cmd->next);
			close_pipe(next_fd);
		}
	}
	else
		ft_exit();
}
