/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:45:55 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/11 22:33:45 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strcher(char *str, char sep)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == sep)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_strcat(char *s1, char *s2, char **dest)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		(*dest)[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		(*dest)[i] = s2[j];
		j++;
		i++;
	}
	(*dest)[i] = '\0';
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*data;
	int		s1_lenght;
	int		s2_lenght;

	if (!s1)
		s1 = calloc(1, 1);
	if (!s2)
		s2 = calloc(1, 1);
	s1_lenght = ft_strlen(s1);
	s2_lenght = ft_strlen(s2);
	data = calloc((s1_lenght + s2_lenght + 1), sizeof(char));
	if (!data)
		return (NULL);
	ft_strcat(s1, s2, &data);
	free(s1);
	return (data);
}
