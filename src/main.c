/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 10:13:08 by jcodina-         ###   ########.fr       */
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

int	main(void)
{
	char 			*str;
	t_minishell_ctx	ctx;
	
	minishell_init(&ctx);
	while (1)
	{
		ft_printf(SHELL_PROMT);
		str = get_next_line(0);
		ft_printf("After gnl\n");
		read_command(str, &ctx);
		if (!assert_input(str))
		{
			free(str);
			continue ;
		}
		do_minishell(tokenize(str), ctx.builtins);
		free(str);
	}
	return (0);
}
