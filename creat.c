/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:29 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:33:51 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_env(char **strs, char *arg)
{
	char	**args;
	int		i;

	if (!strs[0])
	{
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = ft_strdup(arg);
		args[1] = NULL;
		free(strs);
		return (args);
	}
	args = (char **)malloc(sizeof(char *) * (ft_count_args(strs) + 1));
	i = -1;
	while (strs[++i])
	{
		args[i] = ft_strdup(strs[i]);
		free(strs[i]);
	}
	args[i] = ft_strdup(arg);
	free(strs);
	args[i + 1] = NULL;
	return (args);
}

char	*g_variable(char *str)
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

char	**create_envp(char **envp)
{
	char	**env;
	int		i;

	i = -1;
	env = calloc(1, sizeof(char *));
	while (envp[++i])
		env = add_env(env, envp[i]);
	return (env);
}

char	**creat_export(char **env)
{
	int		i;
	char	*tmp;
	char	*vtmp;
	char	*value;
	char	**export;

	i = -1;
	export = calloc(1, sizeof(char *));
	while (env[++i])
	{
		tmp = NULL;
		tmp = ft_strjoin(tmp, "declare -x ");
		vtmp = g_variable(env[i]);
		tmp = ft_strjoin(tmp, vtmp);
		free(vtmp);
		tmp = ft_strjoin(tmp, "=\"");
		value = ft_strdup(env[i] + ft_get_index(env[i], '=') + 1);
		tmp = ft_strjoin(tmp, value);
		free(value);
		tmp = ft_strjoin(tmp, "\"");
		export = add_env(export, tmp);
		free(tmp);
	}
	return (export);
}
