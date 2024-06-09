/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/05/26 20:17:14 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "data_structures_C/src/btree/btree.h"
#include "lexer/token.h"
#include "libft/include/libft.h"

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

int	main(void)
{
	char 			*str;
	char 			*str_trim;
	t_minishell_ctx	ctx;
	
	minishell_init(&ctx);
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
    btree_free(&(ctx.tokens_bt), token_free);
	automata_free(ctx.automata_lexer);
	automata_free(ctx.automata_expander);
	return (0);
}
