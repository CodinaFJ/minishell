/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:26:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 19:24:50 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

void	automata_exp_resume(t_automata_exp *automata, char *str_res)
{
	free(automata->str);
	automata->str = str_res;
	automata->str_len = ft_strlen(automata->str);
	automata->state = E_PRE_VAR;
	if (automata->str[automata->cursor] == '$')
		automata->state = E_DOLLAR;
}

void	automata_exp_free(t_automata_exp *automata)
{
	if (automata == NULL)
		return ;
	if (automata->alphabet != NULL)
		ft_strs_free(automata->alphabet);
	if (automata->errors != NULL)
		ft_strs_free(automata->errors);
	free(automata);
}
