/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_action_extract_var.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:33:45 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 14:41:42 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*fill_new_str(t_automata_exp *automata, t_minishell_ctx *mini_ctx,
		char *var_key, int i)
{
	char	*new_str;
	char	*var_content;

	new_str = (char *)ft_calloc(sizeof(char), i + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, automata->str, i);
	new_str[i] = '\0';
	var_content = environment_get(mini_ctx->env, var_key);
	new_str = ft_strjoin_free(new_str, var_content, FIRST);
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strjoin_free(new_str, automata->str + automata->cursor, FIRST);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}

void	extract_variable(t_automata_exp *automata, void *ctx)
{
	char			*new_str;
	char			*var_key;
	char			*var_content;
	int				i;
	t_minishell_ctx	*mini_ctx;

	mini_ctx = (t_minishell_ctx *)ctx;
	i = strr_find_dollar(automata);
	var_key = get_var_key(automata, i);
	if (var_key == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	new_str = fill_new_str(automata, mini_ctx, var_key, i);
	var_content = environment_get(mini_ctx->env, var_key);
	automata->cursor = automata->cursor - (ft_strlen(var_key) + 1)
		+ ft_strlen(var_content);
	automata_exp_resume(automata, new_str);
	free(var_key);
	if (var_content)
		free(var_content);
}
