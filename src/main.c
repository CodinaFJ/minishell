/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/18 17:27:27 by jcodina-         ###   ########.fr       */
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
	char 			*str;
	char 			*str_trim;
	t_minishell_ctx	ctx;
	
	(void) argc;
	(void) argv;
	if (argc == 2 && ft_strcmp(argv[1], "test") == 0)
	{
		test_minishell(argc, argv, envp);
		exit(0);
	}
	minishell_init(&ctx, envp);
	while (1)
	{
		ft_printf(SHELL_PROMT);
		str = get_next_line(0);
        str_trim = ft_strtrim(str, "\n");
        free(str);
		read_command(str_trim, &ctx);
		if (!assert_input(str_trim))
		{
			free(str_trim);
			continue ;
		}
		do_minishell(tokenize(str_trim), ctx.builtins);
        free(str_trim);
	}
	ft_lstclear(&ctx.env, environment_variable_free);
    btree_free(&(ctx.tokens_bt), token_free);
	automata_lexer_free(ctx.automata_lexer);
	automata_exp_free(ctx.automata_expander);
	return (0);
}
