/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:42 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:25:39 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h> 
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806 /*Double long*/
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strdup_limit(const char *str, char limit);
size_t	ft_strlen_gnl(const char *str);

#endif