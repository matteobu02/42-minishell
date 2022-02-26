/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hgoorick <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/10 18:14:40 by hgoorick		  #+#	#+#			 */
/*   Updated: 2022/02/25 07:38:22 by hgoorick         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

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
	tcgetattr(0, &datas_prompt->old);
	tcgetattr(0, &datas_prompt->new);
	datas_prompt->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &datas_prompt->new);
	datas_prompt->envp = ft_matrixlcpy(envp, ft_matrixlen(envp));
	if (!datas_prompt->envp)
		return ;
	datas_prompt->env_in_struct = conv_env(envp);
	if (!datas_prompt->env_in_struct)
	{
		ft_clean_mat(datas_prompt->envp);
		return ;
	}
	datas_prompt->last_command_status = 0;
	datas_prompt->pid = 0;
	datas_prompt->out_struct = NULL;
	datas_prompt->cmds = NULL;
	ft_putstr_fd(INPUT, 1);
}

static void	i_find_a_signal(int this_signal)
{
	if (this_signal == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_redisplay();
		datas_prompt.last_command_status = 1;
	}
}

void	exec(char *test)
{
	int	fd[2];

	fd[0] = 6;
	fd[1] = 6;
	datas_prompt.cmds = gen_datas_cmd(test);
	free(test);
	if (datas_prompt.cmds)
	{
		if (datas_prompt.cmds->type_hd)
			ft_here_doc(datas_prompt.cmds->magic_word);
		pipe_rec(datas_prompt.cmds, datas_prompt.envp, fd, \
			datas_prompt.cmds->cmd_first);
		ft_free_datas_cmd(datas_prompt.cmds);
	}
}

void	need_to_exit(void)
{
	ft_clean_mat(datas_prompt.envp);
	ft_new_free(datas_prompt.env_in_struct);
	if (datas_prompt.out_struct)
		ft_new_free(datas_prompt.out_struct);
	ft_putstr_fd("exit\n", 1);
	tcsetattr(0, TCSANOW, &datas_prompt.new);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	char			*prompt;
	char			*test;

	(void)argc;
	(void)argv;
	init_data_prompt(&datas_prompt, envp);
	if (!datas_prompt.envp)
		exit (1);
	while (19)
	{
		signal(SIGINT, i_find_a_signal);
		signal(SIGQUIT, SIG_IGN);
		rl_on_new_line();
		prompt = start_prompt(envp);
		test = readline(prompt);
		add_history(test);
		free(prompt);
		if (test && test[0] && ft_allisspace(test) != -1)
			exec(test);
		else if (!test)
			need_to_exit();
	}
}
