/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:44:11 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:33:51 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_expo(char *name, char *value, int exist)
{
	int		j;
	char	*tmp;

	j = -1;
	tmp = ft_new_line(name, value);
	if (exist)
	{
		while (value && g_glob.exp[++j])
		{
			if (!ft_strncmp(g_glob.exp[j], tmp,
					ft_big_len(ft_get_index(g_glob.exp[j], '='), ft_get_index(tmp, '='))))
			{
				free(g_glob.exp[j]);
				g_glob.exp[j] = ft_strdup(tmp);
				free(tmp);
				return ;
			}
		}
	}
	else
		g_glob.exp = add_env(g_glob.exp, tmp);
	free(tmp);
}

char	*ft_join_tmp(char *tmp, char *name, char *value)
{
	tmp = calloc(1, sizeof(char));
	tmp = ft_strjoin(tmp, name);
	tmp = ft_strjoin(tmp, "=");
	tmp = ft_strjoin(tmp, value);
	return (tmp);
}

void	ft_set_env(char *name, char *value)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	tmp = NULL;
	if (!value)
		return ;
	tmp = ft_join_tmp(tmp, name, value);
	while (g_glob.envp[++i])
	{
		tmp2 = g_v_n(g_glob.envp[i]);
		if (!ft_strncmp(tmp2, name, ft_big_len(ft_strlen(tmp2), ft_strlen(name))))
		{
			free(g_glob.envp[i]);
			g_glob.envp[i] = ft_strdup(tmp);
			free(tmp);
			free(tmp2);
			return ;
		}
		free(tmp2);
	}
	g_glob.envp = add_env(g_glob.envp, tmp);
	free(tmp);
}

void	ft_new_env(t_list *exec)
{
	int		i;
	char	**tmp;
	char	*nom;
	char	*val;

	i = 0;
	tmp = ((t_data *)exec->content)->args;
	while (tmp[++i])
	{
		val = NULL;
		nom = ft_get_name(tmp[i]);
		if ((!nom || !nom[0]) || ft_checkin_error(nom))
		{
			(ft_error_export(tmp[i]), free(nom));
			continue ;
		}
		if (ft_strchr(tmp[i], '='))
			val = ft_strdup(tmp[i] + ft_get_index(tmp[i], '=') + 1);
		if (ft_exist(nom) != -1)
			(ft_set_env(nom, val), ft_set_expo(nom, val, 1));
		else
			(ft_set_env(nom, val), ft_set_expo(nom, val, 0));
		free(nom);
		free(val);
	}
}

int	ft_export_cmmd(t_list *exec)
{
	int		len;
	int		i;

	i = -1;
	len = ft_count_args(((t_data *)exec->content)->args);
	if (len == 2)
		while (g_glob.exp[++i])
			printf("%s\n", g_glob.exp[i]);
	else
		ft_new_env(exec);
	return (0);
}
