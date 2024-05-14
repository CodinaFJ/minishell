/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:49:09 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

void	minishell_alphabet_exp_init(t_automata *automata)
{
	automata->alphabet = ft_calloc(ALPHABET_EXP_LEN + 1, sizeof(char *));
	if (automata->alphabet == NULL)
		return ;
	automata->alphabet[0] = NULL;
	ft_strs_add_line("0123456789", automata->alphabet);
	ft_strs_add_line("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_",
		automata->alphabet);
}

void	minishell_errors_exp_init(t_automata	*automata)
{
	automata->errors = ft_calloc(AUTOMATA_EXP_STATES + 1, sizeof(char *));
	if (automata->errors == NULL) // !Prone to segfault
		return ;
}

int	automata_exp_get_state(int i, int j)
{
	const int	state[][8] = {
	//	  # abc   *
		{ 1,  2,  1}, // 0 EntryState
		{ 3,  3,  3}, // 1 Single character state
		{ 2,  2,  3}, // 2 String state
		{ 3,  3,  3}  // 3 End
	};
	ft_printf("From state %d move to %d\n", i, state[i][j]);
	return (state[i][j]);
}

t_automata	*automata_init_exp(void)
{
	t_automata	*automata;
	
	//ft_printf("Automata expander initialization\n");
	automata = ft_calloc(1, sizeof(t_automata));
	if (automata == NULL)
		return (NULL);
	automata->cursor = 0;
	automata->cursor_pre = 0;
	automata->state = 0;
	minishell_alphabet_exp_init(automata);
	minishell_actions_exp_init(automata);
	minishell_errors_exp_init(automata);
	automata->get_state = automata_exp_get_state;
	return (automata);
}
