/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:46:52 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/11 22:30:18 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	char	*p;
	size_t	i;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		total_size = 1;
	p = (char *)malloc(total_size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*one_line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	one_line = malloc(i + 2);
	if (!one_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		one_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		one_line[i++] = '\n';
	one_line[i] = '\0';
	return (one_line);
}

char	*ft_read(int fd, char *nbuffer)
{
	char	*set_data;
	int		byteread;

	if (nbuffer && *nbuffer == '\0')
		return (NULL);
	set_data = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!set_data)
		return (NULL);
	byteread = 1;
	while (!ft_strcher(nbuffer, '\n'))
	{
		byteread = read(fd, set_data, BUFFER_SIZE);
		if (byteread == 0)
			break ;
		if (byteread == -1)
		{
			free(set_data);
			return (NULL);
		}
		set_data[byteread] = 0;
		nbuffer = ft_strjoin(nbuffer, set_data);
	}
	free(set_data);
	return (nbuffer);
}

void	update_buffer(char **buffer)
{
	char	*temp;
	char	*new_buffer;

	temp = *buffer;
	while (*temp && *temp != '\n')
		temp++;
	if (*temp == '\n')
		temp++;
	new_buffer = ft_strdup(temp);
	free(*buffer);
	*buffer = new_buffer;
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	update_buffer(&buffer);
	if (*buffer == '\0' || !buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
