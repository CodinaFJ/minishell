/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:20 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:25:57 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/get_next_line.h"

/**
 * It reads from the file descriptor until it finds a newline character 
 * or until it reaches the end of
 * the file
 * 
 * @param fd file descriptor
 * @param rest the string that contains the rest of the line from the 
 * previous read
 * 
 * @return A pointer to a string.
 */
char	*read_and_rest(int fd, char *rest)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			i;

	i = 1;
	while (!ft_strchr_gnl(rest, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0 || (!i && !ft_strlen_gnl(rest)))
		{
			free(rest);
			return (NULL);
		}	
		buffer[i] = '\0';
		tmp = ft_strjoin_gnl(rest, buffer);
		free(rest);
		rest = NULL;
		rest = tmp;
		tmp = NULL;
	}
	return (rest);
}

/**
 * It reads from the file descriptor fd until it finds a newline character,
 * and returns the line read
 * 
 * @param fd file descriptor
 * 
 * @return A line of text from a file.
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest = NULL;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_and_rest(fd, rest);
	line = ft_strdup_limit(rest, '\n');
	if (rest && rest[ft_strlen_gnl(line) - 1] == '\n')
	{
		tmp = ft_strdup_gnl(rest + ft_strlen_gnl(line));
		free(rest);
		rest = NULL;
		rest = tmp;
		tmp = NULL;
	}
	else
	{
		free(rest);
		rest = NULL;
	}
	return (line);
}
