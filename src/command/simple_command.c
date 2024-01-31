/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:40:06 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/23 20:19:25 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

// TODO: add initialization
t_simple_command	*simple_command_new(void)
{
	t_simple_command	*simple_command;

	simple_command = malloc(sizeof(t_simple_command));
	if (simple_command == NULL)
		return (NULL);
	ft_bzero(simple_command, sizeof(t_simple_command));
	return (simple_command);
}

t_simple_command	*simple_command_dup(t_simple_command *simple_command)
{
	t_simple_command	*simple_command_dup;

	simple_command_dup = ft_calloc(1, sizeof(t_simple_command));
	if (simple_command_dup == NULL)
		return (NULL);
	simple_command_dup->args = ft_strsdup(simple_command->args);
	simple_command_dup->n_args = simple_command->n_args;
	simple_command_dup->n_available_args = simple_command->n_available_args;
	return (simple_command_dup);
}

void	simple_command_free(t_simple_command **simple_command)
{
	if ((*simple_command) == NULL)
		return ;
	if ((*simple_command)->args != NULL)
		ft_strs_free((*simple_command)->args);
	free(*simple_command);
	*simple_command = NULL;
}

void	simple_command_print(t_simple_command *simple_command)
{
	ft_printf("SIMPLE COMMAND\n---------------\n");
	if (simple_command == NULL)
		ft_printf("(null)\n");
	else
	{
		ft_printf("Number of available arguments: %d\n", simple_command->args);
		ft_printf("Number of arguments: %d\n", simple_command->n_args);
		ft_printf("Arguments:\n");
		ft_strs_print(simple_command->args);
	}
	ft_printf("---------------\n");
}
