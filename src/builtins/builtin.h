/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:42:06 by jcodina-          #+#    #+#             */
/*   Updated: 2024/05/26 20:24:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../../lib/libft/include/libft.h"
# define N_BUILTINS 5

typedef struct s_builtin
{
	char	*name;
	void	(*f)(void *ctx);
}	t_builtin;

t_builtin	*builtin_new(char *name, void (*f)(void *ctx));
void		builtin_free(t_builtin *builtin);
t_builtin	**builtins_init();
t_bool		try_exec_builtin(t_builtin **builtins_array, char *name, char *args);


void ft_echo(void *ctx);
void ft_env(void *ctx);
void ft_pwd(void *ctx);
void ft_exit(void *ctx);

#endif