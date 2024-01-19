/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:31 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:24:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/get_next_line.h"

/**
 * It takes two strings and joins them together.
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to a new string that is the result of the
 * concatenation of s1 and s2.
 */
char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		k;
	int		lens1;
	int		lens2;

	i = 0;
	k = 0;
	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	newstr = malloc(lens1 + lens2 + 1);
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[k++] = s1[i++];
	}
	i = 0;
	while (s2 && s2[i])
	{
		newstr[k++] = s2[i++];
	}
	newstr[k] = '\0';
	return (newstr);
}

/**
 * The function ft_strchr() locates the first occurrence of
 * c (converted to a char) in the string
 * pointed to by s
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character c
 * in the string s.
 */
char	*ft_strchr_gnl(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

/**
 * It copies the string s1 into a newly allocated string, and
 * returns a pointer to it
 * 
 * @param s1 The string to be copied.
 * 
 * @return A pointer to a new string which is a duplicate of the string s1.
 */
char	*ft_strdup_gnl(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/**
 * It takes a string and a character, and returns a copy of the
 * string up to the first occurrence of
 * the character
 * 
 * @param str The string to be copied.
 * @param limit the character that will be used to limit the string.
 * 
 * @return A pointer to a new string.
 */
char	*ft_strdup_limit(const char *str, char limit)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	while (str[len] && str[len] != (limit))
		len++;
	if (str[len] == (limit))
		len++;
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/**
 * It returns the length of a string
 * 
 * @param str The string to be measured.
 * 
 * @return The length of the string.
 */
size_t	ft_strlen_gnl(const char *str)
{
	size_t	n;

	n = 0;
	while (str && str[n])
		n++;
	return (n);
}