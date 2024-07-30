/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:42:06 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/30 11:12:18 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../../lib/libft/include/libft.h"
# define N_BUILTINS 6

typedef struct s_builtin
{
	char	*name;
	void	(*f)(void *command ,void *ctx);
}	t_builtin;

t_builtin	*builtin_new(char *name, void (*f)(void *command,void *ctx));
void		builtin_free(t_builtin *builtin);
t_builtin	**builtins_init();
void		*builtins_free(t_builtin	**builtins_array);
t_bool		try_exec_builtin(void *ctx, char *name, char *command);


void ft_echo(void *command, void *ctx);
void builtin_env(void *command, void *ctx);
void	builtin_pwd(void *command, void *ctx);
void builtin_exit(void *command, void *ctx);
void	builtin_export(void *command, void *ctx);
void	builtin_unset(void *command, void *ctx);

#endif