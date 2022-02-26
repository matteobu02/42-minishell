/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   struct.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hgoorick <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/11 15:16:43 by hgoorick		  #+#	#+#			 */
/*   Updated: 2022/02/25 07:40:39 by hgoorick         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_datas			t_datas;
typedef struct s_datas_cmd		t_datas_cmd;
typedef struct s_fd				t_fd;
typedef struct s_list			t_list;
typedef struct s_one_cmd		t_one_cmd;
typedef struct s_var_env		t_var_env;

struct s_datas
{
	t_datas_cmd		*cmds;
	int				pid;
	struct termios	old;
	struct termios	new;
	char			**envp;
	int				last_command_status;
	int				last_command_status_tmp;
	t_var_env		*env_in_struct;
	t_var_env		*out_struct;
};

struct s_datas_cmd
{
	char			**all_cmds;
	int				nb_cmds;
	int				type_hd;
	char			**magic_word;
	t_one_cmd		*cmd_first;
};

struct s_fd
{
	int	f_in;
	int	f_out;
};

struct s_one_cmd
{
	char		**all_cmd;
	char		*cmd;
	char		*params;
	int			infile;
	int			outfile;
	int			type_next;
	t_one_cmd	*next;
	int			fd;
};

struct s_var_env
{
	char		*var_txt;
	char		*name_var;
	t_var_env	*next;
};

struct s_list
{
	void	*content;
	t_list	*next;
};

#endif
