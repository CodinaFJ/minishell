/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:01:44 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 13:02:52 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	command_append_arg(t_command *command, char *arg)
{
	ft_strs_add_line(arg, command->args);
}