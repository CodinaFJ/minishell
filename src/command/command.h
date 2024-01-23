/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:32:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/23 20:19:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include <stdlib.h>
# include "../../lib/libft/include/libft.h"

typedef struct s_simple_command
{
	int		n_available_args;
	int		n_args;
	char	**args;
}	t_simple_command;

t_simple_command	*simple_command_new(void);
t_simple_command	*simple_command_dup(t_simple_command *simple_command);
void				simple_command_free(t_simple_command **simple_command);
void				simple_command_print(t_simple_command *simple_command);

typedef struct s_command
{
	int					num_available_simple_commands;
	int					num_simple_commands;
	t_simple_command	**simple_commands;
	char				*out_file;
	char				*in_file;
	char				*err_file;
	int					background;
	
}	t_command;

t_command	*command_new(void);
//t_command	*command_dup(t_command *command);
void		command_free(t_command *command);
void		command_print(t_command *command);


#endif