/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/31 20:42:33 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	do_minishell(char **tokens)
{
	t_builtin	**builtins_array;

	builtins_array = get_builtins_array();
	if (tokens[1] == NULL)
		try_exec_builtin(builtins_array, ft_strtrim(tokens[0], "\n"), "");
	else
		try_exec_builtin(builtins_array, tokens[0], tokens[1]);
	ft_strs_free(tokens);
}

char	**tokenize(char *str)
{
	return (ft_split(str, ' '));
}

t_bool	assert_input(char *input)
{
	if (input == NULL)
		return (false);
	return (true);
}

int	main(void)
{
	char *str;
	
	while (1)
	{
		ft_printf("\033[32;1mBashCrandicoot> \033[0;39m");
		str = get_next_line(0);
		read_command(str);
		if (!assert_input(str))
		{
			free(str);
			continue ;
		}
		do_minishell(tokenize(str));
		free(str);
	}
	return (0);
}