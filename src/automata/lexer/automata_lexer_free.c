/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:08:22 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 14:09:06 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_lexer.h"

void	automata_lexer_free(t_automata_lexer *automata)
{
	unsigned int	i;

	i = -1;
	if (automata == NULL)
		return ;
	if (automata->alphabet != NULL)
		ft_strs_free(automata->alphabet);
	if (automata->errors != NULL)
	{
		while (++i <= AUTOMATA_LEXER_STATES)
		{
			if (automata->errors[i] == NULL)
				continue ;
			free(automata->errors[i]);
		}
		free(automata->errors);
	}
	free(automata);
}
