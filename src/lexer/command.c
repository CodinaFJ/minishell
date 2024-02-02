/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:50:34 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 15:18:54 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_command	*command_new(char *command, char **args)
{
	t_command	*_command;

	_command = ft_calloc(1, sizeof(t_command));
	if (_command == NULL)
		return (NULL);
	_command->command = ft_strtrim(command, "\"");
	_command->args = args;
	return (_command);
}

void		command_print(t_command *command)
{
	if (command == NULL)
		return ;
	ft_printf("Command: %s\nArgs: \n", command->command);
	ft_strs_print((const char **) command->args);
	return ;
}

void		command_free(t_command *command)
{
	if (command == NULL)
		return ;
	if (command->command != NULL)
		free(command->command);
	if (command->args != NULL)
		ft_strs_free(command->args);
	free(command);
}
