/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:30:01 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 15:57:50 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *str)
{
	int	i;

	i = 0;
	if (!g_glob.envp)
		return (NULL);
	while (g_glob.envp[i] != NULL)
	{
		if (ft_strncmp(g_glob.envp[i], str, ft_strlen(str)) == 0)
			return (g_glob.envp[i] + ft_strlen(str));
		i++;
	}
	return (NULL);
}

void	ft_update_pwd(void)
{
	int	i;

	i = 0;
	while (g_glob.envp[i] != NULL)
	{
		if (ft_strncmp(g_glob.envp[i], "PWD=", 4) == 0)
		{
			free(g_glob.envp[i]);
			g_glob.envp[i] = ft_strjoin(ft_strdup("PWD="), g_glob.pwd);
			break ;
		}
		i++;
	}
}

void	ft_update_oldpwd(void)
{
	int	i;

	i = 0;
	while (g_glob.envp[i] != NULL)
	{
		if (ft_strncmp(g_glob.envp[i], "OLDPWD=", 7) == 0)
		{
			free(g_glob.envp[i]);
			g_glob.envp[i] = ft_strjoin(ft_strdup("OLDPWD="), g_glob.pwd);
			free(g_glob.pwd);
			return ;
		}
		i++;
	}
	free(g_glob.pwd);
}

char	*ft_cd_home(char *path, char **args)
{
	path = ft_getenv("HOME=");
	if (path == NULL && args[1] == NULL)
	{
		write(2, "minishell: cd: HOME not set\n", 28);
	}
	else
		path = getenv("HOME");
	return (path);
}

int	ft_cd_cmmd(char **args)
{
	char	*path;

	path = NULL;
	g_glob.pwd = getcwd(NULL, 0);
	if (args[1] == NULL || (args[1][0] == '~' && ft_strlen(args[1]) == 1))
		path = ft_cd_home(path, args);
	else
		path = args[1];
	if (path && chdir(path) == -1)
	{
		write(2, "minishell: cd: ", 15);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": No such file or directory\n", 29);
	}
	ft_update_oldpwd();
	path = getcwd(NULL, 0);
	if (path)
	{
		ft_update_pwd();
		free(path);
	}
	else
	{
		write(2, "err getcwd\n", 11);
		return (1);
	}
	return (0);
	
}

// int main(int ac , char **av)
// {
//     ft_cd_cmmd(av);
// }
