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
*	Params : Pointeur de la struct g_datas
*	Retour : void
*	Descritpion:
*		init les donnees de bases pour la struct g_datas
*
****************************************/

void	init_data_prompt(t_datas *g_datas, char **envp)
{
	tcgetattr(0, &g_datas->old);
	tcgetattr(0, &g_datas->new);
	g_datas->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &g_datas->new);
	g_datas->envp = ft_matrixlcpy(envp, ft_matrixlen(envp));
	if (!g_datas->envp)
		return ;
	g_datas->env_in_struct = conv_env(envp);
	if (!g_datas->env_in_struct)
	{
		ft_clean_mat(g_datas->envp);
		return ;
	}
	g_datas->last_command_status = 0;
	g_datas->pid = 0;
	g_datas->out_struct = NULL;
	g_datas->cmds = NULL;
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
		g_datas.last_command_status = 1;
	}
}

void	exec(char *test)
{
	int	fd[2];

	fd[0] = 6;
	fd[1] = 6;
	g_datas.cmds = gen_datas_cmd(test);
	free(test);
	if (g_datas.cmds)
	{
		if (g_datas.cmds->type_hd)
			ft_here_doc(g_datas.cmds->magic_word);
		pipe_rec(g_datas.cmds, g_datas.envp, fd, \
			g_datas.cmds->cmd_first);
		ft_free_datas_cmd(g_datas.cmds);
	}
}

void	need_to_exit(void)
{
	ft_clean_mat(g_datas.envp);
	ft_new_free(g_datas.env_in_struct);
	if (g_datas.out_struct)
		ft_new_free(g_datas.out_struct);
	ft_putstr_fd("exit\n", 1);
	tcsetattr(0, TCSANOW, &g_datas.new);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	char			*prompt;
	char			*test;

	(void)argc;
	(void)argv;
	init_data_prompt(&g_datas, envp);
	if (!g_datas.envp)
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
