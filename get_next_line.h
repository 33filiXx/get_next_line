/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 07:43:54 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/09 02:09:31 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8500
#endif

char *get_next_line(int fd);
char *ft_read(int  fd, char *nbuffer);

int ft_strcher(char *str , char sep);
int ft_strlen(char *str);
char *ft_strcat(char *s1 , char *s2  , char *dest);
char	*ft_strdup(char *s);
char *ft_strjoin(char *s1 , char *s2);



#endif


