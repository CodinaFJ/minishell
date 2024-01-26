/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:20:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/26 17:37:44 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	read_command(char *str)
{
	t_automata	automata;
	int			state;

	automata_init(&automata, NULL);
	state = automata_evaluate(&automata, str);
	ft_printf("Automata ended in state: %d\n", state);
	
}

void	lexer_init(void)
{
	
}
