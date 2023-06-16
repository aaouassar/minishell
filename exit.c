/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:00:54 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:33:11 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_args(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
		i++;
	return (i + 1);
}

void	ft_numeric(char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (args[i] != NULL)
	{
		while (args[1][j])
		{
			if ((args[1][0] == '-' || args[1][0] == '+') && args[1][1] == '0'
			&& !atoi(&args[1][1]))
				(printf("exit\n"), exit(0));
			if (args[1][j] != '0' && !atoi(&args[1][j]))
			{
				write(2, "minishell: exit: ", 17);
				write(2, args[1], ft_strlen(args[1]));
				write(2, ": numeric argument required\n", 28);
			}
			j++;
		}
		i++;
	}
}

int	ft_exit_cmmd(char **args)
{
	long long	len;

	len = ft_count_args(args);
	if (!args[1])
		(printf("exit\n"));
	ft_numeric(args);
	write(2, &len, 4);
	if (len > 3)
		write(2, "exit\nminishell: exit: too many arguments\n", 41);
	else if (len == 3)
	{
		len = atoi(args[1]);
		if (args[1][0] != '-' && len < 0)
		{
			write(2, "minishell: exit: ", 17);
			write(2, args[1], ft_strlen(args[1]));
			write(2, ": numeric argument required\n", 28);
			exit(255);
		}
		else
			(printf("exit\n"), exit(atoi(args[1])));
	}
	return (1);
}

// int main(int ac , char **av)
// {
// 	int i = ft_exit_cmmd(av);
// }
