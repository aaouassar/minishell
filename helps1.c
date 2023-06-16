/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:29:20 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/16 16:06:08 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

size_t	ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char	const *s1, char	const *s2)
{
	char	*sf;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	sf = malloc(sizeof(char) * (i + j) + 1);
	if (!sf)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sf[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sf[i++] = s2[j++];
	}
	sf[i] = '\0';
	return (sf);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*f1;
	unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	x = 0;
	while ((f1[x] || f2[x]) && x < n)
	{
		if (f1[x] != f2[x])
		{
			return (f1[x] - f2[x]);
		}
		x++;
	}
	return (0);
}