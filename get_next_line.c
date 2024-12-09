/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:48:42 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/12/09 02:17:46 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_line(char *buffer)
{
    int i;
    char *one_line = 0;

    if (!buffer)
        return NULL;

    // printf("buffer = [%s]", buffer);
    i = 0;

    while (1) {
        if (buffer[i] == '\n' || buffer[i] == '\0')
            break;
        i++;
    }
    one_line = malloc(i + 2);
    if (!one_line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        one_line[i] = buffer[i];
        i++;
    }
    if(buffer[i] == '\n')
    {
        one_line[i++] = '\n';   
    }
    one_line[i] = '\0';
    // printf("\n==> one_line = [%s]", one_line);
    return one_line;
    
}

char *ft_read(int  fd, char *nbuffer)
{
    char *set_data;
    int byteread;

    if (nbuffer && *nbuffer == '\0')
        return NULL;
    // printf("buffer====> [%s]\n", nbuffer);
    set_data = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!set_data)
        return (NULL);
    while (1)
    {
        byteread = read(fd , set_data , BUFFER_SIZE);
        if (byteread == -1)
            return NULL;
        if (byteread == 0)
            break;
        set_data[byteread] = 0; 
        // printf("[set_data = %s]\n", set_data);
        nbuffer = ft_strjoin(nbuffer , set_data);
        if(!nbuffer)
            return (NULL);
        if (ft_strcher(nbuffer , '\n'))
        {
            break;
        }            
        
    }
    return nbuffer;
}

void update_buffer(char **buffer) 
{
    if (!buffer || !*buffer)
        return ;
    while (**buffer && **buffer != '\n')
        (*buffer)++;
    if (**buffer == '\n') 
        (*buffer)++;
}

char *get_next_line(int fd)
{

     static char *buffer = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    line = NULL;
    // printf("buffer ===> [%s]\n", buffer);
    buffer = ft_read(fd, buffer);
    if (!buffer)
        return NULL;
    line = get_line(buffer);
    if (!line)
    {
        free (buffer);
        return NULL;
    }

    // printf("before: [%s]\n", buffer);
    update_buffer(&buffer);
    // printf("after: [%s]\n", buffer);
    
    // printf("hello\n");
    // printf("final buffer = %s\n", buffer);
    return line;
}




int main()
{
    int fd = open("c.txt", O_RDONLY);
    
    char *line;
    // int i = 0;
    while (1) {
        line = get_next_line(fd);
        if (!line)
        {
            break;
        }
        printf("%s", line);
        free(line);
        // i++;
    }


    //line = get_next_line(fd);  // Should return "Hello, world!"
    //printf("Line 2: %s",get_next_line(fd));
    //free(line);

    //line = get_next_line(fd);  // Should return "This is a test."
  
    //printf("%s", get_next_line(fd));
   /// printf("%s", get_next_line(fd));
   // printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    // printf("Line 2: %s", get_next_line(fd));
    // free(line);

    // line = get_next_line(fd);  // Should return "Goodbye!"
    // printf("Line 3: %s", line);
    // free(line);

    // line = get_next_line(fd);  // Should return NULL (EOF)
    // if (line == NULL) {
    //     printf("End of file reached.\n");
    // }


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