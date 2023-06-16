/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:26:01 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/11 16:19:27 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd_cmmd(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	if (s == NULL)
	{
		s = ft_getenv("PWD=");
		if (s != NULL)
			printf("%s\n", s);
		else
			printf("pwd is unseted\n");
	}
	else
	{
		printf("%s\n", s);
		free(s);
	}
	return (0);
}

void    pwd(char **av)
{
    
    char buf[1024];

    if(getcwd(av[1], sizeof(buf)) != NULL)
        printf("%s\n", av[1]);
    else
    {
        printf("error");
        exit(EXIT_FAILURE);
    }  
}

// int main(int ac , char **av)
// {
//     pwd(av);
// }