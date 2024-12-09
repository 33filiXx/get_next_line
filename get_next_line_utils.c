/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:20:23 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/09 02:05:32 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int ft_strcher(char *str , char sep)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == sep)
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

char *ft_strcat(char *s1 , char *s2  , char *dest)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return dest;
}


char	*ft_strdup(char *s)
{
	int i;
	char	*p;

	if (!s)
		return NULL;
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

char *ft_strjoin(char *s1 , char *s2)
{
	char *data;
	int s1_lenght;
	int s2_lenght;

	if(!s1 && !s2)
		return NULL;
	if(!s1)
		return ft_strdup(s2);
	if(!s2)
		return ft_strdup(s1);
	s1_lenght = ft_strlen(s1);
	s2_lenght = ft_strlen(s2);
	data = malloc((s1_lenght + s2_lenght + 1) * sizeof(char));
	if (!data)
		return NULL;
	return  ft_strcat(s1 , s2 , data);
}
