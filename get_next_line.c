/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:48:42 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/05 22:21:20 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int size_of_line(int fd)
// {
//     int i;
//     size_t buffersize;
    
//     i = 0;
//     while()
//     {
        
//     }
// }

char *get_next_line(int fd)
{
    char *buffer;
    //static size_t byteread;
    int i = 0;

    buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        return (NULL);
    //ft_memset(buffer,'\0', BUFFER_SIZE );
    while(read(fd , &buffer[i] , BUFFER_SIZE) > 0)
    {
        if (buffer[i] == '\n')
        {
            buffer[i + 1] = '\0';
            return buffer;
        }
        i++;
    }
    return buffer;
}

int main()
{
    int fd = open("c.txt", O_RDONLY);
    if (fd == -1) {
        perror("Couldn't open the file");
        return 1;
    }

    char *line;


    line = get_next_line(fd);  // Should return "Hello, world!"
    printf("Line 1: %s", line);
    free(line);

    line = get_next_line(fd);  // Should return "This is a test."
    printf("Line 2: %s", line);
    free(line);

    line = get_next_line(fd);  // Should return "Goodbye!"
    printf("Line 3: %s", line);
    free(line);

    line = get_next_line(fd);  // Should return NULL (EOF)
    if (line == NULL) {
        printf("End of file reached.\n");
    }


    // //printf("hhhhhhhh");
    // int fd = open("c.txt" , O_RDWR | O_APPEND);
    // if(fd == -1)
    // {
    //     printf("couldnt open the file\n");
    //     return (1);
    // }
     
    // printf("%s" , get_next_line(fd));
    
    // close(fd);
    // return 0;
}