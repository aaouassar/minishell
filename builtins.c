/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:25 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:51:55 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



t_data	*init_data(char **envp)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	data->args = NULL;
	data->error = 0;
	data->inf = NULL;
	data->infiles = NULL;
	data->n_infiles = 0;
	data->outfiles = NULL;
	data->append = NULL;
	data->hd = NULL;
	data->if_hd = 0;
	if (g_glob.g_env == 0)
	{
		g_glob.envp = create_envp(envp);
		g_glob.g_env = 1;
	}
	if (g_glob.g_exp == 0)
	{
		g_glob.exp = creat_export(envp);
		g_glob.g_exp = 1;
	}
	return (data);
}

int	ft_bulitins(t_list *exec)
{
	if (!exec)
		return (0);
	if (!((t_data *)exec->content)->args)
		return (0);
	if (!ft_strncmp(((t_data *)exec->content)->args[0], "cd", 3))
		return (1);
	if (!ft_strncmp(((t_data *)exec->content)->args[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "env", 4))
		return (1);
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "export", 7))
		return (1);
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "unset", 6))
		return (1);
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "exit", 6))
		return (1);
	return (0);
}

int	ft_execute_bulitins(t_list *exec, int mode)
{
	if (!ft_strncmp(((t_data *)exec->content)->args[0], "cd", 3))
		return (ft_cd_cmmd(((t_data *)exec->content)->args));
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "pwd", 4))
		return (ft_pwd_cmmd());
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "echo", 5))
		ft_echo_cmmd(((t_data *)exec->content)->args);
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "env", 4))
		return (ft_env_cmmd());
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "export", 7))
		return (ft_export_cmmd(exec));
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "unset", 6))
		return (ft_unset_cmmd(((t_data *)exec->content)->args));
	else if (!ft_strncmp(((t_data *)exec->content)->args[0], "exit", 6))
		return (ft_exit_cmmd(((t_data *)exec->content)->args));
	if (mode == 0)
		return (0);
	exit(1);
}
// int main()
// {
// 	int mode = 0;
// 	t_list	*exec;

// 	exec = malloc(sizeof(t_list));
	
// 	exec->content = (char *)malloc(sizeof(char) * 7 + 1);
// 	exec->content[0] = 'e';
// 	exec->content[1] = 'c';
// 	exec->content[2] = 'h';
// 	exec->content[3] = 'o';
// 	exec->content[4] = ' ';
// 	exec->content[5] = 'h';
// 	exec->content[6] = 'i';
// 	exec->content[7] = '\0';
	
// 	// printf ("%s\n", exec->content);

// 	ft_execute_bulitins(exec, mode);
// }