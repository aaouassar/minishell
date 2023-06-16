/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:44:42 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 15:57:09 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_cmmd(void)
{
	int	i;

	i = -1;
	if (g_glob.env == 1)
	{
		write(2, "minishell: env: No such file or directory\n", 42);
		return (1);
	}
	else
		while (g_glob.envp[++i])
			printf("%s\n", g_glob.envp[i]);
	return (0);
}

// int main(int ac , char **av)
// {
// 	ft_env_cmmd();
// }