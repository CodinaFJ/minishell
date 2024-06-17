/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_evaluate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/12 21:57:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_lexer.h"

static int	alphabet_index(char **alphabet, char c)
{
	int	i;
	
	i = 0;
	while (alphabet[i] != NULL)
	{
		if (ft_strchr(alphabet[i], c) != NULL)
			break ;
		i++;
	}
	return (i);
}

static void	automata_evaluate_start(t_automata_lexer *automata)
{
	automata->prev_state = 0;
	automata->state = 0;
	automata->cursor = 0;
	automata->cursor_pre = 0;
}

static void automata_evaluate_char(t_automata_lexer *automata, void *automata_ctx)
{
	automata->state = automata->get_state(automata->state, alphabet_index(automata->alphabet, automata->str[automata->cursor]));
	if (automata->state_enter_action[automata->state])
		automata->state_enter_action[automata->state](automata, automata_ctx);
	if (automata->state_trans_action[automata->prev_state][automata->state])
		automata->state_trans_action[automata->prev_state][automata->state](automata, automata_ctx);
	automata->prev_state = automata->state;
	automata->cursor++;
}

static void automata_evaluate_end(t_automata_lexer *automata, void *ctx)
{
	automata->end_eval_action(automata, ctx);
	if (automata->str != NULL)
	{
		free(automata->str);
		automata->str = NULL;
	}
}

int	automata_lexer_evaluate(t_automata_lexer *automata, void *automata_ctx, char *str)
{
	automata->str = ft_strdup(str);
	if (automata->str == NULL || (automata->str)[0] == '\0')
		return (0);
	ft_printf("Evaluate string [%s]\n", str);
	automata->str_len = (int) ft_strlen(automata->str);
	automata_evaluate_start(automata);
	while (automata->cursor < automata->str_len)
		automata_evaluate_char(automata, automata_ctx);
	automata_evaluate_end(automata, automata_ctx);
	return (automata->state);
}


void    automata_lexer_free(t_automata_lexer *automata)
{
    if (automata == NULL)
        return ;
    if (automata->alphabet != NULL)
        ft_strs_free(automata->alphabet);
    if (automata->errors != NULL)
        ft_strs_free(automata->errors);
}

