/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:43:01 by marubio-          #+#    #+#             */
/*   Updated: 2024/08/27 18:17:32 by jcodina-         ###   ########.fr       */
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
	printf("pwd called\n");
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	else
		perror("getcwd() error");
}
