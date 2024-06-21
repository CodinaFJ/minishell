/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_evaluate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/21 10:58:46y jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

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

static void	automata_evaluate_start(t_automata_exp *automata)
{
	automata->prev_state = 0;
	automata->state = 0;
	automata->cursor = 0;
	automata->cursor_pre = 0;
}

static void automata_evaluate_char(t_automata_exp *automata, void *env)
{
	automata->state = automata->get_state(automata->state, alphabet_index(automata->alphabet, automata->str[automata->cursor]));
	if (automata->state_enter_action[automata->state])
		automata->state_enter_action[automata->state](automata, env);
	if (automata->state_trans_action[automata->prev_state][automata->state])
		automata->state_trans_action[automata->prev_state][automata->state](automata, env);
	automata->prev_state = automata->state;
	automata->cursor++;
}

static void	automata_evaluate_end(t_automata_exp *automata, void *env)
{
    automata->end_eval_action(automata, env);
}

char    *automata_exp_evaluate(t_automata_exp *automata, void *env, char *str)
{
	automata->str = ft_strdup(str);
	if (automata->str == NULL)
		return (NULL);
	else if ((automata->str)[0] == '\0')
		return (automata->str);
	// ft_printf("Evaluate string [%s]\n", automata->str);
	automata->str_len = (int) ft_strlen(automata->str);
	automata_evaluate_start(automata);
	while (automata->cursor < automata->str_len)
		automata_evaluate_char(automata, env);
	automata_evaluate_end(automata, env);
	return (automata->str);
}

void    automata_exp_free(t_automata_exp *automata)
{
    if (automata == NULL)
        return ;
    if (automata->alphabet != NULL)
        ft_strs_free(automata->alphabet);
    if (automata->errors != NULL)
	{
		ft_strs_free(automata->errors);
	}
	free(automata);
}

