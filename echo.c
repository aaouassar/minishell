/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:00:25 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:30:08 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_option(char *args)
{
	int	i;

	i = 2;
	if (args && (args[0] == '-' && args[1] == 'n'))
	{
		while (args[i] == 'n')
			i++;
		if (args[i] == '\0')
			return (1);
	}
	return (0);
}

int	ft_echo_cmmd(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!args[1])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (ft_check_option(args[1]) && !args[2])
		return (0);
	while (ft_check_option(args[++i]))
		j++;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i] && args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!j)
		ft_putstr_fd("\n", 1);
    return(0);
}

// int main(int ac , char **av)
// {
//     ft_echo_cmmd(av);
// }
