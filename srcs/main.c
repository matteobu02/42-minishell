/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:14:40 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/18 15:54:23 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : print_test
*	Params : Strcut de datas_prompt
*	Retour : void
*	Descritpion:
*		Affiche le contenu de toutes les commandes une par une
*
****************************************/
/*
void	print_test(t_datas_prompt datas_prompt)
{
	int			y;
	t_one_cmd	*x;

	x = datas_prompt.cmds->cmd_first;
	while (x->next)
	{
		ft_putstr_fd("\n------------------------\nCmd : ", 1);
		ft_putstr_fd(x->cmd, 1);
		ft_putstr_fd("\nParams : ", 1);
		y = 0;
		while (++y < ft_matrixlen(x->all_cmd))
		{
			ft_putstr_fd(x->all_cmd[y], 1);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd("\nInfile Outfile : ", 1);
		ft_putnbr_fd(x->infile, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(x->outfile, 1);
		ft_putstr_fd("\nType next : ", 1);
		ft_putnbr_fd(x->type_next, 1);
		ft_putstr_fd("\nType hd : ", 1);
		ft_putnbr_fd(x->type_hd, 1);
		ft_putstr_fd("\nMagic word : ", 1);
		ft_putstr_fd(x->magic_word, 1);
		x = x->next;
	}
	ft_putstr_fd("\n------------------------\nCmd : ", 1);
	ft_putstr_fd(x->cmd, 1);
	ft_putstr_fd("\nParams : ", 1);
	y = 0;
	while (++y < ft_matrixlen(x->all_cmd))
	{
		ft_putstr_fd(x->all_cmd[y], 1);
		ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd("\nInfile Outfile : ", 1);
	ft_putnbr_fd(x->infile, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(x->outfile, 1);
	ft_putstr_fd("\nType next : ", 1);
	ft_putnbr_fd(x->type_next, 1);
	ft_putstr_fd("\nType hd : ", 1);
	ft_putnbr_fd(x->type_hd, 1);
	ft_putstr_fd("\nMagic word : ", 1);
	ft_putstr_fd(x->magic_word, 1);
	ft_putstr_fd("\n", 1);
}*/


/****************************************
*
*	Nom : init_data_prompt
*	Params : Pointeur de la struct datas_prompt
*	Retour : void
*	Descritpion:
*		init les donnees de bases pour la struct datas_prompt
*
****************************************/

void	init_data_prompt(t_datas_prompt *datas_prompt, char **envp)
{
	datas_prompt->envp = ft_matrixlcpy(envp, ft_matrixlen(envp));

	datas_prompt->env_in_struct = conv_env(envp);
	if (!datas_prompt->env_in_struct)
		exit(1);
	datas_prompt->last_command_status = 0;
	datas_prompt->out_struct = NULL;
	datas_prompt->old_command = NULL;
	datas_prompt->cmds = NULL;
	ft_putstr_fd("\033[2J", 1);
	ft_putstr_fd(INPUT, 1);
}

int	find_builtin(t_one_cmd *cmd)
{
	if (!ft_strncmp("cd", cmd->cmd, 2))
		cd(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else if (!ft_strncmp("echo", cmd->cmd, 4))
		echo(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else if (!ft_strncmp("env", cmd->cmd, 3))
		env();
	else if (!ft_strncmp("pwd", cmd->cmd, 3))
		pwd();
	//else if (!ft_strncmp("export", cmd->cmd, 6))
		//export(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
	else if (!ft_strncmp("unset", cmd->cmd, 5))
		unset(ft_matrixlen(cmd->all_cmd), cmd->all_cmd);
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

char **conv_env_to_mat(void)
{
	char **out_mat;
	int x;
	t_var_env	*tmp;

	x = ft_lstsize_up(datas_prompt.env_in_struct);
	out_mat = malloc(sizeof(char *) * (x + 1));
	tmp  = datas_prompt.env_in_struct;
	out_mat[x] = NULL;
	while (--x > -1)
	{
		out_mat[x] = malloc(sizeof(char) * (ft_strlen(tmp->var_txt) + ft_strlen(tmp->name_var) + 2));
		ft_strlcpy(out_mat[x], tmp->name_var, ft_strlen(tmp->name_var));
		ft_strlcpy(&out_mat[x][ft_strlen(tmp->name_var)], "=", 1);
		ft_strlcpy(&out_mat[x][ft_strlen(tmp->name_var) + 1], tmp->var_txt, ft_strlen(tmp->var_txt));
		tmp = tmp->next;
	}
	return(out_mat);
}

int	main(int argc, char **argv, char **envp)
{
	char			*prompt;
	char			*test;
	int				fd[2];
	int x;

	fd[0] = 6;
	fd[1] = 6;
	(void)argc;
	(void)argv;
	init_data_prompt(&datas_prompt, envp);
	while (5)
	{
		prompt = start_prompt(envp);
		test = readline(prompt);
		if (test[0] && ft_allisspace(test) != -1)
		{
			x = ft_strchr_up(test, ' ');
			if ((ft_strchr_up(test, '=') && (ft_strchr_up(test, '"') == 0 || ft_strchr_up(test, '"') > ft_strchr_up(test, '='))))
			{
				datas_prompt.out_struct = ft_new_var_env(test, datas_prompt.out_struct);
				if (!datas_prompt.out_struct)
					exit (0);
			}
			else
			{
				datas_prompt.cmds = gen_datas_cmd(test, &datas_prompt);
				if (datas_prompt.cmds)
			//	print_test(datas_prompt);
				{
					if (datas_prompt.cmds->type_hd)
						ft_here_doc(datas_prompt.cmds, datas_prompt.cmds->magic_word[0]);
					pipe_rec(datas_prompt.cmds, datas_prompt.envp, fd, datas_prompt.cmds->cmd_first);
					ft_free_datas_cmd(datas_prompt.cmds);
				}
			}
			add_history(test);
			ft_clean_mat(datas_prompt.envp);
			datas_prompt.envp = conv_env_to_mat();
		}
		if (datas_prompt.old_command)
			free(datas_prompt.old_command);
		datas_prompt.old_command = test;
		free(prompt);
	}
	ft_new_free(datas_prompt.env_in_struct);
	if (datas_prompt.out_struct)
		ft_new_free(datas_prompt.out_struct);
}
