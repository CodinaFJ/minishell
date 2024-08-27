/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:50:34 by jcodina-          #+#    #+#             */
/*   Updated: 2024/08/27 18:17:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_command	*command_new(char *command, int args)
{
	t_command	*_command;

	_command = ft_calloc(1, sizeof(t_command));
	if (_command == NULL)
		return (NULL);
	_command->command = ft_strdup(command);
	_command->args = ft_calloc(args, sizeof(char *));
	if (_command->args == NULL)
	{
		command_free(_command);
		return (NULL);
	}
	return (_command);
}

void		command_print(t_command *command)
{
	if (command == NULL)
		return ;
	if (command->command != NULL)
		printf("Command: %s\n", command->command);
	else
		printf("Command: (null)\n");
	printf("Args: \n");
	ft_strs_print((const char **) command->args);
	return ;
}

void		command_free(t_command *command)
{
	if (command == NULL)
		return ;
	if (command->command != NULL)
	{
		free(command->command);
		command->command = NULL;
	}
	if (command->args != NULL)
	{
		ft_strs_free(command->args);
		command->args = NULL;
	}
	free(command);
}
