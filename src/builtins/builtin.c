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

#include "builtin.h"

t_builtin	*builtin_new(char *name, void (*f)(void *ctx))
{
	t_builtin	*builtin;

	if (name == NULL || f == NULL)
		return (NULL);
	builtin = ft_calloc(1, sizeof(t_builtin));
	builtin->name = ft_strdup(name);
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


