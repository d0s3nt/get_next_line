/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-farg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:14:14 by mel-farg          #+#    #+#             */
/*   Updated: 2023/12/28 21:14:17 by mel-farg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *line, int needle)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != needle)
	{
		if (line[i] == 0)
			return (NULL);
		i++;
	}
	return (line + i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	char	*p;
	int		d;

	x = -1;
	d = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	p = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	if (s1)
		while (s1[++x])
			p[x] = s1[x];
	while (s2[d])
		p[x++] = s2[d++];
	p[x] = '\0';
	return (free(s1), p);
}
