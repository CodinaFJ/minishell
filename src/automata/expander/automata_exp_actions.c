/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 12:48:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	end_exp_evaluation(t_automata_exp *automata, void *env)
{
	if (automata->state == E_STRING_VAR)
		extract_variable(automata, env);
	if (automata->errors != NULL && automata->errors[automata->state] != NULL)
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
}

void	abort_automata(t_automata_exp *automata, void *ctx)
{
	(void)ctx;
	automata->str_len = automata->cursor;
}

void	remove_dollar(t_automata_exp *automata, void *ctx)
{
	char	*str_res;
	int		len;

	(void)ctx;
	len = ft_strlen(automata->str);
	str_res = (char *)ft_calloc(sizeof(char), len);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	ft_strncpy(str_res, automata->str, automata->cursor - 1);
	ft_strcat(str_res, automata->str + automata->cursor);
	free(automata->str);
	automata->str = str_res;
	automata->cursor--;
}
