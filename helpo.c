/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:21:02 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:25:45 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	norm(t_list *exec, int *p, int copy_fd)
{
	g_glob.fdout = -1;
	close(p[0]);
	if (exec->next)
		ft_dup(p[1], 1);
	open_out(exec, 0);
	if (g_glob.fdout != -1)
		ft_dup(g_glob.fdout, 1);
	if (copy_fd != -1)
		ft_dup(copy_fd, 0);
	if (((t_data *)exec->content)->infiles)
		ft_dup(((t_data *)exec->content)->\
		infiles[((t_data *)exec->content)->n_infiles - 1], 0);
}

void	ft_ree(t_list *exec)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(((t_data *)exec->content)->args[0], 2);
	// ft_putstr_fd(": ", 2);
	// ft_putendl_fd(strerror(errno), 2);
	g_glob.g_exit_status = 126;
}

int	err_fork(void)
{
	if (g_glob.pid == -1)
	{
		write(2, "bash: fork: Resource temporarily unavailable\n", 45);
		return (1);
	}
	return (0);
}

void	error_msg(char *str, int err)
{
	(void)err;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	// ft_putstr_fd(": ", 2);
	// ft_putendl_fd(strerror(err), 2);
}
