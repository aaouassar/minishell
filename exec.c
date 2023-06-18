/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:15 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/18 17:13:26 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void path_err(void)
{
	write(2, "path dosn't exist\n", 18);
	exit(127);
}

int ft_built_parent(t_list *exec, char **env)
{
	g_glob.fdout = -1;
	ft_initialise();
	if (ft_bulitins(exec) && !exec->next)
	{
		if (open_out1(exec, 0) == 1)
			return (0);
		if (g_glob.fd_in != -1)
			dup2(g_glob.fd_in, 0);
		if (g_glob.fdout != -1)
			ft_dup(g_glob.fdout, 1);
		g_glob.g_exit_status = ft_execute_bulitins(exec, 0);
		return (0);
	}
	else
	{
		if (cmd && !exec->next)
		{
			char *str = find_path(cmd, env);
			if (str != -1)
			{
				execve();
				write(2, "bash : command not found\n", 26);
				g_glob.g_exit_status = 127;
				exit(127);
			}
		}
	}
	return (1);
}

void child_p(t_list *exec, char **env)
{
	int fd_pipe[0];

	while(exec)
	{
		if (ft_bulitins(exec) || cmd)
		{
			g_glob.pid = fork();
			if (g_glob.pid == -1)
				printf("ERREUR\n");
			if (g_glob.pid == 0)
			{
				if (g_glob.fd_in != -1)
					dup2(g_glob.fd_in, 0);
				else
				{
					dup2(fd_pipe[0], 0);
					close(fd_pipe[0]);
				}
				if (g_glob.fdout != -1)
					dup2(g_glob.fdout, 1);
				else
				{
					dup2(fd_pipe[1], 1);
					close(fd_pipe[1]);
				}
				if (ft_bulitins != -1)
					ft_execute_bulitins(exec, 0);
				else
				{
					char *str = find_path(cmd, env);
					if (str != -1)
					{
						execve();
						write(2, "bash : command not found\n", 26);
						g_glob.g_exit_status = 127;
						exit(127);
					}
				}
			}
			exec = exec->next;
			close(fd_pipe[0]);
			close(fd_pipe[1]);
		else(waitpid(g_glob.pid, NULL) != NULL)
				while waitpid(NULL, NULL)
					;
		}
	}
}

int	ft_last(t_list *exec, char **env)
{
	int	fd_pipe[0];

	if ((ft_bulitins(exec) && !exec->next) || (cmd && !cmd->next))
	{
		g_glob.pid = fork();
		if (g_glob.pid == -1)
			printf("error\n");
		if (g_glob.pid == 0)
		{
			if(g_glob.fd_in != -1)
				dup2(g_glob.fd_in, 0);
			else 
			{
				dup2(fd_pipe[0], 0);
				close(fd_pipe[1]);
			}
			if (g_glob.fdout != -1)
				dup2(g_glob.fdout, 1);
			if (ft_bulitins(exec) != -1)
				ft_execute_bulitins(exec, 0);
			else 
			{
				char *str = find_path(cmd, env);
					if (str != -1)
					{
						execve();
						write(2, "bash : command not found\n", 26);
						g_glob.g_exit_status = 127;
						exit(127);
					}
			}
			
		}
	}
}



	// if (ft_bulitins(exec))
	// {
	// 	g_glob.g_child = 1;
	// 	g_glob.g_exit_status = ft_execute_bulitins(exec, 1);
	// 	exit(0);
	// }
	// else
	// {
	// 	if (((t_data *)exec->content)->args)
	// 	{
	// 		if (execve(find_path(((t_data *)exec->content)->args[0], \
	// 		g_glob.envp), ((t_data *)exec->content)->args, g_glob.envp) == -1)
	// 			(ft_ree(exec), exit(g_glob.g_exit_status));
	// 	}
	// 	else
	// 		exit(0);
	// }


void ft_start_exec(t_list *exec)
{
	t_list *lst;
	int p[2];

	lst = exec;
	if (ft_built_parent(exec) == 0)
		return;
	while (exec)
	{
		piping(p);
		g_glob.pid = fork();
		if (err_fork() != 0)
			break;
		if (g_glob.pid == 0)
		{
			child_p(exec, p, g_glob.copy_fd);
		}
		// close(p[1]);
		// if (g_glob.copy_fd != -1)
		// 	close(g_glob.copy_fd);
		// g_glob.copy_fd = p[0];
		// exec = exec->next;
	}
}
