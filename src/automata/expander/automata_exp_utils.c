/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:26:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/24 20:32:40 by jcodina-         ###   ########.fr       */
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