/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/01 21:50:34 by jcodina-         ###   ########.fr       */
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

void	start_ctx(t_minishell_ctx *ctx)
{
	(void) ctx;
}

int	main(void)
{
	char 			*str;
	t_minishell_ctx	ctx;
	
	minishell_init(&ctx);
	while (1)
	{
		ft_printf(SHELL_PROMT);
		str = get_next_line(0);
		read_command(str, &ctx);
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