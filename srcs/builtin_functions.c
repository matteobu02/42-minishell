/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mbucci <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/01/26 14:49:11 by mbucci			#+#	#+#			 */
/*   Updated: 2022/02/26 03:08:26 by mbucci           ###   ########.fr       */
/*																			*/
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

	tmp = datas_prompt.cmds->cmd_first->all_cmd;
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
	//char	**tmp;
	int	val_return;

	/*tmp = malloc(sizeof(char *) * 3);
	 if (tmp)
	 {
	 tmp[0] = "rm";
	 tmp[1] = "-f";
	 tmp[2] = "tmp";
	 execve("/bin/rm", tmp, datas_prompt.envp);
	 free(tmp);
	 }*/
	ft_putstr_fd("exit\n", 1);
	val_return = ft_exit_all();
	ft_free_datas_cmd(datas_prompt.cmds);
	ft_new_free(datas_prompt.env_in_struct);
	if (datas_prompt.out_struct)
		ft_new_free(datas_prompt.out_struct);
	tcsetattr(0, TCSANOW, &datas_prompt.new);
	exit (val_return);
}
