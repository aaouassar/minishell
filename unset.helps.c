/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:44:32 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 15:37:15 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_acceptable(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

int	ft_checkin_error(char *arg)
{
	int	i;

	if (ft_isdigit(arg[0]) || !ft_isalpha(arg[0]))
		return (1);
	i = 1;
	while (arg[i])
	{
		if (!ft_acceptable(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_error_unset(char *name)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(name, 2);
	//ft_putendl_fd("': not a valid identifier", 2);
	// g_glob.g_exit_status = 1;
}

void	ft_error_export(char *name)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(name, 2);
	//ft_putendl_fd("': not a valid identifier", 2);
	// g_glob.g_exit_status = 1;
}

char	*g_v_n(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = malloc(sizeof(char) * ft_get_index(str, '=') + 1);
	if (!tmp)
		return (NULL);
	while (++i < ft_get_index(str, '='))
		tmp[i] = str[i];
	tmp[i] = 0;
	return (tmp);
}
