/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 11:13:38 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "minishell_ctx.h"

void	do_minishell(char **tokens, t_minishell_ctx *mini_ctx)
{
	if (tokens[1] == NULL)
		try_exec_builtin(mini_ctx, ft_strtrim(tokens[0], "\n"), NULL);
	else
		try_exec_builtin(mini_ctx, tokens[0], tokens[1]);
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
	char			**temp_tokens;
	
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
		temp_tokens = tokenize(ctx.input_str);
		do_minishell(temp_tokens, &ctx);
        free(ctx.input_str);
	}
	minishell_ctx_free(&ctx);
	return (0);
}
