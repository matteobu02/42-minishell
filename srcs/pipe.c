/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:51:00 by lbuccher          #+#    #+#             */
/*   Updated: 2022/02/26 12:48:34 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	process(char *env[], char **cmd, t_one_cmd *cmd_struct, int to_exec)
{
	char	**paths;
	char	*cmd_path;

	if (ft_strlen(cmd_struct->cmd) > 2 && cmd_struct->cmd[0] == '.'
		&& cmd_struct->cmd[1] == '/' && to_exec)
		ft_end_process(cmd_struct->cmd, cmd_struct->all_cmd, NULL, cmd_struct);
	paths = get_path(env);
	if (no_path(paths, cmd, cmd_struct, to_exec))
		return ;
	cmd_path = find_cmd_path(paths, cmd_struct, cmd);
	if (to_exec)
		ft_end_process(cmd_path, cmd, paths, cmd_struct);
	if (paths)
		ft_clean_mat(paths);
}

static void	i_find_a_signal(int this_signal)
{
	if (this_signal == SIGQUIT)
	{
		ft_putstr_fd("^\\QUIT: 3", 1);
		g_datas.last_command_status_tmp = 131;
		kill(g_datas.pid, SIGKILL);
	}
	else
	{
		ft_putstr_fd("^C", 1);
		g_datas.last_command_status_tmp = 130;
	}
	ft_putstr_fd("\n", 1);
}

void	child_process(t_datas_cmd *cds, t_one_cmd *cm, int n_fd[2], int p_fd[2])
{
	if (cds->nb_cmds == 1)
	{
		if (dup2(cm->outfile, 1) < 0 || dup2(cm->infile, 0) < 0)
			return (perror("fd"));
	}
	else
		multi_pipe(cds, n_fd, p_fd, cm);
	if (!check_builtin(cm))
		process(g_datas.envp, cm->all_cmd, cm, 1);
	else
	{
		find_builtin(cm);
		process(g_datas.envp, cm->all_cmd, cm, 0);
		exit(0);
	}
}

void	pipe_rec_2(t_datas_cmd *cmds, t_one_cmd *cmd, int tmp, int n_fd[2])
{
	if ((g_datas.last_command_status_tmp == 130
			|| g_datas.last_command_status_tmp == 131))
		g_datas.last_command_status = g_datas.last_command_status_tmp;
	else
		g_datas.last_command_status = tmp / 255;
	if (cmd->cmd)
		find_builtin_env(cmd);
	if (cmd->next)
		pipe_rec(cmds, g_datas.envp, n_fd, cmd->next);
	else
		process(g_datas.envp, cmd->all_cmd, cmd, 0);
	close_pipe(n_fd);
}

void	pipe_rec(t_datas_cmd *cmds, char **env, int pre_fd[2], t_one_cmd *cmd)
{
	int		next_fd[2];
	pid_t	pid;
	int		tmp;

	(void)env;
	g_datas.last_command_status_tmp = 0;
	if (!(!ft_strlen(cmd->cmd) || ft_strncmp(cmd->cmd, "exit", 4)))
		ft_exit();
	if (pipe(next_fd) == -1)
		return (perror("pipe"));
	pid = fork();
	g_datas.pid = pid;
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
		child_process(cmds, cmd, next_fd, pre_fd);
	else
	{
		close_pipe(pre_fd);
		signal(SIGINT, i_find_a_signal);
		signal(SIGQUIT, i_find_a_signal);
		waitpid(pid, &tmp, 0);
		pipe_rec_2(cmds, cmd, tmp, next_fd);
	}
}
