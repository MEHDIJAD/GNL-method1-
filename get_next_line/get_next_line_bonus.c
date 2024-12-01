/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:11:58 by eel-garo          #+#    #+#             */
/*   Updated: 2024/12/01 20:38:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_found_newline(char *str_buf)
{
    int i;

    if (!str_buf)
        return (0);
    i = 0;
    while (str_buf[i])
    {
        if (str_buf[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
int ft_len_to_newline(char *str_buf)
{
    int len;

    if (!str_buf)
        return (0);
    len = 0;
    while (str_buf[len] && str_buf[len] != '\n')
        len++;
    if (str_buf[len] == '\n')
        len++;
    return (len);
}
char *ft_get_line(char **str_buf, int fd)
{
    int len;
    char *line;

    if (!str_buf[fd] || !*str_buf[fd])
        return(NULL);
    len = ft_len_to_newline(str_buf[fd]);
    line = malloc(len + 1); 
    if (!line)
        return(NULL);
    ft_strlcpy(line, str_buf[fd], len + 1);
    return (line);
}

char *ft_read_join(char **str_buff, int fd)
{
    char *buf;
    char *temp;
    int bytes_read;
    
    if (!str_buff[fd] && !(str_buff[fd] = ft_strdup("")))
        return (NULL);
    if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (free(str_buff[fd]), str_buff[fd] = NULL, NULL);
    while (!ft_found_newline(str_buff[fd]))
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buf);
            if (bytes_read == 0)
                return (str_buff[fd]);
            return (free(str_buff[fd]), str_buff[fd] = NULL, NULL);     
        }
        buf[bytes_read] = '\0';
        temp = ft_strjoined(str_buff[fd], buf);
        free(str_buff[fd]);
        if (!(str_buff[fd] = temp))
            return (free(buf), NULL); 
    }
    return (free(buf), str_buff[fd]);
}

char *get_next_line(int fd)
{
    static char *str_buf[OPEN_MAX];
    char *line;
    char *temp;

    if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    if (!ft_read_join(str_buf, fd) || !str_buf[fd])
        return (NULL);
    line = ft_get_line(str_buf, fd);
    if (!line)
        return (free(str_buf[fd]), str_buf[fd] = NULL, NULL);
    temp = ft_strdup(str_buf[fd] + ft_len_to_newline(str_buf[fd]));
    if (!temp)
        return (free(str_buf[fd]), str_buf[fd] = NULL, free(line), NULL);
    free(str_buf[fd]);
    str_buf[fd] = temp;
    return (line);
}



