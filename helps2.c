/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:38:27 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:22:03 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;

	c1 = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (c1 == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	char	*s_s;
	int		i;

	s_s = (char *)s1;
	i = 0;
	while (s1[i] != '\0')
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(copy))
		return (NULL);
	i = 0;
	while (s_s[i])
	{
		copy[i] = s_s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
