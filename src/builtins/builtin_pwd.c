/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:43:01 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/30 11:13:19 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_pwd(void *command, void *ctx)
{
	char	*cwd;
	char	*args;

	args = (char *)ctx;
	(void)command;
	(void)args;
	cwd = getcwd(NULL, 0);
	ft_printf("pwd called\n");
	if (cwd != NULL)
	{
		ft_printf("%s\n", cwd);
		free(cwd);
	}
	else
		perror("getcwd() error");
}
