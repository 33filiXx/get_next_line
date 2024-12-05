/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 07:43:54 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/05 22:19:49 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

char *get_next_line(int fd);




#endif


