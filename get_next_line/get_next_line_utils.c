/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:21:28 by eel-garo          #+#    #+#             */
/*   Updated: 2024/12/01 19:35:58 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
char	*ft_filljoin(char *tofill, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		tofill[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		tofill[i] = s2[j];
		i++;
		j++;
	}
	tofill[i] = '\0';
	return (tofill);
}

char	*ft_strjoined(char const *str_buff, char const *buf)
{
	char	*strjn;
	size_t	len;

	if (!str_buff && !buf)
		return (NULL);
	if (!str_buff)
		return (ft_strdup(buf));
	if (!buf)
		return (ft_strdup(str_buff));
	len = ft_strlen(str_buff) + ft_strlen(buf);
	strjn = malloc((len + 1) * sizeof(char));
	if (!strjn)
		return (NULL);
	strjn = ft_filljoin(strjn, str_buff, buf);
    if (!strjn)
	{
		free(strjn);
        return (NULL);
	}
	return (strjn);
}

char	*ft_strdup(const char *buff)
{
	size_t	size;
	char	*cpy;
    int i;

	size = ft_strlen(buff);
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
    i = 0;
	while (buff[i])
    {
        cpy[i] = buff[i];
        i++;
    }
	cpy[size] = '\0';
	return (cpy);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t			len;
	size_t			i;

	len = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}