/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.helps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:44:45 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:53:11 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialiser(void)
{
	g_glob.g_exit_status = 0;
	g_glob.g_exp = 0;
	g_glob.env = 0;
	g_glob.last = 0;
	g_glob.pwd = NULL;
}

char	*ft_new_line(char *name, char *value)
{
	char	*tmp;

	tmp = calloc(1, sizeof(char));
	tmp = ft_strjoin(tmp, "declare -x ");
	tmp = ft_strjoin(tmp, name);
	if (value)
	{
		tmp = ft_strjoin(tmp, "=\"");
		tmp = ft_strjoin(tmp, value);
		tmp = ft_strjoin(tmp, "\"");
	}
	return (tmp);
}

char	*ft_get_name(char *str)
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

int	ft_exist(char *name)
{
	int		i;
	char	*tmp;

	tmp = ft_new_line(name, NULL);
	i = -1;
	while (g_glob.exp[++i])
	{
		if (ft_strncmp(g_glob.exp[i], tmp, \
				ft_big_len(ft_get_index(g_glob.exp[i], '='), ft_strlen(tmp))) == 0)
		{
			free(tmp);
			return (i);
		}
	}
	free(tmp);
	return (-1);
}

int	ft_get_index(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (i);
}

int	ft_big_len(int s1, int s2)
{
	if (s1 > s2)
		return (s1);
	return (s2);
}

