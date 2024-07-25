/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:00:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/31 20:19:09by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_builtin	*builtin_new(char *name, void (*f)(void *command, void *ctx))
{
	t_builtin	*builtin;

	if (name == NULL || f == NULL)
		return (NULL);
	builtin = ft_calloc(1, sizeof(t_builtin));
	if (builtin == NULL)
		return (NULL);
	builtin->name = ft_strdup(name);
	if (builtin->name == NULL)
	{
		free(builtin);
		return (NULL);
	}
	builtin->f = f;
	return (builtin);	
}

void	builtin_free(t_builtin *builtin)
{
	if (builtin == NULL)
		return ;
	if (builtin->name != NULL)
		free(builtin->name);
	free(builtin);	
}


