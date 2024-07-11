/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 20:50:15 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	do_minishell(char **tokens, t_builtin **builtins)
{
	if (tokens[1] == NULL)
		try_exec_builtin(builtins, ft_strtrim(tokens[0], "\n"), "");
	else
		try_exec_builtin(builtins, tokens[0], tokens[1]);
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


int	main(int argc, char **argv, char **envp)
{
	t_minishell_ctx	ctx;
	t_rc			rc;
	
	if (argc == 2 && ft_strcmp(argv[1], "test") == 0)
	{
		test_minishell(argc, argv, envp);
		exit(0);
	}
	minishell_init(&ctx, envp);
	while (1)
	{
		rc = interpreter_get_line(&ctx);
		if (rc == RC_NOK)
			continue ;
		do_minishell(tokenize(ctx.input_str), ctx.builtins);
        free(ctx.input_str);
	}
	minishell_ctx_free(&ctx);
	return (0);
}
