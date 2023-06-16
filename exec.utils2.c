/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:03:01 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 14:48:18 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialise(void)
{
	g_glob.copy_fd = -1;
	g_glob.tmpin = dup(0);
	g_glob.tmpout = dup(1);
	g_glob.g_child = 0;
}

void	piping(pid_t *p)
{
	pipe(p);
}

void	ft_dup(int fd, int end)
{
	dup2(fd, end);
	close(fd);
}

int	err_inf(t_list *exec)
{
	if (((t_data *)exec->content)->inf)
	{
		open_out1(exec, 0);
		write(2, "minishell: ", 11);
		write(2, ((t_data *)exec->content)->inf, \
		ft_strlen(((t_data *)exec->content)->inf));
		write(2, ": No such file or directory\n", 28);
		g_glob.g_exit_status = 127;
		return (1);
	}
	return (0);
}

// void	wait_pids(t_list *exec, int *p)
// {
// 	int		status;

// 	while (exec)
// 	{
// 		waitpid(g_glob.pid, &status, 0);
// 		if (g_glob.pid != -1 && g_glob.last == 0)
// 		{
// 			if (WIFEXITED(status))
// 				g_glob.g_exit_status = WEXITSTATUS(status);
// 			if (WIFSIGNALED(status))
// 				g_glob.g_exit_status = 128 + WTERMSIG(status);
// 		}
// 		g_glob.last = 0;
// 		while (wait(NULL) != -1)
// 			;
// 		exec = exec->next;
// 	}
// 	close(p[0]);
// 	close(p[1]);
// }





