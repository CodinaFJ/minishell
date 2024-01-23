/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:58:57 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/23 20:19:29 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

// TODO: add initialization 
t_command	*command_new(void)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (command == NULL)
		return (NULL);
	ft_bzero(command, sizeof(command));
	return (command);
}

void		command_free(t_command *command)
{
	if (command == NULL)
		return ;
	
}

void		command_print(t_command *command)
{
	
}
