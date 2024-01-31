/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:42:06 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/31 20:33:43 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../../lib/libft/include/libft.h"
# define N_BUILTINS 3

typedef struct s_builtin
{
	char	*name;
	void	(*f)(char *args);
}	t_builtin;

t_builtin	*builtin_new(char *name, void (*f)(char *args));
void		builtin_free(t_builtin *builtin);
t_builtin	**get_builtins_array();
void		try_exec_builtin(t_builtin **builtins_array, char *name, char *args);


void ft_echo(char *args);
void ft_env(char *args);
void ft_pwd(char *args);

#endif