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

#include "../../../include/minishell.h"

static t_rc	minishell_alphabet_exp_init(t_automata_exp *automata)
{
	automata->alphabet = ft_calloc(ALPHABET_EXP_LEN + 1, sizeof(char *));
	if (automata->alphabet == NULL)
		return (RC_NOK);
	ft_strs_add_line("0123456789", automata->alphabet);
	ft_strs_add_line("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_",
		automata->alphabet);
	ft_strs_add_line("$", automata->alphabet);
	ft_strs_add_line("?!", automata->alphabet);
	ft_strs_add_line("\'", automata->alphabet);
	ft_strs_add_line("\"", automata->alphabet);
	return (RC_OK);
}

int	automata_exp_get_state(int i, int j)
{
	const int	state[][8] = {
	{0, 0, 1, 0, 4, 5, 0},
	{2, 3, 2, 2, 4, 5, 0},
	{0, 0, 1, 0, 4, 5, 0},
	{3, 3, 1, 0, 4, 5, 0},
	{4, 4, 4, 4, 0, 4, 4},
	{5, 5, 1, 5, 5, 5, 5},
	{6, 6, 6, 6, 6, 6, 6}
	};

	return (state[i][j]);
}

t_automata_exp	*automata_exp_init(void)
{
	t_automata_exp	*automata;
	t_rc			rc;

	rc = RC_OK;
	automata = ft_calloc(1, sizeof(t_automata_exp));
	if (automata == NULL)
		return (NULL);
	if (minishell_alphabet_exp_init(automata) == RC_NOK)
		rc = RC_NOK;
	minishell_actions_exp_init(automata);
	automata->get_state = automata_exp_get_state;
	if (rc == RC_NOK)
	{
		automata_exp_free(automata);
		return (NULL);
	}
	return (automata);
}
