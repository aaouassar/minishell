/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:45:07 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/17 20:35:57 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_loop(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

char	**ft_delete_element(char **env, int n)
{
	int		i;
	int		j;
	char	**new;

	i = -1;
	j = -1;
	new = (char **)malloc(sizeof(char *) * (ft_count_args(env) - 1));
	while (env[++i])
		if (i != n)
			new[++j] = ft_strdup(env[i]);
	new[j + 1] = NULL;
	free_loop(env);
	return (new);
}

void	ft_unset_env(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!ft_strncmp(str, "PATH", 3))
		g_glob.env = 1;
	while (g_glob.envp[++i])
	{
		tmp = g_v_n(g_glob.envp[i]);
		if (!ft_strncmp(tmp, str, ft_big_len(ft_strlen(tmp), ft_strlen(str))))
		{
			g_glob.envp = ft_delete_element(g_glob.envp, i--);
			free(tmp);
			break ;
		}
		free(tmp);
	}
}

void	ft_unset_expo(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_glob.exp[++i])
	{
		tmp = ft_new_line(str, NULL);
		if (!ft_strncmp(g_glob.exp[i], tmp,
				ft_big_len(ft_strlen(tmp), ft_get_index(g_glob.exp[i], '='))))
		{
			g_glob.exp = ft_delete_element(g_glob.exp, i--);
			free(tmp);
			break ;
		}
		free(tmp);
	}
}

int	ft_unset_cmmd(char **args)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = args;
	while (tmp[++i])
	{
		if (!tmp[i] || ft_checkin_error(tmp[i]))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", args[1]);
			g_glob.g_exit_status = 1;
			continue ;
		}
		ft_unset_env(tmp[i]);
		ft_unset_expo(tmp[i]);
	}
	return (g_glob.g_exit_status);
}
